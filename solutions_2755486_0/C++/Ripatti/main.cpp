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

struct QUE
{
	int x, y, s, t;
	bool build;
	QUE( int _x=0, int _y=0, int _s=0, int _t=0, bool _b=false )
	{
		x=_x; y=_y; s=_s; t=_t; build=_b;
	}
};

bool le( const QUE & A, const QUE & B )
{
	if (A.t != B.t) return A.t < B.t;
	return A.build < B.build;
}

QUE Q[2000100];
int q_sz;
map< int, int > Map;

int A[300];

void scale()
{
	Map.clear();

	FOR(a,0,q_sz-1)
	{
		Map[Q[a].x] = 0;
		Map[Q[a].y+1] = 0;
	}

	int ii=0;
	for (map< int, int >::iterator it = Map.begin(); it != Map.end(); it++)
		it->second = ii++;

	FOR(a,0,q_sz-1)
	{
		Q[a].x = Map[Q[a].x];
		Q[a].y = Map[Q[a].y+1]-1;
	}

	ass( SZ(Map) < 300 );
}

void sol()
{
	sort( Q, Q+q_sz, le );
	scale();

	CLR(A);
	int ans = 0;
	FOR(a,0,q_sz-1)
		if (Q[a].build)
		{
			FOR(c,Q[a].x,Q[a].y) A[c] = max( A[c], Q[a].s );
		}
		else
		{
			FOR(c,Q[a].x,Q[a].y)
				if (A[c] < Q[a].s)
				{
					ans++;
					break;
				}
		}

	cout << ans;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	FOR(a,1,T)
	{
		q_sz = 0;

		int n;
		RE("%d", &n);
		FOR(b,1,n)
		{
			int ti, ni, wi, ei, si, dt, dp, ds;
			RE("%d%d%d%d%d%d%d%d", &ti, &ni, &wi, &ei, &si, &dt, &dp, &ds );
			FOR(c,1,ni)
			{
				Q[q_sz++] = QUE( wi, ei-1, si, ti, false );
				Q[q_sz++] = QUE( wi, ei-1, si, ti, true );
				wi+=dp; ei+=dp;
				ti+=dt;
				si+=ds;
			}
		}
		cout << "Case #" << a << ": ";
		sol();
		cout << "\n";
	}

	return 0;
}
