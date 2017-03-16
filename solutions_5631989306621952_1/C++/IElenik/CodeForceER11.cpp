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
#include <intrin.h>
#include <bitset>


#pragma intrinsic(_mul128)

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

vector<int> primes;
void calculatePrimes()
{
	primes.push_back(2);
	for (int i = 3; i < (1<<15); i += 2)
	{
		bool bFound = false;
		int m = sqrt(i);
		for (int j = 1; j < primes.size() && !bFound && primes[j] <= m; j++)
			bFound = ((i%primes[j]) == 0);
		if (!bFound)
			primes.push_back(i);
	}
}

int main()
{
	long long n, t, num; 
	string s;
	cin >> t;

	fk(t)
	{
		cin >> s;
		string o;
		o += s[0];
		for (int i = 1; i < s.size(); i++)
		{
			string n;
			n += s[i];
			if (s[i] < o[0]) o = o + n;
			else o = n + o;
		}

		cout << "Case #" << k+1 << ": " << o << endl;

	}

	return 0;
}

