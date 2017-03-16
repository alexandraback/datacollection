// 2011_2.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <functional>
#include <vector>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <math.h>

using namespace std;

FILE * in, *out;

#define fo(a,b,c) for(int a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )
#define mp make_pair
#define pb push_back
#define all(v) (v).begin( ), (v).end( )
#define _(a,b) memset( a, b, sizeof( a ) )

#define LL long long

int ri() { int a; fscanf(in, "%d", &a); return a; }
double rf() { double a; fscanf(in, "%lf", &a); return a; }
char sbuf[100005];
string rstr()
{
	//fscanf(in, "%lf", sbuf); 
	char c;
	char * b = sbuf;
	while (c = fgetc(in))
	{
		if (c == '\n' || c == 255) break;
		*b++ = c;
	}
	*b = 0;
	return sbuf;
}


int nod(int a, int b)
{
	if (a == 1 || b == 1) return 1;
	if (a == 0) return b;
	if (b == 0) return a;

	return nod(b%a, a);
}

int main()
{
	long long n, t;
	cin >> t;

	fi(t)
	{
		cin >> n;
		set<int> ex;
		set<int> dig;

		int j = 1;
		while (true)
		{
			long long d = n*j;
			if (ex.find(d) != ex.end()) break;
			ex.insert(d);
			while (d)
			{
				dig.insert(d % 10);
				d /= 10;
			}

			if (dig.size() == 10) break;
			j++;
		}

		cout << "Case #" << i + 1 << ": ";
		if (dig.size() == 10) cout << j*n; else cout << "INSOMNIA";
		cout << endl;
	}

	return 0;
}

