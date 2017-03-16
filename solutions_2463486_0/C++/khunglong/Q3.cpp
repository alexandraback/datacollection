#include <stdio.h>
#include <iostream>
#include <conio.h>
using namespace std;

#define file_in "C-small-attempt0.in"
//#define file_in "Q3.in"
#define file_out "Q3.out"

int test;          /* # of test case */
FILE *fi;
FILE *fo;

int a, b;
int p[10];

int main() {
    int i, j, k;

    fi = fopen(file_in, "r");
    fo = fopen(file_out, "w");

    fscanf(fi, "%d", &test);

	p[0] = 1;   //1^2
	p[1] = 4;   //2^2
	p[2] = 9;   //3^2
	p[3] = 121;  //11^2
	p[4] = 484;  //22^2
	
	/*
	for (i=1; i<33; i++)
	    printf("%d %d\n", i, i*i);
	getch();
	*/
	
    for (i=1; i<=test; i++)
    {
		fscanf(fi, "%d %d", &a, &b);
		j = 0;	while ((p[j]<a) && (j<=4)) j++;
		k = 4;	while ((p[k]>b) && (k>=0)) k--;

		fprintf(fo, "Case #%d: %d\n", i, k-j+1);
	}

    fclose(fi);
    fclose(fo);
}

