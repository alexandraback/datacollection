#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <cstdio>
#include <vector>
#include <cctype>
#include <string>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

typedef long double LD;
typedef long long LL;

using namespace std;

#define sz(A) (int)(A).size()
#define mp make_pair
#define pb push_back

const int N = 205, M = (1 << 20);

int cnt[N], inside[N][N], dp[M], open[N], now[N], from[M], n;
bool view[M];
vector<int> way[M];

void ans(int v) {
	if (v) {
		ans(from[v]);
		int val = (v ^ from[v]);
		for (int i = 0; i < n; i++)
			if ((1 << i) == val) {
				printf(" %d", i + 1);
				break;
			}
	}
}

vector<int> path(int v) {
	vector<int> res;
	if (v == 0) 
		return res;
	res = path(from[v]);		
	res.pb(v);
	return res;
}

int lex_min(int a, int b) {
	vector<int> p1 = path(a);
	vector<int> p2 = path(b);
	if (p1 < p2)
		return a;
	else
		return b;
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cerr << i << endl;		
		memset(cnt, 0, sizeof(cnt));
		memset(inside, 0, sizeof(inside));
		memset(dp, 0, sizeof(dp));
		memset(view, 0, sizeof(view));

		dp[0] = 1;

		int k;
		cin >> k >> n;
		for (int j = 0; j < k; j++) {
			int key;
			cin >> key;
			cnt[key]++;
		}

		for (int j = 0; j < n; j++) {
			cin >> open[j] >> k;
			for (int q = 0; q < k; q++) {
				int key;
				cin >> key;
				inside[j][key]++;
			}
		}

		for (int w = 0; w < n; w++)
		for (int j = 0; j < M; j++) {
			if (dp[j] && !view[j]) {
				view[j] = 1;

				for (int t = 0; t < N; t++)
					now[t] = cnt[t];

				for (int t = 0; t < n; t++) {
					if (j & (1 << t)) {
						now[ open[t] ]--;
						for (int q = 0; q < N; q++)
							now[q] += inside[t][q];
					}
				}

				for (int t = 0; t < n; t++) {
					if ((j & (1 << t)) == 0) {
						if (now[ open[t] ]) {
							if (!dp[j | (1 << t)]) {
								from[j | (1 << t)] = j;
								way[j | (1 << t)] = way[j];
								way[j | (1 << t)].pb(t);
							}
							else {
								vector<int> new_w = way[j];
								new_w.pb(t);
								if (new_w < way[j | (1 << t)]) {
									way[j | (1 << t)] = new_w;								
									from[j | (1 << t)] = j;
								}
							}
							dp[j | (1 << t)] = 1;
						}
					}
				}
			}
		}

		if (dp[(1 << n) - 1] == 0) {
			printf("Case #%d: IMPOSSIBLE\n", i + 1);
		}
		else {
			int now = (1 << n) - 1;
			printf("Case #%d:", i + 1);
			ans(now);
			puts("");
		}
	}

	return 0;
}
