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

ld dp[2000][2000];

ld prob(int n, int k, int y, int l, int r) {
	if (l + r == n) {
		if (l >= y) {
			dp[l][r] = 1.0;
		} else {
			dp[l][r] = 0.0;
		}
		re dp[l][r];
	}
	if (dp[l][r] >= -0.5) {
		re dp[l][r];
	}
	if (l == k) {
		dp[l][r] = prob(n, k, y, l, r + 1);
		re dp[l][r];
	}
	if (r == k) {
		dp[l][r] = prob(n, k, y, l + 1, r);
		re dp[l][r];
	}
	dp[l][r] = 0.5 * (prob(n, k, y, l + 1, r) + prob(n, k, y, l, r + 1));
	re dp[l][r];
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		int n, x, y;
		cin >> n >> x >> y;
		int k = 1;
		int s = 0;
		while (1) {
			if (n >= k) {
				n -= k;
			} else {
				if (abs(x) + y < s) {
					printf("Case #%d: %.10lf\n", I + 1, 1.0);
					break;
				} else if (abs(x) + y > s) {
					printf("Case #%d: %.10lf\n", I + 1, 0.0);
					break;
				} else {
					if (x == 0) {
						printf("Case #%d: %.10lf\n", I + 1, 0.0);
						break;
					} else {
						y += 1;
						rep(i, n) {
							rep(j, n) {
								dp[i][j] = -1;
							}
						}
						printf("Case #%d: %.10lf\n", I + 1, (double)prob(n, k / 2, y, 0, 0));
						break;
					}
				}
			}
			s += 2;
			k += 4;
		}
	}
	return 0;
}
