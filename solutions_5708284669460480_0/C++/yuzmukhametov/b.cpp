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
double ans = 0.0;
double mx = 0.0;
double all = 0.0;

bool eq(int k) {
	int start = k + 1 - sz(Ll);
	for (int i = 0; i < sz(Ll); ++i) {
		if (Ll[i] != Str[start + i]) {
			return false;
		}
	}
	return true;
}

void rec(int k, double cum) {
	if (k == S) {
		//Str[k] = 0;
		//cout << cum << " " << string(Str) << endl;
		ans += cum;
		mx = max(cum, mx);
		all = all + 1;
	} else {
		for (int i = 0; i < sz(Ke); ++i) {
			Str[k] = Ke[i];
			int add = 0;
			if (k + 1 >= sz(Ll) && eq(k)) {
				add = 1;
			}
			rec(k + 1, cum + add);
		}
	}
}

void solve(int num) {
	ans = 0.0;
	mx = 0.0;
	all = 0.0;
	cin >> K >> L >> S;
	cin >> Ke >> Ll;
	//double q = pow(sz(Ke), S);
	rec(0, 0);
	//cout << all << endl;
	//cout << mx << endl;
	//cout << ans << endl;
	ans /= all;
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