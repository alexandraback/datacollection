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
	fscanf(in, "%lf", sbuf); 
	/*char c;
	char * b = sbuf;
	while(c = fgetc(in))
	{
		if(c == '\n' || c == 255) break;
		*b++=c;
	}
	*b = 0;*/
	return sbuf; 
}
long long rll() { long long a; fscanf(in, "%lld", &a ); return a; }


int getSmallest(int r, int nd)
{
	int m = r;

	fi(11)
	{
		int n = (r/10)+(r%10)*nd;
		r = n;
		if(m>n) m = n;
	}

	return m;
}

int getNumDigit(int s)
{
	int res = 1;
	while(res <= s) res *= 10;
	return res/10;
}

int _tmain(int argc, _TCHAR* argv[])
{
	in	= fopen("C-large.in","rt");
	out	= fopen("l_out.txt","wt");
	
	int T = ri(); 
	for(int i = 0; i<T; i++)
	{
		int a = ri(); 
		int b = ri(); 
		map<int,int> m;

		int nd = getNumDigit(a);
		for(int j = a; j<=b; j++)
			m[getSmallest(j,nd)]++;

		__int64 count = 0;
		for(map<int,int>::iterator j = m.begin(); j!=m.end(); j++)
		{
			if(j->second > 1)
			{
				count += (j->second-1)*((__int64)j->second)/2;
			}
		}
		

		fprintf(out, "Case #%d: %lld\n",i+1, count);
		printf("Case #%d: %lld\n",i+1, count);
	}

	fclose(in);
	fclose(out);
	return 0;
}

