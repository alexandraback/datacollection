#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <ctime>

using namespace std;

const int MAXN = 10100;
const int MAXE = 100;

int v[MAXN];

long long bestans[MAXN][MAXE];

void solve() {
	int E, r, n;
	scanf("%d%d%d", &E, &r, &n);
	r = min(r, E);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);

	memset(bestans, 255, sizeof(bestans));
	bestans[0][E] = 0;
	for (int i = 0; i < n; i++)
		for (int curE = 0; curE <= E; curE++) {
			if (bestans[i][curE] == -1)
				continue;

			for (int sub = 0; sub <= curE; sub++) {
				bestans[i + 1][min(E, curE - sub + r)] =
						max(bestans[i + 1][min(E, curE - sub + r)],
								bestans[i][curE] + sub * v[i]);
			}
		}

	long long ans = 0;
	for (int i = 0; i <= E; i++)
		ans = max(ans, bestans[n][i]);
	cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("B_input.txt","r", stdin);
	freopen("B_output.txt","w", stdout);
#endif
	int testnum;
	scanf("%d\n", &testnum);
	for (int i = 0; i < testnum; i++)
	{
		printf("Case #%d: ", i + 1);
		solve();
	}
}
