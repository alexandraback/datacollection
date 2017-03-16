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

int n;
double d[500000];
double m[500000];
int s;
int solve() {
	scanf("%d", &n);
	s = 0;
	for (int i = 0; i < n; i++) {
		int h;
		scanf("%lf%d%lf", d + s, &h, m + s);
		for (int j = 1; j < h; j++) {
			d[s + j] = d[s];
			m[s + j] = m[s] + j;
		}
		s += h;
	}
	if (s == 1)
		return 0;
	if (m[0] == m[1])
		return 0;
	if (d[0] > d[1])
		swap(d[0], d[1]), swap(m[0], m[1]);
	if (m[0] > m[1]) {
		if (m[0] * (1 - (d[0] / 360)) < m[1] * (2 - (d[1] / 360)))
			return 0;
		return 1;
	} else {
		if (m[0] * (1 - (d[0] / 360)) >= m[1] * (1 - (d[1] / 360)))
			return 0;
		double y = (d[1] - d[0]) / 360 / ((1 / m[0]) - (1 / m[1]));
		double z = d[0] / 360 + y / m[0];
		if (m[1] * (1 - z) < m[0] * (2 - z))
			return 0;
		return 1;
	}
}
int main() {
	int t;
	scanf("%d", &t);
	for (int _ = 1; _ <= t; _++) {
		printf("Case #%d: %d\n", _, solve());
	}
	return 0;
}
