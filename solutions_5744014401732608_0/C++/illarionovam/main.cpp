#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("ololo.txt", "w", stdout);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int T=1; T<=t; T++) {
		cout << "Case #" << T << ": ";
		int n;
		long long m;
		cin >> n >> m;
		if ((n-2)*(n-1)/2LL + 1 < m) {
			cout << "IMPOSSIBLE\n";
		}
		else {
			cout << "POSSIBLE\n";
			bool a[n+1][n+1];
			for (int i=0; i<=n; i++) {
				for (int j=0; j<=n; j++) {
					a[i][j]=0;
				}
				if (i>=1 && i<=n-1) a[i][n]=1;
			}
			m--;
			for (int i=1; i<=n-1 && m; i++) {
				for (int j=i+1; j<=n-1 && m; j++) {
					a[i][j]=1;
					m--;
				}
			}
			for (int i=1; i<=n; i++) {

				for (int j=1; j<=n; j++) {
					if (j==n&&i!=1&&i!=n) {
                        cout << a[1][i];
					}
					else cout << a[i][j];
				}
				cout << "\n";
			}
		}
	}
	return 0;
}
