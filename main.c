/*
 * This program is designed to calculate the Trigonometric Identities of any given degree.
 * First it asks the user for the size of the angle; then converts it into radians, since it is the necessary unit for
 * the functions to work on this Programming Language. Then it prints the sine, cosine, tangent, secant, cosecant and
 * cotangent of the given angle.
 *
 * Author: Soraya Lizeth Maqueda Gutiérrez
 * Date: 03.10.2018
 * Contact: soraya_maqueda@hotmail.com
 */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double anyAngle(double beta) {
    int coterminal = (int) floor(beta / 360.0);
    double realAngle= beta - (360.0 * coterminal);

    if (realAngle >= 0){
        return realAngle;
    }else {
        return realAngle + 360;
    }
}

int main() {
    double angle;
    double radians;
    double cotan;
    double sec;
    double cosec;
    char ND[]="Not Defined";
    char verifier[100];
    char *notInteger;

    //Here I ask the user to introduce the size of the angle in degree measurements.
    //We create a string called Verifier to determine whether the user introduced a valid data type or not.
    printf("State the measurement of the angle in degrees:\n");

    fgets(verifier, sizeof(verifier), stdin);

    //Here we use the function strtod to convert the string into a valid data type, and save the not useful data that
    //the user may have introduced into the notInteger variable.
    angle = strtod (verifier, &notInteger);

    //If the data introduced is valid for the program, then the calculations begin.
    //Also it validates that the program doesn't runs a 0 if there aren't any numbers at the user's input.
    if (strlen(verifier) != strlen(notInteger)) {

        angle = anyAngle(double realAngle);
        //Here I convert the degrees into radians.
        radians = angle * (M_PI / 180.0);

        //Calculates the sine
        printf("sin(%lf) = %lf\n", angle, sin(radians));

        //Calculates the cosine
        printf("cos(%lf) = %lf\n", angle, cos(radians));

        //When the cosine == 0 then the tangent, secant and cotangent will be undefined.
        if (angle != 90.0 && angle != 270.0) {

            //Calculates the tangent
            printf("tan(%lf) = %lf\n", angle, tan(radians));

            //Calculates the secant
            sec = (1 / cos(radians));
            printf("sec(%lf) = %lf\n", angle, sec);

        } else {

            printf("tan(%lf)= %s\n", angle, ND);
            printf("sec(%lf)= %s\n", angle, ND);

        }

        //When the sine == 0 then the cosecant will be undefined.
        if (angle != 0.0 || angle != 180.0 || angle != 360.0){

            cosec = (1 / sin(radians));
            printf("cosec(%lf) = %lf\n", angle, cosec);

        } else {

            printf("cosec(%lf)= %s\n", radians, ND);

        }

        if (angle != 0.0 && angle != 180.0 && tan != 0){

            //Calculates the cotangent
            cotan = (cos(radians) / sin(radians));
            printf("cotan(%lf) = %lf\n", angle, cotan);

        } else {

            printf("cotan(%lf)= %s\n", angle, ND);

        }

    } else {
        //If the user did not introduced valid data, then the program lets the user know so.
        printf("You did not introduced valid data.");
    }

    return 0;
}