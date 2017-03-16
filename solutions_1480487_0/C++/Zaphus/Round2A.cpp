// Round2A.cpp : Defines the entry point for the console application.
//
//
// zaph
// at
// torps
// dot
// com



// Including SDKDDKVer.h defines the highest available Windows platform.

// If you wish to build your application for a previous Windows platform, include WinSDKVer.h and
// set the _WIN32_WINNT macro to the platform you wish to support before including SDKDDKVer.h.

#include <SDKDDKVer.h>

#include <stdio.h>
#include <tchar.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	scanf("%d\n",&T);

	for (int i=0; i<T; i++)
	{

		fprintf(stderr,"Solving case#%d\n",i+1);
		// Inputs here
		int N;
		scanf("%d",&N);
		int S[512];
		int pointSum=0;
		for (int n=0; n<N; n++)
		{
			scanf("%d",&S[n]);
			pointSum+=S[n];
		}

		float elim[512];

		for (int n=0; n<N; n++)
		{
			int under=0;
			int newPS=0;
			for (int m=0; m<N; m++)
			{
				if (S[m]<=(2.0*(float)pointSum/(float)N))
				{
					newPS+=S[m];
					under++;
				}
			}
			float needs = ((float)(newPS+pointSum)/(float)under-S[n]);
			elim[n]=100.0*needs/(float)pointSum;
			if (elim[n]<0)
			{
				elim[n]=0;
				//fprintf(stderr,"ERROR\n");
			}
		}
		//printf("Case #%d: %f %f\n",i+1,best, top);
		int best=0;
		fprintf(stderr,"Case #%d: ",i+1);
		for (int n=0; n<N; n++)
			fprintf(stderr," %f", elim[n]);
		fprintf(stderr,"\n");
		for (int n=0; n<N; n++)
			fprintf(stderr," %f", S[n]+elim[n]*(float)pointSum/100.0);
		fprintf(stderr,"\n");
		printf("Case #%d: ",i+1);
		for (int n=0; n<N; n++)
			printf(" %f", elim[n]);
		printf("\n");
	}

	return 0;
}
