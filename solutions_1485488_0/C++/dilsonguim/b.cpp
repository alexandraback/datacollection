#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define NDEBUG
#if defined(NDEBUG)
#define DBG_CODE(cb...)
#else
#define DBG_CODE(cb...) cb
#endif
#define WRITE(x) DBG_CODE(cout << x << endl)
#define WATCH(x) DBG_CODE(cout << #x << "=" << x << endl)
#define FORN(i, a, b) for(typeof(b) i = (a); i < (b); i++)
#define ALL(x) x.begin(), x.end()
#define FOREACH(i, c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

const double EPS = 1.e-8;
int cmp(double a, double b)
{
	if(a + EPS < b) return -1;
	if(a - EPS > b) return 1;
	return 0;
}

struct qe
{
	int i;
	int j;
	double t;

	qe(int xi, int xj, double xt) : i(xi), j(xj), t(xt) {};
	bool operator<(const qe& b) const
	{
		if(i < b.i) return false;
		if(i > b.i) return true;
		if(j < b.j) return false;
		if(j > b.j) return true;
		return cmp(t, b.t) != -1;
	}
};

int main(){
	int ntc;
	scanf("%d", &ntc);
	FORN(tc, 0, ntc){
		int h, n, m;
		scanf("%d%d%d", &h, &n, &m);
		int f[n][m];
		int c[n][m];
		FORN(i, 0, n)
			FORN(j, 0, m)
				scanf("%d", &(c[i][j]));
		FORN(i, 0, n)
			FORN(j, 0, m)
				scanf("%d", &(f[i][j]));

		const double INF = 1.e8;
		priority_queue<qe> q;
		double d[n][m];
		FORN(i, 0, n)
			FORN(j, 0, m)
				d[i][j] = INF;

		q.push(qe(0, 0, 0));

		while(not q.empty()){
			qe top = q.top();
			q.pop();
			if(cmp(top.t, d[top.i][top.j]) != -1) continue;
			d[top.i][top.j] = top.t;
			const static int mvi[] = {0, 0, 1, - 1};
			const static int mvj[] = {1, -1, 0, 0};
			FORN(mi, 0, 4){
				double wl = h - top.t * 10;
				int ni = top.i + mvi[mi];
				int nj = top.j + mvj[mi];
				WATCH(ni);
				WATCH(nj);
				if(ni < 0 or nj < 0) continue;
				WRITE("A");
				if(ni >= n or nj >= m) continue;
				WRITE("A");
				WATCH(c[top.i][top.j]);
				WATCH(f[ni][nj]);
				if(c[top.i][top.j] - f[ni][nj] < 50) continue;
				WRITE("A");
				if(c[ni][nj] - f[ni][nj] < 50) continue;
				WRITE("A");
				if(c[ni][nj] - f[top.i][top.j] < 50) continue;
				WRITE("A");
				double cost = top.t;
				bool goes_down = cmp(top.t, 0) != 0;
				if(cmp(wl, c[ni][nj] - 50) == 1){
					double next_wl = c[ni][nj] - 50;
					double ttd = (wl - next_wl) / 10.0;
					wl = next_wl;
					WATCH(next_wl);
					WATCH(ttd);
					cost += ttd;
					goes_down = true;
				}
				
				if(cmp(wl, 20 + f[top.i][top.j]) == -1){
					cost += 10;
				}else{
					cost += 1;
				}
				
				if(not goes_down) cost = 0;
				if(cmp(cost, d[ni][nj]) == -1){
					WRITE("NEXT " << ni << " " << nj << " " << cost );
					q.push(qe(ni, nj, cost));
				}


			}
		}
		printf("Case #%d: %.7lf\n", tc + 1, d[n - 1][m - 1]);
	}
}
