#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define mp make_pair
#define pb push_back
#define S second
#define F first

using namespace std;

vector<int> G[1101];
int T;
int tanda[1010];
int N;

int main () {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		for (int j = 0; j < N; ++j)
			G[j].clear();
		for (int j = 0; j < N; ++j) {
			int x, a;
			scanf("%d", &x);
			for (int k = 0; k < x; ++k) {
				scanf("%d", &a);
				G[j].pb(--a);
			}
		}
		printf("Case #%d: ", i + 1);
		
		for (int j = 0; j < N; ++j) {
			queue<int> q;
			q.push(j);
			memset(tanda, -1, sizeof tanda);
			tanda[j] = 1;
			while (!q.empty()) {
				int r = q.front();
				q.pop();
				int xx = G[r].size();
				for (int k = 0; k < xx; ++k)
					if (tanda[G[r][k]] != -1) {
						puts("Yes");
						goto hell;
					}
					else {
						tanda[G[r][k]] = 1;
						q.push(G[r][k]);
					}
			}
		}
		puts("No");
		hell: ;
	}
}
