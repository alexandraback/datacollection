#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 110;
const int64 MOD = INF + 7;


int64 fact[MAXN];


int n;
string s[MAXN];


void precalc() {
	forn(i, MAXN)
		if (i == 0)
			fact[i] = 1;
		else
			fact[i] = fact[i - 1] * i % MOD;
}


void read() {
	cin >> n;
	forn(i, n)
		cin >> s[i];
}


int u[26];
vector<pair<char, char> > a;


int64 solve() {
	memset(u, 0, sizeof u);
	forn(i, n)
		forn(j, s[i].length())
			++u[s[i][j] - 'a'];
	forn(i, n) {
		int l = 0;
		while (l < (int)s[i].length() && s[i][0] == s[i][l])
			++l;

		int r = (int)s[i].length() - 1;
		while (r >= 0 && s[i].back() == s[i][r])
			--r;

		if (s[i][0] == s[i].back() && r != -1)
			return 0;

		for (int j = l; j <= r; ++j) {
			int rj = j;
			while (rj + 1 <= r && s[i][j] == s[i][rj + 1])
				++rj;

			if (rj - j + 1 != u[s[i][j] - 'a'])
				return 0;

			j = rj;
		}
	}

	a.clear();
	forn(i, n)
		a.push_back(mp(s[i][0], s[i].back()));

	int64 ans = 1;
	forn(tp, 2) {
		for (char c = 'a'; c <= 'z'; ++c) {
			vector<int> left, right, both, other;
			forn(i, a.size())
				if (a[i].fs == c && a[i].sc == c)
					both.push_back(i);
				else if (a[i].fs == c)
					left.push_back(i);
				else if (a[i].sc == c)
					right.push_back(i);
				else
					other.push_back(i);

			if (left.size() + right.size() + both.size() > 1) {
				if (left.size() > 1 || right.size() > 1)
					return 0;

				if (both.empty() && tp == 0)
					continue;

				char left_char = right.empty() ? c : a[right[0]].fs;
				char right_char = left.empty() ? c : a[left[0]].sc;
				if (left_char == right_char && left_char != c)
					return 0;
				ans = ans * fact[both.size()] % MOD;

				vector<pair<char, char> > na;
				na.push_back(mp(left_char, right_char));
				forn(i, other.size())
					na.push_back(a[other[i]]);
				a = na;
			}
		}
	}
	ans = ans * fact[a.size()] % MOD;

	return ans;
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	precalc();

	int ts;
	cin >> ts;
	forn(tt, ts) {
		cerr << "Case #" << tt + 1 << "..." << endl;
		read();
		printf("Case #%d: ", tt + 1);
		cout << solve() << endl;
	}
	cerr << "Finish." << endl;

	return 0;
}
