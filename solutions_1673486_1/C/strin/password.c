#include "stdio.h"

int t;
double p[200000];
double sp[200000];

int main() {
	FILE* fpin = fopen( "password.in", "r");
	FILE* fpout = fopen( "password.out", "w");
	fscanf( fpin, "%d", &t);
	int A, B;
	double cases[4];		
    for( int i = 1; i <= t; i++) {
        fscanf( fpin, "%d %d", &A, &B);
        for( int j = 1; j <= A; j++) {
            fscanf( fpin, "%lf", &p[j]);
        }
        // Calc cases #1.
        sp[0] = 1.0;
        for( int j = 1; j <= A; j++) {
            sp[j] = sp[j-1]*p[j];
        }
        double piP = sp[A];
        cases[1] = piP*(B-A+1)+(1-piP)*(B-A+1+B+1);
        
        // Calc cases #3.
        cases[2] = B+2;
        
        // Calc cases #2.
        double min = 9876543210;
        int minj;
        for( int j = 0; j <= A-1; j++) {
            double esp = A-j+sp[j]*(B-j+1)+(1-sp[j])*(B-j+1+B+1);
            //printf( "esp: %lf\n", esp);
            if( esp < min) {
                min = esp;
                minj = j;
            }
        }
        cases[3] = min;
        
        double res = 0;
        if( cases[1] <= cases[2] && cases[1] <= cases[3]) {
            res = cases[1]; //printf( "1\n");
        }else if( cases[2] <= cases[1] && cases[2] <= cases[3]) {
            res = cases[2]; //printf( "2\n");
        }else{
            res = cases[3]; //printf( "3\n");
        }
        fprintf( fpout, "Case #%d: %lf\n", t, res);
    }	
    fclose( fpout);
	fclose( fpin);
}
