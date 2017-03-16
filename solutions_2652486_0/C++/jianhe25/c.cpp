#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>
using namespace std;
#define REP(i, n) for (int i = 0; i < n; ++i)
#define TR(i, x) for (typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define PB push_back
#define MP make_pair
typedef long long ll;

const int MAXK = 20;
const int MAXN = 20;
int products[MAXK];
int path[MAXN];
int n, m, k, R;

bool dfs(int depth, int product, int last) {
	if (depth == n) {
		REP(round, k) {
			if (product % products[round] != 0)
				return false;
		}
		return true;
	}
	for (int i = last; i <= m; ++i) {
		path[depth] = i;
		if (dfs(depth + 1, product * i, i))
			return true;
	}
}
int main() {
	int test;
	cin >> test;
	for (int cas = 1; cas <= test; ++cas) {
		cin >> R >> n >> m >> k;
		printf("Case #%d:\n",cas);
		REP(round, R) {
			REP(round, k)
				scanf("%d",&products[round]);
			dfs(0, 1, 2);
			for (int i = 0; i < n; ++i)
				printf("%d",path[i]);
			cout << endl;
		}
	}
}

