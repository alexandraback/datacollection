// Problem C. BFFs
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n, x, ans = 0;
		scanf("%d", &n);
		vector<int> a;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			a.push_back(x - 1);
		}

		for (int t = 0; t < (1 << n); t++) {
			vector<int> s;
			for (int i = 0; i < n; i++)
				if (t & (1 << i)) s.push_back(i);
			if (s.size() <= ans) continue;
			do {
				bool ok = true;
				int m = s.size();
				for (int i = 0; i < s.size(); i++) {
					int u = s[i], v1 = s[(i + 1) % m], v2 = s[(i - 1 + m) % m];
					if (a[u] != v1 && a[u] != v2) {
						ok = false;
						break;
					}
				}
				if (ok) {
					ans = s.size();
					break;
				}
			} while (next_permutation(s.begin(), s.end()));
		}

		printf("Case #%d: %d\n", ti, ans);
	}

	return 0;
}
