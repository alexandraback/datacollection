// Safety.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

FILE *fin,*fout;
int T,N;
int data[300];
int _tmain(int argc, _TCHAR* argv[])
{
	
	fin = fopen("Safety.txt","r");
	fout= fopen("Safety.out","w");

	fscanf(fin, "%d\n", &T);
	for (int t = 1 ; t<=T;t++) {

		fscanf(fin, "%d", &N);
		memset(data,0,sizeof(data));
		int X =0;
		for (int i=1;i<=N;i++) {
			fscanf(fin, "%d",&data[i]);
			X += data[i];
		}
		double f,Lowest;
		f = X/(double)100;
		
		Lowest = (X + 100.0*f)/(double)N;

		fprintf(fout,"Case #%d: ",t);
		double answer[300];
		for (int i=1;i<=N;i++) {
			double ans;
			ans = (Lowest-(double)data[i])/f;

			//if (Lowest >= (double)data[i]+f*answer)
			//if (answer>=0.0)
				//fprintf(fout,"%.6lf",answer);
			//else
			//	fprintf(fout,"0.0");

			//if (i!=N)
			//	fprintf(fout," ");

			answer[i] = ans;
		}

		double negative=0;
		int count=0;
		for (int i=1;i<=N;i++) {
			if (answer[i]<0) {
				negative = negative + answer[i]*(-1.0);
			count++;
			}
		}
		double share;
		share = negative / (double)(N-count);

		for (int i=1;i<=N;i++) {
			if (answer[i]<0)
				answer[i] = 0.0;
			else 
				answer[i] = answer[i] - share;

			fprintf(fout,"%.6lf ",answer[i]);
		}

		fprintf(fout,"\n");



	}

	fclose(fin);
	fclose(fout);
	return 0;
}

