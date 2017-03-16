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

int a[200];

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cin >> n;
		int s = 0;
		rep(i, n) {
			cin >> a[i];
			s += a[i];
		}
		cout << "Case #" << I + 1 << ":";
		rep(i, n) {
			double l = 0.0, r = 1.0;
			rep(J, 50) {
				double c = (l + r) / 2.0;
				double p = a[i] + c * s;
				double q = 1.0 - c;
				bool kpyto = true;
				rep(j, n) {
					if (j != i) {
						if (a[j] > p)
							continue;
						if (q < (p - a[j]) / (D)s) {
							kpyto = false;
							break;
						}
						q -= (p - a[j]) / (D)s;
					}
				}
				if (kpyto)
					l = c;
				else
					r = c;
			}
			printf(" %.10lf", r * 100.0);
		}
		printf("\n");
	}
	return 0;
}
