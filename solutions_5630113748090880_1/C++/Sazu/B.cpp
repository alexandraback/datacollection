#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

int main() {
	ios_base::sync_with_stdio(false);

	int kase =1 ;
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		static int app[2505];
		memset(app, 0, sizeof app);
		fori(i, 0, 2 * n - 1) {
			fori(j, 0, n) {
				int cur;
				cin >> cur;
				app[cur]++;
			}
		}

		vector<int> ans;
		fori(i, 1, 2501) {
			if(app[i]) {
				if(app[i] & 1) {
					ans.push_back(i);
				}
			}
		}

		cout << "Case #" << kase++ << ":";
		for(auto &each : ans) {
			cout << " " << each;
		}
		cout << '\n';
	}

	return 0;
}
