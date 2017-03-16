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

template<class T> T abs(T x) {
	return x > 0 ? x : -x;
}

int m;
int n;

typedef pair<ii, vi> box;
typedef vector<box> vbox;

void open(vi &keys, vbox &boxes, int id) {
	int t = boxes[id].fi.se;
	rep(i, sz(keys))
		if (keys[i] == t) {
			keys[i] = keys.back();
			keys.pop_back();
			break;
		}

	rep(i, sz(boxes[id].se))
	{
		keys.pb(boxes[id].se[i]);
	}

	boxes[id] = boxes.back();
	boxes.pop_back();
}

int c1[400];
int c2[400];

void lol(box x) {
	rep(i, sz(x.se))
	{
		c1[x.se[i]]++;
	}
}

vi v;

int matr[200][200];
int cct;

int gi;

int zt;
int ww[200];

int go(int x) {
	ww[x] = zt;
	rep(i, n) {
		if (matr[x][i] == cct) {
			if (i == gi)
				re 1;
			if (ww[i] != zt)
				if (go(i))
					re 1;
		}
	}
	re 0;
}

int check2(vi &keys, vbox &boxes) {
	n = sz(boxes);

	cct++;
	rep(i, n)
	rep(j, n) {
		if (count(all(boxes[i].se), boxes[j].fi.se))
			matr[i][j] = cct;
	}

	rep(i, n)
	if (c1[boxes[i].fi.se]) {
		zt++;
		gi = i;
		if (go(i))
			re i;
	}
	re -1;
}

int check(vi keys, vbox boxes) {
	fill(c1, 0);
	fill(c2, 0);
	rep(i, sz(keys))
		c1[keys[i]]++;
	rep(i, sz(boxes))
		c2[boxes[i].fi.se]++;
	while (sz(boxes) ) {
		int f = 0;

		/*rep(i, sz(boxes))
		cout << boxes[i].fi.fi << ' ' << boxes[i].fi.se << "     ";
		cout << endl;
		rep(i, sz(keys))
		cout << keys[i] << ' ';
		cout << endl;*/

		//cout << c1[2] << ' ' << c2[2] << endl;

		rep(i, sz(boxes))
		{
			int t = boxes[i].fi.se;
			if (c1[t] >= 2 || (c1[t] == 1 && c2[t] == 1)) {
				c1[t]--;
				c2[t]--;
				lol(boxes[i]);
				open(keys, boxes, i);
				f = 1;
				break;
			}
		}

		//cout << "f = " << f << endl;

		if (f)
			continue;

		int id = check2(keys, boxes);

		if (id == -1)
			re 0;
		int t = boxes[id].fi.se;
		lol(boxes[id]);
		open(keys, boxes, id);
		//cout << "c2 = " << c1[2] << endl;
		c1[t]--;
		c2[t]--;
	}
	re 1;
}

void solve(vi keys, vbox boxes) {
	while (sz(boxes) ) {
		sort(all(boxes));
		vi tkeys = keys;
		vbox tboxes = boxes;
		rep(i, sz(boxes))
		{
			if (count(all(keys), boxes[i].fi.se)) {
				int zlo = boxes[i].fi.fi;
				open(keys, boxes, i);
				if (check(keys, boxes)) {
					cout << zlo + 1 << ' ';
					break;
				} else {
					keys = tkeys;
					boxes = tboxes;
				}
			}
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		int tk;
		int n;
		cin >> tk >> n;

		vi vk;
		rep(i, tk) {
			int x;
			cin >> x;
			x--;
			vk.pb(x);
		}

		vbox v;
		rep(i, n) {
			int t, k;
			vi tv;
			cin >> t >> k;
			t--;
			rep(j, k) {
				int x;
				cin >> x;
				x--;
				tv.pb(x);
			}
			v.pb(mp(mp(i, t), tv));
		}

		if (!check(vk, v)) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			solve(vk, v);
			cout << endl;
		}
	}

	re 0;
}
