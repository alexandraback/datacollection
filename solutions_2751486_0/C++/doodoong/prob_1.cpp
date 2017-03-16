// prob_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//#define out	stdout

char table[1000001] ; 
int len ;

int _tmain(int argc, _TCHAR* argv[])
{
	int numCases;

	FILE *in = fopen("A-small-attempt0.in","r");
	FILE *out = fopen("output.txt","w");

	fscanf(in,"%d\n",&numCases);

	for(int cnt=1;cnt<=numCases;cnt++){
		int n ; 
		fprintf(out,"Case #%d: ",cnt);
		char temp ;
		int sublength =0 , Nvalue=0, len=0; 
		while ((temp = fgetc(in)) != ' ') {
			table[len++] = temp ; 
		}

		fscanf(in,"%d\n",&n);
		int lastvalue =0;

		for(int idx=0;idx<len;idx++) {
			char temp = table[idx] ; 
			if (!(temp == 'a' || temp=='e' || temp=='i' || temp=='o' || temp=='u')) {
				sublength++;
				if (sublength>=n) {
					Nvalue += idx-n+2 ; 
					lastvalue = idx-n+2;
				} else {
					Nvalue +=lastvalue;
				}
			} else {
				sublength=0;
				Nvalue +=lastvalue;
			}
		}

		fprintf(out,"%d \n",Nvalue);
	}

	return 0;
}
