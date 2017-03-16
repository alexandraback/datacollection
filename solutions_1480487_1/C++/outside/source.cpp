#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <map>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <fstream>
using namespace std;
 
#ifdef MYDEBUG
#pragma comment(linker, "/stack:1000000000")
#endif

typedef pair<int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;
 
#define MAX(a, b) ((a >= b) ? a : b)
#define MIN(a, b) ((a <= b) ? a : b)
#define ABS(a) ((a < 0) ? -(a) : a)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define sz size()
#define mp make_pair
#define pb push_back
#define HAS(S, v) ((S).find(v) != (S).end())
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
#define CLR(a, b) memset(a, b, sizeof(a))
#define sqr(a) ((a) * (a))
#define V(t) vector<t>
#define VV(t) V(V(t))

V(int) mas;
int x;
double bs(int p) {
	int n = mas.sz;
	double lo = 0.0, hi = 1.0;
	FOR (k, 0, 200) {
		double m = lo + (hi - lo) / 2;
		double value = (double)mas[p] + (double)x * m;
		double taken = m;
		FOR (i, 0, n)
			if (i != p && (double)mas[i] < value) {
				double val = (value - (double)mas[i]) / (double)x;
				taken += val;
			}
		if (taken < 1.0) lo = m;
		else hi = m;
	}
	return lo * 100.0;
}
int main() {
#ifdef MYDEBUG
	freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    clock_t beg = clock();
#endif

	int T;
	scanf("%d", &T);
	FOR (t, 0, T) {
		printf("Case #%d: ", t + 1);
		int n;
		scanf("%d", &n);
		mas.clear();
		mas.resize(n);
		x = 0;
		FOR (i, 0, n) {
			scanf("%d", &mas[i]);
			x += mas[i];
		}
		FOR (i, 0, n) {
			printf("%.20lf", bs(i));
			if (i + 1 == n) printf("\n");
			else printf(" ");
		}
	}
#ifdef MYDEBUG
    fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0 * (clock() - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}