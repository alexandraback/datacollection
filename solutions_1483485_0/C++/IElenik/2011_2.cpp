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


map<char,char> l;

void loadToMap(const char * a, const char * b)
{
	while(*a)
	{
		if(l.find(*b) != l.end() && l.find(*b)->second != *a)
			printf("Error1\n");
		if(!*b)
			printf("Error2\n");
		l[*b++] = *a++;
	}
	if(*b)
		printf("Error3\n");
}

void translate(const char * a, char * b)
{
	while(*a)
	{
		if(l.find(*a) == l.end())
		{
			printf("Error1\n");
			*b++ = '_';
			*a++;
			continue;
		}
		*b++ = l.find(*a++)->second ;
	}
	*b = 0;
}

void init_mapping()
{
	l['y'] = 'a';
	l['e'] = 'o';
	l['q'] = 'z';

	loadToMap("our language is impossible to understand","ejp mysljylc kd kxveddknmc re jsicpdrysi");
	loadToMap("there are twenty six factorial possibilities","rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	loadToMap("so it is okay if you want to just give up","de kr kd eoya kw aej tysr re ujdr lkgc jv");
	loadToMap("q","z");
}



int _tmain(int argc, _TCHAR* argv[])
{
	in	= fopen("A-small-attempt1.in","rt");
	out	= fopen("s_out.txt","wt");
	init_mapping();
	
	int T = ri(); 
	fgetc(in);

	char rd[1024] = "";

	translate("de kr kd eoya kw aej tysr re ujdr lkgc jv", rd);
	for(int i = 0; i<T; i++)
	{
		string rs = rstr();
		translate(rs.c_str(), rd);
		fprintf(out, "Case #%d: %s\n",i+1, rd);
		printf("Case #%d: %s\n",i+1, rd);
	}

	fclose(in);
	fclose(out);
	return 0;
}

