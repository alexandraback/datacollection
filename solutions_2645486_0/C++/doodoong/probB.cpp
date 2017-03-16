// probB.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#define out stdout

int E,R,N ; 
int value[1000];
int table[1000][10]; 

int solve() {
	int i;
	i=0;
	for(int j=0;j<=E;j++) {
		table[i][j] = value[i]*(E-j) ;
	}

	for(int i=1;i<N;i++) {
		for(int j=0;j<=E;j++) {
			table[i][j] = 0; 
			for(int k=0;k<=E;k++) {
				int energy = k+R ; 
				if (energy>E) { energy = E ; }
				if (energy<j) continue ; 
				int now = table[i-1][k] + (energy-j)*value[i] ;
				if (now > table[i][j] ) table[i][j] = now ; 
			}
		}
	}

	int max = 0;
	for(int j=0;j<=E;j++) {
		if (max <table[N-1][j] ) { max = table[N-1][j]; }
	}
	return max ;
}
	



int _tmain(int argc, _TCHAR* argv[])
{
	int numCases;

	FILE *in = fopen("B-small-attempt0.in","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in,"%d",&numCases); 
	for(int cnt=0;cnt<numCases;cnt++) {
		fscanf(in,"%d %d %d",&E,&R,&N);
		for(int i=0;i<N;i++) {
			fscanf(in,"%d",&value[i]);
		}
		fprintf(out,"Case #%d: %d\n",cnt+1,solve());
	}

	return 0;
}

