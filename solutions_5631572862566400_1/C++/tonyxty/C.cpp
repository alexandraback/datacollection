#include <iostream>
#include <cstring>
using namespace std;

int n;
int F[1000];
int flag[1000];
int order[1000];
int queue[1000];

int find_max_with_cp() {
	int ans = 0;
	for (int i = 0; i < n; i++) if (F[F[i]] == i) {	// FFF
		memset(order, 0, n * sizeof(order[0]));
		order[i] = 1;
		int qb = 0, qt = 0;
		for (int j = 0; j < n; j++) if (F[j] == i && j != F[i])
			queue[qt++] = j, order[j] = 2;
		while (qb < qt) {
			int p = queue[qb++];
			int o = order[p];
			for (int j = 0; j < n; j++) if (F[j] == p)
				queue[qt++] = j, order[j] = o + 1;
		}
		int max = 0;
		for (int j = 0; j < n; j++)
			if (order[j] > max) max = order[j];
		ans += max;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> F[i];
			F[i]--;
		}
		for (int i = 0; i < n; i++) {
			flag[i] = i + 1;
			int j = i;
			int l = 1;
			do {
				j = F[j];
				if (flag[j] == i + 1) break;
				flag[j] = i + 1;
				l++;
			} while (j != i);
			if (j == i && l > ans) ans = l;
		}
		int _ = find_max_with_cp();
		if (_ > ans) ans = _;
		cout << "Case #" << t << ": " << ans << endl;
	}
}
