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

int tx[100], ty[100];

int matr[100][100];
int w[100][100];

int make(int h) {
	fill(w, 0);

	rep(i, n)
	if (!tx[i])
		rep(j, m)
			w[i][j] = 1;

	rep(j, m)
	if (!ty[j])
		rep(i, n)
			w[i][j] = 1;

	rep(i, n) rep(j, m) {
		if (matr[i][j] == h) {
			tx[i] = 1;
			ty[j] = 1;
		}
		if (matr[i][j] <= h)
			if (!w[i][j])
				re 0;
	}
	re 1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc;
	cin >> tc;
	rep(tt, tc) {
		cout << "Case #" << tt + 1 << ": ";

		cin >> n >> m;
		rep(i, n) rep(j, m)
			cin >> matr[i][j];

		fill(tx, 0);
		fill(ty, 0);

		int g = 1;
		for (int h = 100; h >= 1; h--) {
			if (!make(h)) {
				cout << "NO" << endl;
				g = 0;
				break;
			}
		}

		if (g)
			cout << "YES" << endl;
	}

	re 0;
}
