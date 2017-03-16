// 2011_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

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
double rf() { double a; fscanf(in, "%lf", &a ); return a; }
char sbuf[100005]; 
string rstr() 
{
	//fscanf(in, "%lf", sbuf); 
	char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\n' || c == 255) break;
		*b++=c;
	}
	*b = 0;
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }

bool vilet(int ind, double p, int sum, int * v, int num)
{
	double cv = v[ind] + p*sum;
	double rest = (1-p)*sum;
	for(int i = 0; i<num && rest >= 0; i++)
	{
		if(i == ind) continue;
		if(v[i] < cv) rest -= cv-v[i];
	}
	return rest > 0;
}

long _tmain(int argc, _TCHAR* argv[])
{
	in	= fopen("A-small-attempt0.in","rt");
	out	= fopen("s_out.txt","wt");
	
	int T = ri(); 
	int	v[1000];
	float			p[1000];
	
	for(int i = 0; i<T; i++)
	{
		int N = ri(); 
		int s = 0;
		for(int j = 0; j<N; j++) { v[j] = ri(); s = s + v[j]; }
		
		fprintf(out, "Case #%d: ",i+1);
		for(int j = 0; j<N; j++) 
		{
			double p  = 0.5;
			double cp = 0.25;
			fk(30)
			{
				if(vilet(j,p,s,v,N))
					p += cp;
				else
					p-=cp;

				cp /= 2;
			}

			fprintf(out, "%f ",p*100);
		}
		fprintf(out, "\n");
	}

	fclose(in);
	fclose(out);
	return 0;
}

