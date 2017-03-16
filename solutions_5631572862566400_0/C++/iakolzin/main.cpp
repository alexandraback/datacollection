#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	freopen("inputl.txt", "r", stdin);
	freopen("outputl.txt", "w", stdout);
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
		vector <int> p(n);
		for (int i = 0; i < n; i++)
			p[i] = i;
		int ans = 0;
		do {
			for (int i = 2; i <= n; i++) {
				bool ok = true;
				for (int j = 0; j < i; j++) {
					int li = (j - 1 + i) % i;
					int ri = (j + 1) % i;
					int cur = p[j];
					if (p[li] == arr[cur] || p[ri] == arr[cur]) {}
					else
						ok = false;
				}
				if (ok)
					ans = max(ans, i);
			}
		} while (next_permutation(p.begin(), p.end()));

		cout << "Case #" << t << ": " << ans << endl;
	}
	return 0;
}