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

int n;
int m;
int x;

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		scanf ("%d%d%d", &x, &n, &m);
		if (n > m) swap (n, m);
		int ans = 0;
		if ((n * m) % x == 0) {
			if (x == 1) ans = 1; else
			if (x == 2)	ans = 1; else
			if (x == 3) {
				if (n >= 2 && m >= 3) ans = 1;
			} else 
			if (x == 4) {
				if (n >= 3 && m >= 4) ans = 1;
			} else 
			if (x == 5) {
				if (n >= 3 && m >= 5) ans = 1;
			} else 
			if (x == 6) {
				if (n >= 4 && m >= 6) ans = 1;
			} else {
				ans = 0;
			}
		}	
		cout << "Case #" << it << ": " << (ans ? "GABRIEL" : "RICHARD");
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}