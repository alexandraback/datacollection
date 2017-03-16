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
#define INF                     (2000000000)

#ifdef _DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

int c[255];
int cc[11];
string d[10] = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

bool isW(string s) {
	FOR(i, 0, s.size()) {
		if (c[s[i]] <= 0)
			return false;
	}
	return true;
}

void solve(int t) {
	CLEAR(c, 0);
	CLEAR(cc, 0);
	cout << "Case #" + to_string(t) + ": ";
	string s;
	cin >> s;
	FOR(i, 0, s.size()) {
		c[s[i]]++;
	}

	while (c['Z'] > 0) {
		cc[0]++;
		FOR(j, 0, d[0].size()) {
			c[d[0][j]]--;
		}
	}

	while (c['W'] > 0) {
		cc[2]++;
		FOR(j, 0, d[2].size()) {
			c[d[2][j]]--;
		}
	}

	while (c['U'] > 0) {
		cc[4]++;
		FOR(j, 0, d[4].size()) {
			c[d[4][j]]--;
		}
	}

	while (c['X'] > 0) {
		cc[6]++;
		FOR(j, 0, d[6].size()) {
			c[d[6][j]]--;
		}
	}

	while (c['G'] > 0) {
		cc[8]++;
		FOR(j, 0, d[8].size()) {
			c[d[8][j]]--;
		}
	}

	FOR(i, 0, 10) {
		FOR(j, 0, cc[i])
			cout << i;
		while (isW(d[i])) {
			cout << i;
			FOR(j, 0, d[i].size()) {
				c[d[i][j]]--;
			}
		}
	}
	FOR(i, 0, 255)
		if (c[i] != 0)
			throw - 1;
	cout << endl;
}

int main() {
	freopen("A-large.in","r",stdin);
	freopen("Cl.out","w",stdout);
	int t;
	cin >> t;
	//t = 1;
	FOR(i, 0, t) {
		solve(i+1);
	}
	return 0;
}
