#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

int v[MAXN];
bool used[MAXN];
int twin[MAXN];

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int z = 1; z <= t; z++) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
		}
		memset(twin, 0, sizeof(twin));
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (v[i] == j && v[j] == i) {
					twin[i] = twin[j] = 1;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			memset(used, false, sizeof(used));
			int p = i;
			int actual = i;
			int partial = 1;
			while (v[actual] != p) {
				if (used[v[actual]]) {
					if (v[v[actual]] == actual) {
						twin[v[actual]] = max(twin[v[actual]], partial - 1);
					}
					partial = 0;
					break;
				}
				actual = v[actual];
				used[actual] = true;
				partial++;
			}
			ans = max(ans, partial);
		}
		int acc = 0;
		for (int i = 1; i <= n; i++) {
			//cout << "twin[" << i << "]" << twin[i] << endl;
			acc += twin[i];
		}
		ans = max(ans, acc);
		cout << "Case #" << z << ": " << ans << endl;
	}
	return 0;
}
