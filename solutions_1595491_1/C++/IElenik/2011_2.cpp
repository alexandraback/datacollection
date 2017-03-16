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

bool isNS(int e, int sc)
{
	return (e <= (sc+2)/3);
}

bool isS(int e, int sc)
{
	if( (sc + 4)/3 - 2 < 0) return false;
	return (e <= (sc+4)/3);
}


int _tmain(int argc, _TCHAR* argv[])
{
	in	= fopen("B-large.in","rt");
	out	= fopen("l_out.txt","wt");
	
	int T = ri(); 
	for(int i = 0; i<T; i++)
	{
		int N = ri(); 
		int S = ri(); 
		int p = ri(); 
		int count = 0;
		fj(N)
		{
			int r = ri();
			if(isNS(p,r)) count ++;
			else if(S && isS(p,r)) { count ++; S--; }
		}
		fprintf(out, "Case #%d: %d\n",i+1, count);
		printf("Case #%d: %d\n",i+1, count);
	}

	fclose(in);
	fclose(out);
	return 0;
}

