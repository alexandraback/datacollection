#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int keys[210];
vector<int> v[25];
int need[25];

bool used[1048586];
int path[1048586];

int m, n;

bool DFS(int mask) {
	//printf("%d\n", mask);
	if (__builtin_popcount(mask) == n) return true;
	used[mask] = true;
	
	REP(i, n) {
		if (mask & (1 << i)) continue;
		if (used[mask | (1 << i)]) continue;
		if (keys[need[i]] != 0) {
			keys[need[i]]--;
			REP(j, v[i].size()) {
				keys[v[i][j]]++;
			}
			if (DFS(mask | (1 << i))) {
				path[mask] = i;
				return true;
			}
			keys[need[i]]++;
			REP(j, v[i].size()) {
				keys[v[i][j]]--;
			}
		}
	}
	return false;
}

void imprime() {
	int mask = 0;
	REP(i, n) {
		int x = path[mask];
		printf(" %d", x + 1);
		mask = mask | (1 << x);
	}
}

int main()
{		
	int t;
	scanf("%d", &t);
	REP(k, t) {
		memset(used, 0, sizeof(used));
		scanf("%d %d", &m, &n);
		memset(keys, 0, sizeof(keys));
		REP(i, m) {
			int x;
			scanf("%d", &x);
			keys[x]++;
		}
		REP(i, n) {
			scanf("%d", &need[i]);
			int y;
			scanf("%d", &y);
			v[i].clear();
			REP(j, y) {
				int x;
				scanf("%d", &x);
				v[i].push_back(x);
			}
		}
		printf("Case #%d:", k+1);
		if (DFS(0)) {
			imprime();
		}
		else {
			printf(" IMPOSSIBLE");
		}
		printf("\n");
	}
	return 0;
}