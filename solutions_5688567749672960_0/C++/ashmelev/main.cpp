#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <sstream>
#include <cstring>
#include <numeric>
#include <ctime>

#define re return
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int) (x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define spc(i,n) " \n"[i == n - 1]

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;

template<class T> T abs(T x) { return x > 0 ? x : -x;}

int m;
int n;

string s;
ll st10[20];

ll getfull(int k) {
	ll ans = 0;
	if (k == 1)
		re 8;
	rep(i, k)
		ans += 9 * st10[min(i, k - i - 1)];
	re ans;
}

ll getans(string s) {
	if (s[sz(s) - 1] == '0') {
		ll o;
		stringstream sin(s), sout;
		sin >> o;
		o--;
		sout << o;
		re 1 + getans(sout.str());
	}

	ll ans = 0;
	for (int i = 1; i < sz(s); i++)
		ans += getfull(i) + 1;

	ll t1 = 0;
	ll t2 = 1;

	s[0]--;

	rep(i, sz(s)) {
		t1 += (s[i] - 48) * st10[sz(s) - 1 - i];
		t2 += (s[i] - 48) * st10[min(i, sz(s) - 1 - i)];
	}

	ans += min(t1, t2);
	re ans;
}

int main() {
#ifdef LOCAL_BOBER
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc;
	cin >> tc;
	st10[0] = 1;
	for (int i= 1; i < 20; i++)
		st10[i] = st10[i - 1] * 10;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";
		cin >> s;
		cout << getans(s)+1 << endl;
	}

	re 0;
}
