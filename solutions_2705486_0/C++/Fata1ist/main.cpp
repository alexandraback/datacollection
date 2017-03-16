#pragma comment(linker, "/STACK:67108864")

#include <iostream>
#include <fstream> 
#include <cstdio>
#include <vector>
#include <deque>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <cassert>
#include <complex>
#include <bitset>
#include <map>
#include <set>
#include <ctime>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for(int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for(int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;

const long double pi = 3.1415926535897932384626433832795;
const long double eps = 0.000000001;
const int INF = 1E9;
const int MAXN = 4444;

struct vertex {
	int nxt[26];
	bool t;
	vertex() {
		memset(nxt, -1, sizeof(nxt));
		t = 0;
	};
};

string lib[521196];
vector<vertex> w;

void add(string s) {
	int pos = 0;
	forn(i, s.size()) {
		if (w[pos].nxt[s[i] - 'a'] == -1) {
			w[pos].nxt[s[i] - 'a'] = w.size();
			w.pb(vertex());
		}
		pos = w[pos].nxt[s[i] - 'a'];
	}
	w[pos].t = 1;
}

int t, n, m, ans, nans, len, last;
int dp[MAXN][5];
string s;
int l;

void go(int v, int l, int ll, int wr) {
	if (w[v].t)
		dp[len + l][ll] = min(dp[len][last] + wr, dp[len + l][ll]);

	if (len + l == n)
		return;

	int c = s[len + l] - 'a';
	if (w[v].nxt[c] != -1)
		go(w[v].nxt[c], l + 1, min(4, ll + 1), wr);

	if (ll == 4) { //pravo na oshibku
		forn(i, 26) 
			if ((s[len + l] - 'a' != i) && w[v].nxt[i] != -1) //ne tot symbol
				go(w[v].nxt[i], l + 1, 0, wr + 1);
	}
}

int main() {

	m = 521196;
	ifstream iss("dict.txt");
	w.pb(vertex()); //root
	forn(i, m) {
		iss >> s;	
		add(s);
	}

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	cin >> t;
	forn(ii, t) {
		cout << "Case #" << ii + 1 << ": ";

		cin >> s;
		n = s.size();

		forn(i, n + 1)
			forn(j, 5)
				dp[i][j] = INF;
		dp[0][4] = 0;
		forn(i, n)
			forn(j, 5)
				if (dp[i][j] < INF) {
					len = i;
					last = j;
					go(0, 0, last, 0); //recursively
				}

		ans = INF;
		forn(j, 5)
			ans = min(ans, dp[n][j]);
		cout << ans << '\n';
	}

    return 0;
}