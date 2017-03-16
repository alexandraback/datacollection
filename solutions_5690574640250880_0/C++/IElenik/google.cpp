#define _cRT_SEcURE_NO_DEPREcATE
#define __int64 long long

#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <list>
#include <set>
#include <deque>
#include <math.h>

using namespace std;

FILE * in, * out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

int ri() { int a; fscanf(in, "%d", &a ); return a; }
double rf() 
{ 
	double a; 
	fscanf(in, "%lf", &a ); 
	return a; 
}

char * sbuf = 0; 
string rstr() 
{
	//fscanf(in, "%lf", sbuf); 
	if(sbuf == 0)
		sbuf = new char [(1<<20)+1];

	char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\r' || c == '\n' || c == -1) 
		{
			if(b - sbuf > 0)
				break;
			continue;
		}
		*b++=c;
	}
	*b = 0;
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }

int printfield(int i, int j, int ai, int aj, int r, int c)
{
	int nm = 0;
	for(int i1 = 1; i1<= r; i1++)
	{
		for(int j1 = 1; j1<= c; j1++)
		{
			if(i1 == 1 && j1 == 1) fprintf(out,"c");
			else if(i1 <= i && j1 <= j) fprintf(out,".");
			else if(i1 <= i+1 && j1 <= aj) fprintf(out,".");
			else if(i1 <= ai && j1 <= j+1) fprintf(out,".");
			else { fprintf(out,"*"); nm++; }
		}
		fprintf(out,"\n");
	}
	return nm;
}

int main(int argc, char * argv[])
{
	in	= fopen("C-small-attempt5.in","rt");
	FILE * out1 = out	= fopen("out.txt","wt");
	FILE * out2	= fopen("out1.txt","wt");
	int numcases = ri();
	for(int ca = 0; ca<numcases; ca++)
	{
		int r = ri();
		int c = ri();
		int m = ri();


		bool bFound = false;
		fprintf(out,"case #%d:\n", ca+1);
		for(int i = 2; i <= r-1 && !bFound; i++)
		{
			for(int j = 2; j <= c-1 && !bFound; j++)
			{
				if(i*j + m > r*c) continue;
				if(r*c - i*j - m == 1) continue;
				if(r*c - i*j - m > i+j-2 ) continue;

				for(int ai = 0; ai < i && !bFound; ai++)
				{
					if(ai == 1) continue;

					int aj = r*c - i*j - m - ai;
					if(aj == 1) continue;
					if(aj >= j) continue;
					bFound = true;
					if(m != printfield(i,j,ai,aj,r,c))
						__asm int 3;
				}
			}
		}
		for(int i = 2; i <= r && !bFound; i++)
		{
			int j  = c;
			int ai = 0;
			if(i*j + m > r*c) continue;
			if(r*c - i*j - m == 1) continue;
			if(r*c - i*j - m > j-1 && r*c - i*j - m > 0) continue;
			int aj = r*c - i*j - m;
			if(aj == 1) continue;
			if(aj >= j) continue;
			bFound = true;

			if(m != printfield(i,j,ai,aj,r,c))
				__asm int 3;
		}
		for(int j = 2; j <= c-1 && !bFound; j++)
		{
			int i  = r;
			if(i*j + m > r*c) continue;
			if(r*c - i*j - m == 1) continue;
			if(r*c - i*j - m > i-1  && r*c - i*j - m > 0) continue;
			int ai = r*c - i*j - m;
			int aj = 0;
			if(ai == 1) continue;
			if(ai >= i) continue;
			bFound = true;

			if(m != printfield(i,j,ai,aj,r,c))
				__asm int 3;
		}
		if(!bFound && r*c-m == 1)
		{
			bFound = true;
			printfield(0,0,0,0,r,c);
		}

		if(!bFound && c == 1)
		{
			bFound = true;
			printfield(r-m,1,0,0,r,c);
		}
		if(!bFound && r == 1)
		{
			bFound = true;
			printfield(1,c-m,0,0,r,c);
		}
		if(!bFound && m == 0)
		{
			bFound = true;
			printfield(r,c,0,0,r,c);
		}

		if(!bFound) 
		{			
			fprintf(out,"Impossible\n");

			out = out2;
			fprintf(out,"case #%d:\n", ca+1);
			fprintf(out,"Impossible\n");
			for(int j = 0; j <= c && !bFound; j++)
			{
				int i  = r;
				if(i*j + m > r*c) continue;
				if(r*c - i*j - m > i) continue;
				int ai = r*c - i*j - m;
				int aj = 0;

				if(m != printfield(i,j,ai,aj,r,c))
					__asm int 3;
				bFound = true;
			}
			out = out1;
		}
	}
	return 0;
}

