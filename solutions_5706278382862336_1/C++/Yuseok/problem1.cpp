// Codejam Pratice rotate.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <conio.h>

using namespace std;

int t;
char data1[100000];
int a,b;
int n,k;
int final, mins;

FILE *op,*out;

int recur(long double data1, int depth)
{
	int i,j;
	long double a,b;
	
	if(depth>=41 || final == 1) return 0;
	printf("%f\n",data1);
	a = (data1 * 2) - 1;

	if(a>=0) {

		if(a==0) {
			if(mins > depth) {
				mins = depth;
				final = 1;
			}

			return 1;
		}

		if(recur(a,depth+1) == 1) {
			if(mins > depth) {
				mins = depth;
				final = 1;
			}

			return 1;
		}

		return 0;
	}

	else {
		b = data1 * 2;
		return recur(b,depth+1);
	}

	return 0;
}

int main()
{
	int i,j,k;
	int ok;
	long double a,b;

	ofstream outfile("output.txt");
	op = fopen("input.txt","r");

	fscanf(op,"%d",&t);

	for(i=0;i<t;i++) {

		fscanf(op,"%s",&data1);
		printf("%s\n",data1);
		a = 0; b =0;
		ok = 0;
		
		for(j=0;j<strlen(data1);j++) {
			if(data1[j] == '/') { ok = 1; continue; }
		
			if(ok==0) {
				a*=10;
				a+=(data1[j]-'0');
			}

			if(ok==1) {
				b*=10;
				b+=(data1[j]-'0');
			}
		}
		
		final = 0; mins =50;

		recur(long double(a/b), 1);

		if(final == 1) {
			outfile << "Case #" <<  i+1 << ": " << mins << endl;
		}

		else {
			outfile << "Case #" <<  i+1 << ": impossible" <<endl;
		}
	}

	return 0;
}
