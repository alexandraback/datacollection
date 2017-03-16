#include <iostream>
#include <cstring>

#define rep(i, s, t) for (int i = s; i <= t; i++)
using namespace std;

#define N 100
#define NO cout << "NO\n"; goto out
#define YES cout << "YES\n"; goto out

int a[N][N];
int mxi[N], mxj[N];

using namespace std;

int main() {
	int T;
	cin >> T;
	rep (ca, 1, T) {
		int n, m;
		cin >> n >> m;
		cout << "Case #" << ca << ": ";
		memset(mxi, 0, sizeof(mxi));
		memset(mxj, 0, sizeof(mxj));
		rep (i, 1, n) {
			rep (j, 1, m) {
				cin >> a[i][j];
				mxi[i] = max(mxi[i], a[i][j]);
				mxj[j] = max(mxj[j], a[i][j]);
			}
		}
		rep (i, 1, n) {
			rep (j, 1, m) {
				if (a[i][j] < mxi[i] && a[i][j] < mxj[j]) {
					NO;
				}
			}
		}
		YES;
out:
		continue;
	}
	return 0;
}
