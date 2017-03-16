#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x))
#define WATCH(x) TRACE(cout << #x" = " << x << endl)

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define _FOR(it, b, e) for (decltype(b) it = (b); it != (e); ++it)
#define foreach(x...) _FOR(x)
#define fu(i, a) foreach(i, 0, a)
#define forall(i, v) foreach(i, all(v))

#define MSET(c, v) memset(c, v, sizeof(c))

#define pb push_back
#define sz(c) int((c).size())

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

int main() {
	int _;
	scanf("%d", &_);
	fu(__,_) {
		printf("Case #%d:\n", __+1);
		int R,N,M,K;
		scanf("%d %d %d %d", &R, &N, &M, &K);
		fu(i, R) {
			vi ans;
			double maxp = 0.;
			vi temp(K, 0);
			fu(i, K) scanf("%d", &temp[i]);
			foreach(p1, 2, M+1) foreach(p2, 2, M+1) foreach(p3, 2, M+1) {
				vector<double> prob(5*5*5+1, 0.);
				fu(i, 2) fu(j, 2) fu(k, 2) prob[ (i?p1:1)*(j?p2:1)*(k?p3:1) ] += 1./8;
				double p = 1.;
				fu(i, K) p *= prob[temp[i]];
				if (p > maxp) {
					maxp = p;
					ans = {p1, p2, p3};
				}
			}
			printf("%d%d%d\n", ans[0], ans[1], ans[2]);
		}
	}
	return 0;
}
