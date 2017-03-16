#include <bits/stdc++.h>

#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ld long double

using namespace std;

const int nm = 110;

int n;
map<int, int> dem;

void solve(int test) {
	printf("Case #%d: ", test);
	scanf("%d", &n);
	dem.clear();
	for (int i = 1; i < n + n; ++i) {
		for (int j = 1; j <= n; ++j) {
			int x;
			scanf("%d", &x);
			dem[x]++;
		}
	}
	int d = 0;
	for(map<int, int>::iterator it = dem.begin(); it != dem.end(); it++)
		if (it->second & 1) {
			d++;
			if (d < n)
				printf("%d ", it->first);
			else
				printf("%d\n", it->first);
		}
}

int main() {
#ifdef LOCAL
	freopen("B-large (1).in", "r", stdin);
//	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i)
		solve(i);
}

