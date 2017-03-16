//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#define _CRT_SECURE_NO_DEPRECATE
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<complex>
#include<set>
#include<algorithm>
#include <iomanip>

using namespace std;

typedef unsigned long long      ui64;
typedef long long               i64;
typedef long long               LL;
typedef vector<int>             VI;
typedef vector<bool>            VB;
typedef vector<VI>              VVI;
typedef vector<string>          VS;
typedef pair<int, int>           PII;
typedef map<string, int>         MSI;
typedef set<int>                SI;
typedef set<string>             SS;
typedef complex<double>         CD;
typedef vector< CD >            VCD;
typedef map<int, int>            MII;
typedef pair<double, double>     PDD;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000000000000)

#ifdef _DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

int c[111];

bool eq(int x, string s) {
	int l = 0;
	while (x) {
		c[l] = x % 10;
		x /= 10;
		l++;
	}
	while (l < s.length()) {
		c[l] = 0;
		l++;
	}
	if (l != s.length()) {
		return false;
	}

	FOR(i, 0, s.size()) {
		if (s[i] != '?') {
			if (s[i] - '0' != c[l - i - 1])
				return false;
		}
	}
	return true;
}


string ss(LL x, int n) {
	string s = to_string(x);
	while (s.length() < n) {
		s = "0" + s;
	}
	return s;
}

void f(string a, string b) {
	int x = 0, y = INF;
	FOR(i,0,1000)
		if (eq(i, a)) {
			FOR(j, 0, 1000) {
				if (eq(j, b)) {
					if (abs(i - j) < abs(x - y)) {
						x = i;
						y = j;
					}
					if (abs(i - j) == abs(x - y) && (i < x || ( i == x && j<y) )) {
						x = i;
						y = j;
					}
				}
			}
		}
	cout << ss(x,a.length()) << " " << ss(y,a.length()) << endl;
}

LL dp[20][10][10];
pair<LL, LL> pos[20][20][20];

void solve(int t) {
	cout << "Case #" + to_string(t) + ": ";
	string a, b;
	cin >> a >> b;
	//cout << endl << endl;
	//cout << a << " " << b << endl;
	int len = a.size();
	//f(a, b);
	FOR(l, 0, 20)
		FOR(i, 0, 10)
		FOR(j, 0, 10)
		dp[l][i][j] = INF;

	dp[0][0][0] = 0;
	
	//reverse(ALL(a));
	//reverse(ALL(b));
	FOR(l, 1, len + 1) {
		int l1 = 0, r1 = 10;
		int l2 = 0, r2 = 10;
		if (a[l - 1] != '?') {
			l1 = a[l - 1] - '0';
			r1 = l1 + 1;
		}
		if (b[l - 1] != '?') {
			l2 = b[l - 1] - '0';
			r2 = l2 + 1;
		}
		FOR(c1, l1, r1) {
			FOR(c2, l2, r2) {
				FOR(i, 0, 10) {
					FOR(j, 0, 10) 
					if (dp[l - 1][i][j] < INF){
						LL v = dp[l - 1][i][j] * 10 + (c1 - c2);
						pair<LL, LL> p = MP(pos[l - 1][i][j].first * 10 + c1, pos[l - 1][i][j].second * 10 + c2);
						if (v >= 0) {
							if (v < dp[l][c1][c2] || (v==dp[l][c1][c2] && p < pos[l][c1][c2])) {
								dp[l][c1][c2] = dp[l - 1][i][j] * 10 + (c1 - c2);
								pos[l][c1][c2] = p;
							}
						}
					}
				}
			}
		}
	}
	LL ans = INF;
	pair<LL, LL> r = MP(INF, INF);
	FOR(i, 0, 10)
		FOR(j, 0, 10) {
		if (dp[len][i][j] < ans || (dp[len][i][j] == len && pos[len][i][j] < r)) {
			ans = dp[len][i][j];
			r = pos[len][i][j];
		}
	}


	swap(a, b);
	FOR(l, 0, 20)
		FOR(i, 0, 10)
		FOR(j, 0, 10)
		dp[l][i][j] = INF;

	dp[0][0][0] = 0;
	
	FOR(l, 1, len + 1) {
		int l1 = 0, r1 = 10;
		int l2 = 0, r2 = 10;
		if (a[l - 1] != '?') {
			l1 = a[l - 1] - '0';
			r1 = l1 + 1;
		}
		if (b[l - 1] != '?') {
			l2 = b[l - 1] - '0';
			r2 = l2 + 1;
		}
		FOR(c1, l1, r1) {
			FOR(c2, l2, r2) {
				FOR(i, 0, 10) {
					FOR(j, 0, 10) 
						if (dp[l - 1][i][j] < INF) {
						LL v = dp[l - 1][i][j] * 10 + (c1 - c2);
						pair<LL, LL> p = MP(pos[l - 1][i][j].first * 10 + c1, pos[l - 1][i][j].second * 10 + c2);
						if (v >= 0) {
							if (v < dp[l][c1][c2] || (v == dp[l][c1][c2] && p < pos[l][c1][c2])) {
								dp[l][c1][c2] = dp[l - 1][i][j] * 10 + (c1 - c2);
								pos[l][c1][c2] = p;
							}
						}
					}
				}
			}
		}
	}
	FOR(i, 0, 10)
		FOR(j, 0, 10) {
		if (dp[len][i][j] < ans || (dp[len][i][j] == ans && MP(pos[len][i][j].second,pos[len][i][j].first)<r)) {
			ans = dp[len][i][j];
			r = MP(pos[len][i][j].second, pos[len][i][j].first);
		}
	}
	
	//cout << ans << endl;
	cout << ss(r.first,len) << " " << ss(r.second,len) << endl;
	//cout << a << " " << b << endl;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int t;
	cin >> t;
	//t = 1;
	FOR(i, 0, t) {
		solve(i+1);
	}
	return 0;
}
