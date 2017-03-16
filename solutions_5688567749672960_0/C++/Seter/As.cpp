//Orz Sevenkplus
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <complex>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#define un using namespace
un std;
#define pb push_back
#define pf pop_front

#define mp make_pair

#define c0 first
#define c1 second
#define sqr(x) ((x)*(x))
#define clr(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, -1, sizeof(x))
#define clr80(x) memset(x, 0x80, sizeof(x))
#define clr7F(x) memset(x, 0x7F, sizeof(x))

#define LL long long
#ifdef __unix__
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif
#define pii pair<int, int>
#define pip pair<int, pii>
#define vi vector<int>
#define vpi vector<pii>
#define pq priority_queue

template<typename T>
inline bool chkmin(T &a, T b){return a > b ? a = b, 1 : 0;}
template<typename T>
inline bool chkmax(T &a, T b){return a < b ? a = b, 1 : 0;}

#define P 1000000007

int ans[1000000];

int solve() {
	int n;
	scanf("%d", &n);
	return n == 1000000 ? ans[999999] + 1 : ans[n];
}

int r(int x) {
	char z[10];
	sprintf(z, "%d", x);
	int p = 1, y = 0;
	for (int i = 0; z[i]; i++) {
		y += p * (z[i] - '0');
		p *= 10;
	}
	return y;
}

int main() {
	int t;
	scanf("%d", &t);
	deque<int> Q;
	Q.push_back(1);
	ans[1] = 1;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pf();
		if (x == 999999)
			continue;
		if (!ans[x + 1]) {
			ans[x + 1] = ans[x] + 1;
			Q.pb(x + 1);
		}
		int y = r(x);
		if (!ans[y]) {
			ans[y] = ans[x] + 1;
			Q.pb(y);
		}
	}
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: %d\n", _, solve());
	}
	return 0;
}
