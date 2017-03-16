#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

int DFS(const vector <vector <int> > &gr, int v, int f) {
	int ans = 0;
	for (int i = 0; i < gr[v].size(); i++)
		if (gr[v][i] != f)
			ans = max(ans, DFS(gr, gr[v][i], f) + 1);
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		int n;
		cin >> n;
		vector <int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			arr[i]--;
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			int cur = 1;
			int idx = i;
			unordered_map <int, int> f;
			while (true) {
				if (f.count(idx)) {
					ans = max(ans, cur - f[idx]);
					break;
				}
				f[idx] = cur++;
				idx = arr[idx];
			}
		}

		vector <vector <int> > gr(n);
		for (int i = 0; i < n; i++)
			gr[arr[i]].push_back(i);
		int cnt = 0;
		for (int i = 0; i < n; i++)
			if (arr[arr[i]] == i) {
				int cur = DFS(gr, i, arr[i]) + DFS(gr, arr[i], i) + 2;
				cnt += cur;
			}
		ans = max(ans, cnt / 2);
		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}