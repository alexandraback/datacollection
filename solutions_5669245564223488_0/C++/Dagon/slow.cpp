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

const ll mod = 1e9 + 7;

const int nmax = 2000;

string s[nmax];

vi g[nmax];
int type[nmax];
int was[nmax];
int cnt[nmax];

string cur = "";

ll go(int k, int n) {
	/*cerr << "cnt: ";
	for (char ch = 'a'; ch <= 'd'; ch++)
		cerr << cnt[ch] << ' '; cerr << endl;
	cerr << k << ' ' << n << ' ' << cur << endl;*/
	if (k == n)
		return 1;
	ll ans = 0;
	rep(I, n) {
		string s = ::s[I];
		if (was[I] == 0) {
			was[I] = 1;
			string tmp = cur;
			bool kpyto = true;
			rep(i, sz(s))
				if (cnt[s[i]] == 0 || cur[sz(cur) - 1] == s[i]) {
					cur += s[i];
					cnt[s[i]]++;
				} else {
					rep(j, i)
						cnt[s[j]]--;
					kpyto = false;
					break;
				}
			if (kpyto) {
				ans += go(k + 1, n);
				rep(i, sz(s))
					cnt[s[i]]--;
			}
			cur = tmp;
			was[I] = 0;
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	rep(I, T) {
		cerr << I << endl;
		int n;
		cin >> n;
		rep(i, n)
			cin >> s[i];
		cout << "Case #" << I + 1 << ": " << go(0, n) << endl;
	}
	return 0;
}
