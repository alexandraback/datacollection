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
#include <cassert>

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

int n;
int m;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		int k, c, s;
		cin >> k >> c >> s;
		vector<ll> res;
		set<int> all;
		for (int i = 0; i < k; i += c) {
			ll cur = 0;
			for (int j = 0; i + j < k && j < c; j++)
				cur = cur * k + (i + j);
			res.pb (cur + 1);
			for (int j = 0; j < c; j++) {
				all.insert (cur % k);
				cur /= k;
			}
		}
		assert (sz (all) == k);
		cout << "Case #" << it << ": ";
		if (sz (res) > s) cout << "IMPOSSIBLE"; else
		for (int i = 0; i < sz (res); i++) cout << res[i] << " ";
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}