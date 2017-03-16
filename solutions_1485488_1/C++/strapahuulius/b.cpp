// GCJ 2012 Round 1B - Problem B
// -- strapahuulius

// pre-written code follows
// #includes {{{
#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// }}}
// constants, typedefs, macros {{{
typedef long long LL;
typedef unsigned long long ULL;
const int oo = 1000000000;
const LL OO = 1000000000000000000LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<string> VS;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef complex<double> tComp;
const double PI = 2.0 * acos(0.0);
const double EPS = 1e-9;
#define FORIT(i,c) for (typeof((c).end()) i=(c).begin(); i!=(c).end(); ++i)
#define CERR(x) cerr << (#x) << " = " << (x) << endl
#define COUT(x) cout << (#x) << " = " << (x) << endl
// }}}

// code written during the competition follows
int F[128][128];
int C[128][128];
int T[128][128];
#define INSIDE(x, y) ((x) >= 0 && (y) >= 0 && (x) < m && (y) < n)
const int X[] = {0, 1, 0, -1};
const int Y[] = {1, 0, -1, 0};
int main()
{
	int kase;
	scanf("%d\n", &kase);
	for (int tkase=0; tkase<kase; tkase++)
	{
		printf("Case #%d: ", tkase+1);
		int h, m, n;
		cin >> h >> m >> n;
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				cin >> C[i][j];
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				cin >> F[i][j];
		for (int i=0; i<m; i++)
			for (int j=0; j<n; j++)
				T[i][j] = oo;
		typedef pair<int, PII> State;
		priority_queue<State, vector<State>, greater<State> > pq;
		pq.push(State(0, PII(0, 0)));
		T[0][0] = 0;
		while (!pq.empty())
		{
			State act = pq.top();
			pq.pop();
			int x = act.second.first;
			int y = act.second.second;
			if (act.first > T[x][y])
				continue;
			for (int d=0; d<4; d++)
			{
				int xx = x + X[d];
				int yy = y + Y[d];
				if (!INSIDE(xx, yy)) // (3)
					continue;
				for (int dt=0; ; dt++)
				{
					if (dt > 0 && h - (act.first + dt * 1) < 0)
						break;
					int hh = max(0, h - (act.first + dt) * 1);
					// (1)
					if (hh + 50 > C[xx][yy])
						continue;
					if (F[x][y] + 50 > C[xx][yy])
						continue;
					if (F[xx][yy] + 50 > C[xx][yy])
						continue;
					// (2)
					if (F[xx][yy] > C[x][y] - 50)
						continue;
					int cost = 100;
					if (hh >= F[x][y] + 20)
						cost = 10;
					if (act.first + dt == 0)
						cost = 0;
					if (act.first + dt + cost < T[xx][yy])
					{
						T[xx][yy] = act.first + dt + cost;
						pq.push(State(act.first + dt + cost, PII(xx, yy)));
						break;
					}
				}
			}	
		}
		printf("%.1lf\n", T[m-1][n-1] * 0.1);
	}
	return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
