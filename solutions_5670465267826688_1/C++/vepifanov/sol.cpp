#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

const int g[4][4] = {
{1, 2, 3, 4},
{2, -1, 4, -3},
{3, -4, -1, 2},
{4, 3, -2, -1}};

int n;
ll m;

int get (char c) {
	re c - 'i' + 2;
}

int mult (int a, int b) {
	int s = 1;
	if (a < 0) {
		s = -s;
		a = -a;
	}
	if (b < 0) {
		s = -s;
		b = -b;
	}
	re s * g[a - 1][b - 1];
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		string s;
		cin >> n >> m >> s;
		if (m > 16) m -= ((m - 16) / 4) * 4;
		int cur = 1;
		string t = "";
		for (int i = 0; i < m; i++)
			t += s;
		n *= m;
		for (int i = 0; i < n; i++)
			cur = mult (cur, get (t[i]));
		int ans = 0;
		if (cur == -1) {
			int a = n, b = -1, tmp = 1;
			for (int i = 0; i < n; i++) {
				tmp = mult (tmp, get (t[i]));
				if (tmp == 2) {
					a = i;
					break;
				}
			}
			tmp = 1;
			for (int i = n - 1; i >= 0; i--) {
				tmp = mult (get (t[i]), tmp);
				if (tmp == 4) {
					b = i;
					break;
				}
			}
			if (a < b) ans = 1;
		}
		cout << "Case #" << it << ": " << (ans ? "YES" : "NO");
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}