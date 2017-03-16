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
#define MP make_pair

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

int dp[1000100];
bool F[1000100];
int Q[1000100];

int rev( int i )
{
	char ch[10];
	sprintf( ch, "%d", i );
	int L = strlen( ch );
	reverse( ch, ch+L );
	int re;
	sscanf( ch, "%d", &re );
	return re;
}

void sol()
{
	F[1] = true;
	dp[1] = 1;
	Q[0] = 1;
	int z = 1;

	FOR(a,0,z-1)
	{
		int c = Q[a];
		int cc = c+1;
		if (cc<=1000000 && !F[cc])
		{
			dp[cc] = dp[c]+1;
			F[cc] = true;
			Q[z] = cc;
			z++;
		}
		cc = rev(c);
		if (cc<=1000000 && !F[cc])
		{
			dp[cc] = dp[c]+1;
			F[cc] = true;
			Q[z] = cc;
			z++;
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	sol();

	int t=0;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";
		int x;
		cin >> x;
		cout << "Case #" << a << ": ";
		cout << dp[x];
		cout << "\n";
	}
	return 0;
}
