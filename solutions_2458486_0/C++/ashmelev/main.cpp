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

int scol[201];
int tcol[201][201];
int t[200];
int table[1 << 20];
int next[1 << 20];

int get(int mask, int c) {
	int ans = scol[c];
	rep(i, n)
	if (mask & (1 << i)) {
		if (t[i] == c)
			ans--;
		ans += tcol[i][c];
	}
	re ans;
}

int getans(int mask) {
	int &ans = table[mask];
	if (ans != -1)
		re ans;
	if (mask == (1 << n) - 1) {
		ans = 1;
		re 1;
	}

	ans = 0;
	rep(i, n) {
		if (mask & (1 << i))
			continue;
		int o = get(mask, t[i]);
		if (o >= 1)
			if (getans(mask + (1 << i))) {
				ans = 1;
				next[mask] = i;
				re 1;
			}
	}
	ans = 0;
	re 0;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";
		fill(scol, 0);
		int k;
		cin >> k >> n;
		rep(i, k) {
			int x;
			cin >> x;
			x--;
			scol[x]++;
		}

		fill(tcol, 0);
		rep(i, n) {
			int ck;
			cin >> t[i] >> ck;
			t[i]--;
			rep(j, ck) {
				int x;
				cin >> x;
				x--;
				tcol[i][x]++;
			}
		}

		fill(table, -1);
		int o = getans(0);
		if (o == 0) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			int cm = 0;
			while (cm != (1 << n) - 1) {
				int o = next[cm];
				cm += (1 << o);
				cout << o + 1 << ' ';
			}
			cout << endl;
		}
	}

	re 0;
}
