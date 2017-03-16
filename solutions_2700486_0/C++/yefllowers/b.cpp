#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<queue>
using namespace std;
 
#define rep(i,n) for(int i = 0; i < (int)n; i++)
#define FOR(i,n,m) for(int i = (int)n; i <= (int)m; i++)
#define FOD(i,n,m) for(int i = (int)n; i >= (int)m; i--)
#define EACH(i,v) for(__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
 
typedef long long i64;
typedef pair<int, int> PI;
 
#define sz(v) ((i64)(v).size())
#define all(v) (v).begin(),(v).end()
#define bit(n) (1LL<<(i64)(n))
 
#define PB push_back
#define MP make_pair
#define X first
template<class T> void fmax(T &a, const T &b) { if (a < b) a = b; }
template<class T> void fmin(T &a, const T &b) { if (a > b) a = b; }
template<class T> T sqr(const T &a) { return a * a; }

double C2[4444][4444];

int main() {
	rep(i, 4444) {
		C2[i][0] = 1;
		rep(k, i) C2[i][0] /= 2;
		C2[i][i] = C2[i][0];
		FOR(j, 1, i - 1)
			C2[i][j] = (C2[i - 1][j] + C2[i - 1][j - 1]) / 2;
	}
	int CNT;
	cin >> CNT;
	rep(cnt, CNT) {
		int n, x, y;
		cin >> n >> x >> y;
		double ans = 0;
		if (n == 1) {
			if (!x && !y)
				ans = 1.0;
			else
				ans = 0;
		}
		else {
			int m = 1;
			while (2 * (m + 1) * (m + 1) - (m + 1) <= n) m++;
		//	cout << m << endl;
			if (max(x, -x) + y <= m + m - 2)
				ans = 1.0;
			else if (max(x, -x) + y > m + m || 2 * m * m - m == n)
				ans = 0;
			else {
				int w = n - 2 * m * m + m;
				if (y == m + m)
					ans = 0;
				else 
				if (w > m + m && w - m - m >= y + 1)
					ans = 1;
				else
				if (w <= m + m) {
					FOR(k, y + 1, w) ans += C2[w][k];
				}
				else 
				if (w >= m + m) {
					FOR(i, 1, m + m - 1) {
						if (i + m + m - 1 < w) continue;
						if (i >= y + 1)
							ans += C2[w][i];
					}
					int u = w - m - m;
					//cout << "u=" << u << endl;
					double p = C2[m+m][0];
					FOR(i, 1, u) p += C2[i + m + m - 1][i] / 2;
				//	cout << p << ' ' << ans << endl;
					if (u >= y + 1) ans +=p;
					ans += p;
				}
			}
		}
//		cout << "Case #" << cnt+1 << ": ";
//		cout << ans;
//		cout << endl;
		printf("Case #%d: %.7f\n", cnt+1, ans);
	}
}