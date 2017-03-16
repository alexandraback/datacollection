#include <string>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stack>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(int k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)
#define ABS(a) ((a)>0?(a):-(a))
#define pb push_back

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<vector<double> > VVD;
typedef vector<vector<bool> > VVB;


bool kuhn(int v, vector<bool>& used, vector<int>& neighboor, const vector<vector<bool> >& g)
{
	if (used[v]) return false;
	used[v] = true;
	REP(i, g[v].size()) if (g[v][i])
	{
		if (neighboor[i] == -1 || kuhn(neighboor[i], used, neighboor, g))
		{
			neighboor[i] = v;
			return true;
		}
	}
	return false;
}


int main(int argv, char** argc) {
	freopen("C-small-attempt1.in", "r", stdin);
	freopen("C-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	char c1[23], c2[23];
	FOR(tc, 1, T + 1)
	{
		map<string, int> m1, m2;
		vector<pair<int, int> > e;
		int NN;
		scanf("%d", &NN);
		REP(i, NN)
		{
			scanf("%s %s", c1,c2);
			string s(c1), z(c2);
			if (m1.count(s) == 0)
			{
				int t1 = m1.size();
				m1[s] = t1;
			}
			if (m2.count(z) == 0)
			{
				int t2 = m2.size();
				m2[z] = t2;
			}
			e.push_back(make_pair(m1[s], m2[z]));
		}
		int N = m1.size();
		int M = m2.size();
		vector<vector<bool> > g(N, vector<bool>(M));
		REP(i, e.size())
		{
			g[e[i].first][e[i].second] = 1;
		}
		vector<int> neigh(M, -1);
		vector<bool> used(N);
		for (int i = 0; i < N; ++i)
		{
			fill(used.begin(), used.end(), false);
			kuhn(i, used, neigh, g);
		}
		int ans = 0;
		REP(i, M) if (neigh[i] != -1) ++ans;
		int res = N + M - ans;
		printf("Case #%d: %d\n", tc, e.size()-res);
	}
	return 0;
}