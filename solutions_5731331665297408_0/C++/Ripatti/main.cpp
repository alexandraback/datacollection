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

// stupid algo should work in O(n! * 2^n * n) or something like that

int n, m;
bool M[10][10];
string zips[10];
string ans;

int p[10];
int q[10];

bool dfs( int i, int j )
{
	if (i==n-1)
		return true;

	DFOR(a,j,0) if (M[q[a]][p[i+1]])
	{
		q[a+1] = p[i+1];
		if (dfs( i+1, a+1 ))
			return true;
	}

	return false;
}

void sol()
{
	ans = "a";

	FOR(a,0,n-1) p[a] = a+1;
	while(1)
	{
		q[0] = p[0];
		if ( dfs( 0, 0 ) )
		{
			string tmp;
			FOR(a,0,n-1) tmp = tmp + zips[p[a]];
			ans = min( ans, tmp );
		}

		if (!next_permutation( p, p+n )) break;
	}

	cout << ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	FOR(a,1,t)
	{
		cerr << a << "\n";

		cin >> n >> m;
		FOR(b,1,n) cin >> zips[b];
		CLR(M);
		FOR(b,1,m)
		{
			int x, y;
			cin >> x >> y;
			M[x][y] = M[y][x] = true;
		}
		
		cout << "Case #" << a << ": ";
		sol();
		cout << "\n";
	}
	return 0;
}
