// b.cpp : Defines the entry point for the console application.
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

__int64 a[128],A[128],b[128],B[128];
__int64 a2[128],b2[128];
int N, M;

__int64 solve(int n, int m)
{
		__int64 total=0;

		if (n<N && m<M)
		{


			bool match=false;
			if (A[n]==B[m])
			{
				match=true;
				if (a2[n]>b2[m])
				{
					total+=b2[m];
					a2[n]-=b2[m];
					m++;
				}
				else if (a2[n]<b2[m])
				{
					total+=a2[n];
					b2[m]-=a2[n];
					n++;
				}
				else
				{
					total+=a2[n];
					n++;
					m++;
				}
			}

			__int64 a2n=a2[n];
			__int64 b2m=b2[m];

			if (match)
			{
				total+=solve(n,m);
				//memcpy(a2,a3,sizeof(__int64)*128);
				//memcpy(b2,b3,sizeof(__int64)*128);

				return total;
			}
			else
			{
				__int64 a3[128],b3[128];
				memcpy(a3,a2,sizeof(__int64)*128);
				memcpy(b3,b2,sizeof(__int64)*128);

				__int64 total1=solve(n,m+1);
				memcpy(a2,a3,sizeof(__int64)*128);
				memcpy(b2,b3,sizeof(__int64)*128);

				__int64 total2=solve(n+1,m);
				//memcpy(a2,a3,sizeof(__int64)*128);
				//memcpy(b2,b3,sizeof(__int64)*128);

				return total+max(total1,total2);
			}
		}
		//if (total>best)
		//{
		//	fprintf(stderr,"New best: %I64d\n",total);
		//	best=total;
		//}
	
		return total;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	scanf("%d\n",&T);

	for (int i=0; i<T; i++)
	{

		fprintf(stderr,"Solving case#%d\n",i+1);
		// Inputs here

		scanf("%d %d\n",&N, &M);



		for (int n=0; n<N; n++)
		{
			scanf("%I64d %I64d",&a[n], &A[n]);
		}

		for (int m=0; m<M; m++)
		{
			scanf("%I64d %I64d",&b[m], &B[m]);
		}

		__int64 best=0;


		memcpy(a2,a,sizeof(__int64)*128);
		memcpy(b2,b,sizeof(__int64)*128);
		if (0)
			best=solve(0,0);

		if (1)
		for (int l=0; l<100000; l++)
		{
			int n=0;
			int m=0;
			memcpy(a2,a,sizeof(__int64)*128);
			memcpy(b2,b,sizeof(__int64)*128);

			__int64 total=0;

			while (n<N && m<M)
			{
				if (A[n]==B[m])
				{
					if (a2[n]>b2[m])
					{
						total+=b2[m];
						a2[n]-=b2[m];
						m++;
					}
					else if (a2[n]<b2[m])
					{
						total+=a2[n];
						b2[m]-=a2[n];
						n++;
					}
					else
					{
						total+=a2[n];
						n++;
						m++;
					}
				}
				else
				{
					int r=rand()%2;
					if (r)
						n++;
					else
						m++;
				}
			}
			if (total>best)
			{
				fprintf(stderr,"New best: %I64d\n",total);
				best=total;
			}
		}

		//printf("Case #%d: %f %f\n",i+1,best, top);
		
		fprintf(stderr,"Case #%d: %I64d\n",i+1,best);

		printf("Case #%d: %I64d\n",i+1, best);
	}

	return 0;
}
