#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pi 3.14159265
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define MEM(x, y) memset(x, y, sizeof(x))
#define round(x) x + 0.5
using namespace std ;

int ans[51][51];
ll maxi[55];

int main() {
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int tc;
	cin >> tc;
	for (int t = 1; t <= tc; t++) {
		MEM(ans, 0);
		cout << "Case #" << t << ": ";
		int b, m;
		cin >> b >> m;
		
		if (( 1<<(b -2)) < m) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << "POSSIBLE\n";
		ll arr[55] = {0}, tot = 0;
		if (m >= 1) {
			ans[1][b] = 1;
			arr[1] = 1;
			tot = 1;
		}
		if (m >= 2 && b > 2) {
			ans[1][2] = 1;
			ans[2][b] = 1;
			arr[2] = 1;
			tot = 2;
		}
		if (m > 2) {
			int curr = 2;
			while (tot < m) {
				curr++;
				ans[curr][b] = 1;
				for (int i = curr - 1; i > 0; i--) {
					if (arr[i] + tot <= m) {
						ans[i][curr] = 1;
						tot += arr[i];
						arr[curr] += arr[i];
					}
				}
			}
		}
		
		for (int i = 1; i <= b; i++) {
			for (int j = 1; j <= b; j++) {
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	
	return 0;
}