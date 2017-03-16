// c.cpp : Defines the entry point for the console application.
//
//  This code may use Boost libraries 1_49_0
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
//#include <boost/dynamic_bitset.hpp>



int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	scanf("%d\n",&T);

	for (int i=0; i<T; i++)
	{

		fprintf(stderr,"Solving case#%d\n",i+1);
		// Inputs here
		double D;
		int N,A;
		scanf("%lg %d %d\n",&D, &N, &A);
		

		double t[2048], x[2048];

		for (int n=0; n<N; n++)
		{
			scanf("%lg %lg\n",&t[n], &x[n]);
		}

		double acc[512];
		for (int a=0; a<A; a++)
		{
			scanf("%lg",&acc[a]);
		}

		fprintf(stderr,"Case #%d:\n",i+1);
		printf("Case #%d:\n",i+1);

		// How long to go D meters ?
		for (int a=0; a<A; a++)
		{
			double bestT = sqrt(2.0*D/acc[a]);
			double myT=0;
			double carT=0;

			// At each spot, see when we each get there
			double delay=0;
			for (int n=0; n<N-1; n++)
			{
				double me=delay+sqrt(2.0*x[n]/acc[a]);
				if (me<t[n])
					delay+=(t[n]-me);
				else
				{
				}

				if ((x[n+1]>=D) || n==N-1)
				{
					// this block of time.
					double v=(x[n+1]-x[n])/(t[n+1]-t[n]);
					carT = t[n]+(D-x[n])/(v);
				}
			}

			bestT+=delay;

			//// Other car gets there when ?
			//for (int n=0; n<N-1; n++)
			//{
			//	if ((x[n+1]>=D) || n==N-1)
			//	{
			//		// this block of time.
			//		double v=(x[n+1]-x[n])/(t[n+1]-t[n]);
			//		carT = t[n]+(D-x[n])/(v);
			//		break;
			//	}
			//}
			if (bestT>carT)
				printf("%.8f\n",bestT);
			else
				printf("%.8f\n",carT);
		}

		//printf("Case #%d: %f %f\n",i+1,best, top);
		int best=0;
	}

	return 0;
}
