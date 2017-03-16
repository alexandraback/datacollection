#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>

using namespace std;

unsigned long long B, M, C;
int g[55][55];

void solve(int v) {
	if (M == 0) return;
	if (v == B) {
		M--;
	}
	for (int k = v+1; k <= B && M > 0; k++) {
		g[v][k]	= 1;
		solve(k);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL), cout.precision(15);
	int T; cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> B >> M;
		C = (B-2)*(B-1);
		C /= 2;
		C += 1;
		if (M > C) {
			cout << "Case #"<< t <<": IMPOSSIBLE\n";
			continue;
		}
		memset(g, 0, sizeof(g));
		solve(1);
		cout << "Case #"<< t <<": POSSIBLE\n";
		for (int i = 1; i <= B; i++) {
			for (int k = 1; k <= B; k++) {
				cout << g[i][k] << (k == B ? "\n" : "");
			}
		}
	}

	return 0;
}
