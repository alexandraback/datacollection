#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> g[1000];
int bff[1000];
bool used[1000];

int dfs(int curr, int no) {
	int ans = 0;
	for (int i = 0; i < g[curr].size(); i++) {
		int next = g[curr][i];
		if (next == no)	continue;
		ans = max(ans, 1+dfs(next, no));
	}
	return ans;
}

int main (void) {
	int t;
	scanf ("%d", &t);
	for (int c = 1; c <= t; c++) {
		int n;
		scanf ("%d", &n);
		for (int i = 0; i < n; i++) {
			g[i].clear();
		}
		
		for (int i = 0; i < n; i++) {
			scanf ("%d", &bff[i]);
			bff[i]--;
			g[bff[i]].push_back(i);
		}
		int ans1 = 0, ans2 = 0;
		int cnt2 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)	used[j] = false;
			int curr = i;
			used[curr] = true;
			int cnt = 1;
			while (bff[curr] != i && !used[bff[curr]]) {
				curr = bff[curr];
				used[curr] = true;
				cnt++;
			}
			if (bff[curr] == i)	{
				ans1 = max(ans1, cnt);
				if (cnt == 2) {
					ans2 += 1 + dfs(i, bff[i]);
				}
			}	
			// printf ("%d ", bff[curr] == i ? cnt : 1);
		}
		printf ("Case #%d: %d\n",c , max(ans1, ans2));
	}
}