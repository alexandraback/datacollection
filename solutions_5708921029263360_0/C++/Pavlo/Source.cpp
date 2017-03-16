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

int a, b, c, m;
int ab[4][4];
int ac[4][4];
int bc[4][4];
int r[1000];
int ans[1000];

void solve(int t) {
	cout << "Case #" + to_string(t) + ": ";
	cin >> a >> b >> c >> m;
	vector<pair<pair<int, int>,int> >pos;

	FOR(i, 0, a) {
		FOR(j, 0, b) {
			FOR(k, 0, c) {
				pos.push_back(MP(MP(i, j), k));
			}
		}
	}
	int anss = 0;
	int n = pos.size();
	//cout << n << endl;
	FOR(mask, 0, (1 << n)) {
		int q = 0;
		FOR(i, 0, n) {
			if (mask & (1 << i)) {
				q++;
			}
		}
		if (q <= anss) {
			continue;
		}
		CLEAR(ab, 0);
		CLEAR(ac, 0);
		CLEAR(bc, 0);
		int rs = 0;
		FOR(i, 0, n) {
			if (mask & (1 << i)) {
				int ii = pos[i].X.X, jj = pos[i].X.Y, kk = pos[i].Y;
				if (ab[ii][jj] < m && ac[ii][kk] < m && bc[jj][kk] < m) {
					ab[ii][jj]++;
					ac[ii][kk]++;
					bc[jj][kk]++;
					//cout << i << " " << j << " " << k << endl;
					r[rs] = (ii * 100 + jj * 10 + kk);
					rs++;
				}
			}
		}
		if (rs > anss) {
			FOR(i, 0, rs) {
				ans[i] = r[i];
			}
			anss = rs;
		}
	}
	

	cout << anss << endl;
	FOR(i, 0, anss) {
		int x = ans[i];
		cout << x / 100 + 1 << " ";
		x %= 100;
		cout << x / 10 + 1 << " ";
		x %= 10;
		cout << x + 1 << endl;
	}

}

int main() {
	freopen("C-small-attempt1.in","r",stdin);
	freopen("Cs.out","w",stdout);
	int t;
	cin >> t;
	FOR(i, 0, t) {
		solve(i+1);
	}
	return 0;
}
