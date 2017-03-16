// probA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#define out stdout

__int64 R,T;

int solv() {
	__int64 sum = 0, idx=R ; 
	while (T>=0) {
		T-=(idx*2+1) ; 
		idx+=2 ; 
		sum +=1 ; 
	}

	return sum-1; 
	
}


int _tmain(int argc, _TCHAR* argv[])
{
	int numCases;

	FILE *in = fopen("A-small-attempt0.in","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in,"%d",&numCases);

	for(int cnt=1;cnt<=numCases;cnt++){
		fscanf(in,"%I64d %I64d",&R,&T);
		fprintf(out,"Case #%d: %d\n",cnt,solv());
	}

	return 0;
}

