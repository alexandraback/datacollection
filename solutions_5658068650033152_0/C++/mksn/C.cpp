#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wunused-result"
#else
#define _CRT_SECURE_NO_WARNINGS
#define _SCL_SECURE_NO_WARNINGS
#endif
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <algorithm>
#include <string>
#include <iostream>
#define FOR(x,y,z) for (int x=(y); x<=(z); ++x)
#define FORD(x,y,z) for(int x=(y); x>=(z); --x)
#define REP(x,y) for (int x=0; x<(y); ++x)
#if defined(__GNUC__) && __cplusplus < 201103L
#define FOREACH(y,x) for (typeof((x).begin()) y = (x).begin(); y != (x).end(); ++y)
#else
#define FOREACH(y,x) for (auto y = (x).begin(); y != (x).end(); ++y)
#endif
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((int)(x).size())
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
const int INF = 1000000001;

inline int Pow2(int exp) { return 1 << exp; }

template<typename T>
inline T Pow2(int exp) { return (T)1 << exp; }

int xp[4] = { -1, 1, 0, 0 };
int yp[4] = { 0, 0, -1, 1 };

bool Chk(int n, int m, int b, int v0)
{
	if (b & Pow2(v0)) return true;
	queue<int> q;
	q.push(v0);
	int vs = Pow2(v0);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int x = v/m, y = v%m;
		if (x == 0 || x == n-1 || y == 0 || y == m-1) return false;
		REP(i,4) {
			int ux = x + xp[i];
			int uy = y + yp[i];
			if (ux < 0 || ux >= n || uy < 0 || uy >= m) continue;
			int u = ux*m + uy;
			if ((b & Pow2(u)) || (vs & Pow2(u))) continue;
			vs |= Pow2(u);
			q.push(u);
		}
	}
	return true;
}

int Go(int n, int m, int k)
{
	int res = INF;
	REP(i,Pow2(n*m)) {
		int x = 0;
		REP(j,n*m) x += ((i & Pow2(j)) != 0);
		if (x >= res) continue;
		int y = 0;
		REP(j,n*m) {
			y += Chk(n, m, i, j);
			if (y >= k) {
				res = x;
				break;
			}
		}
	}
	return res;
}

int main(int argc, char** argv)
{
	int tc;
	scanf("%d", &tc);
	FOR(tccc,1,tc) {
		int n,m,k;
		scanf("%d%d%d", &n, &m, &k);
		int res = Go(n, m, k);
		printf("Case #%d: %d\n", tccc, res);
	}

#ifdef _DEBUG
	system("pause");
#endif
	return 0;
}
