#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

int n;
ll m1, m2;
ll d1, d2;
ll h1, h2;

void solve() {
	scanf("%d", &n);
	if (n==1) {
		scanf("%lld%lld%lld", &d1, &m1, &h1);
		printf("0\n"); return;
	}
	scanf("%lld%lld%lld", &d1, &h1, &m1);
	scanf("%lld%lld%lld", &d2, &h2, &m2);
	m1 *= 360; m2 *= 360;
	// 1 je rychlejsi
	if (m1 > m2) {
		swap(m1, m2); swap(d1, d2);
	}
	if (m1 + (360-d1)*m1/360 <= (360-d2)*m2/360) printf("1\n");
	else printf("0\n");
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
