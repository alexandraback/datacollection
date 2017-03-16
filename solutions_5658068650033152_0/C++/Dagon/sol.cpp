#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <deque>
#include <bitset>

#define sqr(x) ((x) * (x))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define y0 ywuerosdfhgjkls
#define y1 hdsfjkhgjlsdfhgsdf
#define j1 j924
#define j0 j2834
#define sqrt(x) (sqrt(abs(x)))
#define re return
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = ((n) - 1); i >= 0; i--)
#define fill(a, x) memset(a, x, sizeof(a))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef double D;
typedef vector <string> vs;

template <class T> inline T abs(T a) {
		return a > 0 ? a : -a;
}

int n;
int m;
int k;

int grid[20][20];
int w[20][20];

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

int MASK;
int dfs(int i, int j) {
	w[i][j] = 1;
	int ans = 1;
	if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
		ans =  0;
	rep(k, 4) {
		int I = i + dx[k];
		int J = j + dy[k];
		if (grid[I][J] == 0 && I >= 0 && J >= 0 && I < n && J < m && w[I][J] == 0) {
			int tmp = dfs(I, J);
			if (tmp == 0)
				ans = 0;
			if (ans)
				ans += tmp;	
		}
	}	
	re ans;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cin >> n >> m >> k;
		int ans = n * m;
		rep(mask, (1 << (n * m))) {
			MASK = mask;
			fill(grid, 0);
			int enc = __builtin_popcount(mask);
			rep(i, n)
				rep(j, m)
					if (mask & (1 << (i * m + j)))
						grid[i][j] = 1;
			fill(w, 0);
			rep(i, n)
				rep(j, m)
					if (!grid[i][j] && !w[i][j]) {
						int tmp = dfs(i, j);
						enc += tmp;
					}
			
			if (enc >= k) {
				ans = min(ans, __builtin_popcount(mask));
			}
		}
		cerr << I << endl;
		cout << "Case #" << I + 1 << ": " << ans << endl;
	}
	return 0;
}
