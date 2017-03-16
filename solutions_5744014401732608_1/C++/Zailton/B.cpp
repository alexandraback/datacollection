#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,b) FOR(i, 0, b)
#define sz(e) (int)e.size()
#define CLR(x,v) memset (x, v, sizeof x)
#define pb push_back
#define all(e) e.begin(), e.end()

typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 102;
const int INF = 1000000000;

int mat[MAXN][MAXN];

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin>>T;
	FORR (c, T) {
		cout << "Case #" << c+1 << ": ";
		ll B, M;
		cin>>B>>M;
		CLR (mat, 0);
		if (M > (1LL<<(B-2))) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			FOR (i, 1, MAXN) {
				FOR (j, i+1, MAXN) {
					mat[i][j] = 1;
				}
			}
			for (int i = B-3, x = 1; i >= 0; i--, x++) {
				if (M >= (1LL<<i)) {
					M -= (1LL<<i);
					mat[0][x] = 1;
				}
			}
			if (M==1) {
				mat[0][B-1] = 1;
			}
			FORR (i, B) {
				FORR (j, B) {
					cout << mat[i][j];
				} cout << endl;
			}
		}
	}
}
