#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 12;
const int MAX2 = 7000;
const int BASE = 1000000000;

int T;
int n, m;
int Q[MAX];
VI G[MAX];
string S[MAX];
bool R[MAX][256];
bool B[MAX][MAX];

void Init()
{
	FOR (i,0,MAX)
		G[i].clear();
	FILL(B, 0);
}

void SolveTest(int test)
{
	scanf("%d %d", &n, &m);
	FOR (i,0,n)
	{
		cin >> S[i];
	}
	FOR (i,0,m)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		-- u;
		-- v;
		G[u].PB(v);
		G[v].PB(u);
		B[u][v] = B[v][u] = 1;
	}
	VI P;
	string res = "";
	FOR (i,0,n)
		P.PB(i);
	do
	{
		FOR (i,0,n)
			Q[P[i]] = i;
		FILL(R, 0);
		R[0][1 << 0] = 1;
		FOR (i,0,n)
			RFOR (j,(1 << n),1)
			{
				if (R[i][j] == 0)
					continue;
				//cerr << j << ' ' << i << endl;
				int last = -1;
				FOR (k,0,n)
					if ((j & (1 << k)) != 0)
						last = k;
				if (last != -1)
				{
					R[i][j - (1 << last)] = 1;
					if (i+1 < n)
						if (B[P[last]][P[i+1]] == 1)
							R[i+1][j + (1 << (i+1))] = 1;
				}
			}
		bool ok = R[n-1][0];
		//cout << ok << endl;
		if (ok)
		{
			string s = "";
			FOR (i,0,n)
				s += S[P[i]];
			if (res == "" || s < res)
			{
				FOR (j,0,n)
					cerr << P[j] << ' ';
				cerr << endl;
				res = s;
			}
		}
	}
	while (next_permutation(ALL(P)));
	printf("Case #%d: %s\n", test+1, res.c_str());
	cerr << endl;
	//int f;
	//system("pause");
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("C-small-attempt0 (1).in", "r", stdin);
		//freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif

	scanf("%d", &T);
	FOR (test,0,T)
	{
		Init();
		SolveTest(test);
	}

	return 0;
}