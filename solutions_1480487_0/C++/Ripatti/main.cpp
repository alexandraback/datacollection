#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>
#include <set>
#include <ctime>
#include <algorithm>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define WR printf
#define RE scanf
#define PB push_back
#define SE second
#define FI first

#define FOR(i,k,n) for(int i=(k); i<=(n); i++)
#define DFOR(i,k,n) for(int i=(k); i>=(n); i--)
#define SZ(a) (int)((a).size())
#define FA(i,v) FOR(i,0,SZ(v)-1)
#define RFA(i,v) DFOR(i,SZ(v)-1,0)
#define CLR(a) memset(a, 0, sizeof(a))

#define LL long long
#define VI  vector<int>
#define PAR pair<int ,int>
#define o_O 1000000000

void __never(int a){printf("\nOPS %d", a);}
#define ass(s) {if (!(s)) {__never(__LINE__);cout.flush();cerr.flush();abort();}}

int n;
int p[250];
int sum;

bool check( int i, double t )
{
	double cur = (double)p[i] + sum*t;

	double ss=0.;
	FOR(a,1,n) if (a!=i) if ((double)p[a] < cur) ss += cur-p[a];

	return ss > sum*(1.-t);
}

void sol()
{
	sum = 0;
	FOR(a,1,n) sum += p[a];
	FOR(a,1,n)
	{
		double mi = 0., ma = 1.;
		FOR(b,1,100)
		{
			double sr = (mi+ma)*0.5;
			if (check( a, sr )) ma = sr;
			else mi = sr;
		}
		WR(" %.9lf", mi*100.);
	}
	cout << "\n";
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(a,1,T)
	{
		cin >> n;
		FOR(b,1,n) cin >> p[b];
		cout << "Case #" << a << ":";
		sol();
	}
	return 0;
}
