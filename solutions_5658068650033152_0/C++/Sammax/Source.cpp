/*
ID: 
PROG: kimbits
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <complex>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <complex>
#include <stdio.h>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <stack>
#ifdef SAMMAX
#include <ctime>
clock_t beg;
#endif

const double pi = 3.1415926535897932384626433832795;
double EPS = 10e-4;
const int INF = 2000000000;

#pragma comment(linker, "/stack:1500000000")
#define sz size()
#define mp make_pair
#define pb push_back
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define MEMS(a,b) memset(a,b,sizeof(a))
#define sqr(a) ((a)*(a))
#define HAS(a,b) ((a).find(b)!=(a).end())
#define MAX(a,b) ((a>=b)?a:b)
#define MIN(a,b) ((a<=b)?a:b)
#define ABS(a) ((a<0)?-(a):a)
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define FORD(i,a,b) for (int i=(a);i>(b);--i)
#define VVI vector < vector <int> >
#define VI vector <int>
#define LL long long    
#define U unsigned
#define pnt pair <int,int>
LL gcd(LL a, LL b){ if (a == 0) return b; return gcd(b%a, a); }
LL lcm(LL a, LL b){ return a / gcd(a, b) * b; }

using namespace std;

void ifd() {
#ifdef SAMMAX
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout); 
	beg = clock();
#else
	//freopen("kimbits.in", "r", stdin);
	//freopen("kimbits.out", "w", stdout);
#endif  
}
void tme() {
#ifdef SAMMAX
	fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0*(clock() - beg) / CLOCKS_PER_SEC);
#endif
}



int t, ans, n, m, k, all, pos, tmp_cnt, cur;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int d[22][22], was[22][22];

void dfs(int ci, int cj) {
	was[ci][cj] = cur;

	FOR(i, 0, 4) {
		if (ci + di[i] >= 0 && ci + di[i] < n &&
			cj + dj[i] >= 0 && cj + dj[i] < m && was[ci + di[i]][cj + dj[i]] != cur && !d[ci + di[i]][cj + dj[i]]) {
			dfs(ci + di[i], cj + dj[i]);
		}
	}
}

bool ok() {
	int cnt = 0;

	FOR(i, 0, n) {
		if (!d[i][0] && was[i][0] != cur) {
			dfs(i, 0);
		}
		if (!d[i][m - 1] && was[i][m - 1] != cur) {
			dfs(i, m - 1);
		}
	}

	FOR(i, 0, m) {
		if (!d[0][i] && was[0][i] != cur) {
			dfs(0, i);
		}
		if (!d[n - 1][i] && was[n - 1][i] != cur) {
			dfs(n - 1, i);
		}
	}
	
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cnt += (was[i][j] != cur);
		}
	}
	return cnt >= k;
}

int main() {
	ifd();


	scanf("%d", &t);

	FOR(cs, 1, t + 1) {
		scanf("%d %d %d", &n, &m, &k);
		
		FOR(i, 0, n) {
			FOR(j, 0, m) {
				was[i][j] = -1;
			}
		}

		ans = k;
		all = n * m;

		FOR(bts, 0, (1 << all)) {
			cur = bts;
			pos = 0;
			tmp_cnt = 0;

			FOR(i, 0, n) {
				FOR(j, 0, m) {
					d[i][j] = ((bts >> pos) & 1);
					tmp_cnt += d[i][j];
					pos++;
				}
			}

			if (ok()) {
				ans = MIN(ans, tmp_cnt);
			}

		}
		
		printf("Case #%d: %d\n", cs, ans);
	}

	tme();
	return 0;
}