#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <utility>
#include <iomanip>

using namespace std;

int t, n, k, num, x;
vector <int> ch[300];
vector <int> ans;
int kn[300];
int key[300];
int d[2000000];
bool u[2000000];
bool reach[2000000];

void calc(int mask) {
	if (u[mask]) 
		return;
	u[mask] = true;

	if (mask == (1 << n) - 1) 
		reach[mask] = true;

	for (int i = 1; i <= n; i++) 
		if ( ( mask & (1 << (i - 1)) ) == 0 && kn[key[i]] > 0) {
			kn[key[i]]--;
			for (int j = 0; j < (int) ch[i].size(); j++) {
				kn[ch[i][j]]++;
			}

			calc(mask | (1 << (i - 1)));

			if (reach[mask] == false && reach[mask | (1 << (i - 1))] == true) {
				reach[mask] = true;
				d[mask] = i;
			}

			kn[key[i]]++;
			for (int j = 0; j < (int) ch[i].size(); j++) {
				kn[ch[i][j]]--;
			}
		}
}

int main() {
	freopen("D-small-attempt1.in","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d", &t);

	for (int test = 1; test <= t; test++) {
		scanf("%d %d", &k, &n);

		for (int i = 0; i <= n; i++) 
			ch[i].clear();

		for (int i = 0; i < (1 << n); i++) {
			u[i] = false;
			reach[i] = false;
		}

		for (int i = 1; i <= 200; i++) 
			kn[i] = 0;

		for (int i = 1; i <= k; i++) {
			scanf("%d", &x);
			kn[x]++;
		}

		for (int i = 1; i <= n; i++) {
			scanf("%d %d", &key[i], &num);
			for (int j = 1; j <= num; j++) {
				scanf("%d", &x);
				ch[i].push_back(x);
			}
		}

		calc(0);

		if (reach[0] == false) {
			printf("Case #%d: IMPOSSIBLE\n", test);
		}
		else {
			printf("Case #%d: ", test);
			int mask = 0; 
			ans.clear();
			while (mask != (1 << n) - 1) {
				int to = d[mask];
				ans.push_back(to);
				mask |= (1 << (to - 1));
			}
			for (int i = 0; i < n; i++) 
				printf("%d ", ans[i]);
			printf("\n");
		}
	}

	return 0;
}