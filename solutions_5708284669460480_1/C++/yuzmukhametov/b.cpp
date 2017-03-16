#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)((x).size()))
#define rep(i, N) for (int i = 0; i < N; ++i)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();++it)
typedef long long lint;
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;

int K, L, S;
string Ke, Ll;
char Str[1000];
//double ans = 0.0;
//double mx = 0.0;
//double all = 0.0;

bool eq(int k) {
	int start = k + 1 - sz(Ll);
	for (int i = 0; i < sz(Ll); ++i) {
		if (Ll[i] != Str[start + i]) {
			return false;
		}
	}
	return true;
}

bool eq(int k, string &p) {
	if (sz(p) < sz(Ll)) {
		return false;
	}
	int start = k + 1 - sz(Ll);
	for (int i = 0; i < sz(Ll); ++i) {
		if (Ll[i] != p[start + i]) {
			return false;
		}
	}
	return true;
}

pair<double, double> dp[110][110][110];
bool mark[110][110][110];

bool isPrefix(string &foo, string &foobar) {
	if (sz(foo) > sz(foobar)) return false;
	for (int i = 0; i < sz(foo); ++i) {
		if (foo[i] != foobar[i]) {
			return false;
		}
	}
	return true;
}


int calc_pref(string &t) {
	for (int i = 0; i <= sz(t); ++i) {
		string t1 = t.substr(i);
		if (isPrefix(t1, Ll)) {
			return sz(t1);
		}
	}
	return 0;
}


pair<double, double> rec(int k, int cum, int pref) {
	if (mark[k][cum][pref]) {
		return dp[k][cum][pref];
	}

	if (k == S) {
		//ans += cum;
		//mx = max(cum, mx);
		//all = all + 1;
		mark[k][cum][pref] = true;
		return dp[k][cum][pref] = mp(cum, cum);
	} else {

		string p(Ll.begin(), Ll.begin() + pref);

		double res1 = 0.0;
		double res2 = 0.0;
		for (int i = 0; i < sz(Ke); ++i) {
			string t = p  + (char)Ke[i];

			Str[k] = Ke[i];
			int add = 0;
			int npref = calc_pref(t);
			//if (k + 1 >= sz(Ll) && eq(k)) {
			if (npref == sz(Ll)) {
				add = 1;
			}
			pair<double, double> tt = rec(k + 1, cum + add, npref);
			res1 += tt.first;
			res2 = max(res2, tt.second);
		}
		mark[k][cum][pref] = true;
		return dp[k][cum][pref] = mp(res1, res2);
	}
}

void solve(int num) {
	memset(mark, false, sizeof(mark));
	//ans = 0.0;
	//mx = 0.0;
	//all = 0.0;
	cin >> K >> L >> S;
	cin >> Ke >> Ll;
	//double q = pow(sz(Ke), S);
	//all = pow(sz(Ke), S);
	pair<double, double> t = rec(0, 0, 0);
	double ans = t.first;
	double mx = t.second;
	//cout << all << endl;
	//cout << q << endl;
	//cout << mx << endl;
	//cout << ans << endl;
	//ans /= all;
	for (int i = 0; i < S; ++i) {
		ans /= sz(Ke);
	}
	ans = mx - ans;
	printf("Case #%d: %0.12lf\n", num, ans);
}

int main() {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int tst;
	cin >> tst;
	for (int i = 1; i <= tst; ++i) {
		solve(i);
	}
	return 0;
}