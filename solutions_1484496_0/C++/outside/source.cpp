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

const int N = 20 + 1, M = 20 * 100 * 1000 + 10;
int dp[2][N][2 * M];
V(int) mas, m1, m2;
int R(bool f, int p, int s) {
	int &r = dp[f][p][s + M];
	if (r != -1) return r;
	if (p == mas.sz) return r = (f && (s == 0));
	if (R(f, p + 1, s)) {
		return r = 1;
	} else if(R(1, p + 1, s + mas[p])) {
		return r = 1;
	} else if(R(1, p + 1, s - mas[p])) {
		return r = 1;
	}
	return r = 0;
}
void dfs(bool f, int p, int s) {
	if (p == mas.sz && f && (s == 0)) return;
	if (R(f, p + 1, s)) {
		dfs(f, p + 1, s);
		return;
	} else if(R(1, p + 1, s + mas[p])) {
		m1.pb(mas[p]);
		dfs(1, p + 1, s + mas[p]);
		return;
	} else if(R(1, p + 1, s - mas[p])) {
		m2.pb(mas[p]);
		dfs(1, p + 1, s - mas[p]);
		return;
	}
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
		printf("Case #%d:\n", t + 1);
		mas.clear();
		m1.clear();
		m2.clear();
		int n;
		scanf("%d", &n);
		mas.resize(n);
		FOR (i, 0, n)
			scanf("%d", &mas[i]);
		CLR(dp, -1);
		if (R(0, 0, 0)) {
			dfs(0, 0, 0);
			//int sum = 0;
			FOR (i, 0, m1.sz) {
				printf("%d", m1[i]);
				//sum += m1[i];
				if (i + 1 == m1.sz) printf("\n");
				else printf(" ");
			}
			//printf("%d\n", sum);
			//sum = 0;
			FOR (i, 0, m2.sz) {
				printf("%d", m2[i]);
				//sum += m2[i];
				if (i + 1 == m2.sz) printf("\n");
				else printf(" ");
			}
			//printf("%d\n", sum);
		} else printf("Impossible\n");
	}
#ifdef MYDEBUG
    fprintf(stderr, "*** Total time: %.3lf ***\n", 1.0 * (clock() - beg) / CLOCKS_PER_SEC);
#endif
    return 0;
}