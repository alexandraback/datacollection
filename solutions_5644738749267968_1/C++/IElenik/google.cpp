#define _CRT_SECURE_NO_DEPRECATE
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


int main(int argc, char * argv[])
{
	in	= fopen("D-large (2).in","rt");
	out	= fopen("out.txt","wt");
	int numcases = ri();
	for(int ca = 0; ca<numcases; ca++)
	{
		int nb = ri();

		vector<double> nw(nb);
		fi(nb) nw[i] = rf();

		vector<double> pw(nb);
		fi(nb) pw[i] = rf();

		sort(all(pw));
		sort(all(nw));

		int nwn = 0;
		for(int i = 0; nwn+i < nb; )
		{
			if(pw[nwn+i] > nw[i]) i++;
			else nwn++;
		}

		int nwp = 0;
		for(int i = 0; nwp+i < nb; )
		{
			if(nw[nwp+i] > pw[i]) i++;
			else nwp++;
		}


		fprintf(out,"Case #%d: %d %d\n",ca+1,nb-nwp,nwn);
	}
	return 0;
}

