#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 1007;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 18;

int PRIME = 1000003;

Int Hash(string s)
{
	Int h = 0;
	FOR(i,0,s.size())
		h = h * PRIME + s[i];
	return h;
}

VI G[MAX];
int M[MAX];
bool U[MAX];

bool dfs (int v) {
	if (U[v])  return 0;
	U[v] = 1;
	FOR(i,0,G[v].size())
	{
		int to = G[v][i];
		if (M[to] == -1 || dfs(M[to]))
		{
			M[to] = v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	freopen("in.txt", "r", stdin);
	//freopen("out.txt" , "w", stdout);
	//freopen("equation.in", "r", stdin);
	//freopen("equation.out", "w", stdout);

	int t;
	cin >> t;
	FOR(tt,0,t)
	{
		printf("Case #%d: " , tt + 1);
		int n;
		cin >> n;
		vector<PII> E;
		VI X, Y;
		FOR(i,0,n)
		{
			string S,T;
			cin >> S >> T;
			Int h1 = Hash(S);
			Int h2 = Hash(T);
			E.push_back(MP(h1 ,h2));
			X.push_back(h1);
			Y.push_back(h2);
		}
		sort(ALL(X));
		X.resize(unique(ALL(X)) - X.begin());
		sort(ALL(Y));
		Y.resize(unique(ALL(Y)) - Y.begin());
		FOR(i,0,n) G[i].clear();
		FOR(i,0,E.size())
		{
			E[i].first = lower_bound(ALL(X) , E[i].first) - X.begin();
			E[i].second = lower_bound(ALL(Y) , E[i].second) - Y.begin();
			G[E[i].first].push_back(E[i].second);
		}

		int res = n - SZ(X) - SZ(Y);
		FILL(M, -1);
		FILL(U,0);
		FOR(i,0,X.size())
		{
			FILL(U, 0);
			res += dfs(i);
		}

		cout << res << endl;


	}
}
