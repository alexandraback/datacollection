#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int a[1024];
int vis[1024];
bool is_cycle[1024];
bool is_2_cycle[1024];
int depth[1024];

int ans;

void clr() {
	for (int i = 0; i < 1024; i++) {
		vis[i] = -1;
		is_cycle[i] = false;
		is_2_cycle[i] = false;
		depth[i] = -1;
	}
}

void flag_on(int v, int rem, int len) {
	is_cycle[v] = true;
	is_2_cycle[v] = (len == 2);
	rem--;

	if (rem > 0)
		flag_on(a[v], rem, len);
}

void find_cycle(int v, int cnt) {
	vis[v] = cnt;

	if (vis[a[v]] == -1) {
		find_cycle(a[v], cnt + 1);
	} else {
		int len = cnt - vis[a[v]] + 1;
		ans = max(ans, len);
		flag_on(v, len, len);
	}

	vis[v] = -1;
}

void calc_depth(int v, int accum) {
	if (is_2_cycle[v])
		depth[v] = max(depth[v], accum);
	else if (!is_cycle[v])
		calc_depth(a[v], accum + 1);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d:", t);

		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[i];

		ans = 0;

		clr();
		for (int i = 1; i <= n; i++)
			if(vis[i] == -1)
				find_cycle(i, 0);

		for (int i = 1; i <= n; i++)
			calc_depth(i, 1);

		int nans = 0;
		for (int i = 1; i <= n; i++)
			if (depth[i] >= 0)
				nans += depth[i];

		ans = max(ans, nans);
		cout << " " << ans;

		printf("\n");
	}

	return 0;
}
