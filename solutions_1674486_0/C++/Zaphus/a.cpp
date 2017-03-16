// a.cpp : Defines the entry point for the console application.
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

int S[1024][1024];
bool path[1024][1024];

int countpaths(int a, int b, bool firsttime=true)
{
	int count=0;
	
	for (int m=0; m<1024; m++)
	{
		if (S[a][m]>0)
		{
			if (S[a][m]==(b+1))
				count++;
			else
			{
				count += countpaths(S[a][m]-1,b, false);
			}
			if (count>1)
				return count; // we can stop now!
		}
	}
	return count;
}

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

		for (int n=0; n<N; n++)
		{
			int links=0;
			memset(S[n],0,sizeof(int)*1024);
			scanf("%d",&links);
			for (int i=0; i<links; i++)
				scanf("%d",&S[n][i]);
		}

		memset(path,0,sizeof(bool)*1024*1024);

		bool foundone=false;
		for (int n=0; n<N; n++)
		{
			for (int m=0; m<N; m++)
			if (n!=m && !foundone)
			{
				int paths=countpaths(n,m);
				if (paths>1)
				{
					foundone=true;
					break;
				}
			}
		}

		fprintf(stderr,"Case #%d: %s\n",i+1,(foundone)?"Yes":"No");

		printf("Case #%d: %s\n",i+1,(foundone)?"Yes":"No");
	}

	return 0;
}
