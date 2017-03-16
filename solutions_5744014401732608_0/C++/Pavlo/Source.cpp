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

int n;
LL m;
int a[100][100];

void solve(int t) {
	cout << "Case #" + to_string(t) + ": ";
	cin >> n >> m;
	CLEAR(a, 0);
	FOR(i, 0, n)
		FOR(j, i + 1, n) {
		a[i][j] = 1;
	}
	LL s = (1ll << (n - 2));
	if (m > s) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	LL k = (1ll << (n - 3));
	FOR(i, 1, n) {
		if (k>0 && s - k >= m) {
			//cout << i+1 << " " << k << endl;
			s -= k;
			a[0][i] = 0;
		}
		k/=2;
	}
	if (s != m) {
		throw - 1;
	}
	FOR(i, 0, n) {
		FOR(j, 0, n)
			cout << a[i][j];
		cout << endl;
	}
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("Bs.out","w",stdout);
	int t;
	cin >> t;
	FOR(i, 0, t) {
		solve(i+1);
	}
	return 0;
}
