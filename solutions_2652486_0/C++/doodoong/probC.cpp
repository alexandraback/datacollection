// probC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#define		out stdout

int R,N,M,K ; 
int table[4][4][4][4] ; 
int products[8];

void process() {
	for(int a=2;a<=M;a++) {
		for(int b=2;b<=M;b++) {
			if (a>b) continue ; 
			for(int c=2;c<=M;c++) {
				if (b>c) continue ; 
				table[a-2][b-2][c-2][0] = a*b ; 
				table[a-2][b-2][c-2][1] = a*c ; 
				table[a-2][b-2][c-2][2] = b*c ; 
				table[a-2][b-2][c-2][3] = a*b*c ; 
			}
		}
	}
}

int solve() {
	for(int a=2;a<=M;a++) {
		for(int b=2;b<=M;b++) {
			if (a>b) continue ; 
			for(int c=2;c<=M;c++) {
				if (b>c) continue ;

				int i ; 

				for( i=0;i<K;i++) {
					bool found =false;
					if (products[i]==1 || products[i]==a || products[i]==b || products[i]==c) { continue; }

					for(int j=0;j<4;j++) {
						if (products[i] == table[a-2][b-2][c-2][j]) {
							found =true ; break; 
						}
					}
					if (!found) break; 
				}

				if (i==K) return (a*100+b*10+c);
			}
		}
	}
	return (222);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int numCases;

	FILE *in = fopen("C-small-1-attempt0.in","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in,"%d",&numCases); 
	fprintf(out,"Case #1:\n");
	for(int cnt=0;cnt<numCases;cnt++) {
		fscanf(in,"%d %d %d %d",&R,&N,&M,&K);
		process();
		for(int i=0;i<R;i++) {
			for(int j=0;j<K;j++) {
				fscanf(in,"%d",&products[j]);
			}
			fprintf(out,"%d\n",solve());
		}
	}

	//char temp = getchar();

	return 0;
}

