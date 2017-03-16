#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;


const int MAXN = 100+1;
const int INF = 100+1;

int n, m;
int a[MAXN][MAXN];

int r[MAXN], c[MAXN];


bool solve() {
	scanf("%d %d", &n, &m);


	for(int i = 0; i < n; i++) r[i] = -INF;
	for(int i = 0; i < m; i++) c[i] = -INF;


	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			r[i] = max(r[i], a[i][j]);
			c[j] = max(c[j], a[i][j]);
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((a[i][j] != r[i]) && (a[i][j] != c[j])) return false;
		}
	}

	return true;
}



int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: %s\n", i, solve()?"YES":"NO");
	}
}