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
double x[1000];
double y[1000];
int use[1000];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> x[i];
		for (int i = 0; i < n; i++) cin >> y[i];
		sort (x, x + n);
		sort (y, y + n);
		int ans = 0;
		memset (use, 0, sizeof (use));
		for (int i = 0, j = 0; i < n; i++)
			if (x[i] > y[j] + 1e-7) {
				ans++;
				j++;
			}
		int bad = 0;
		memset (use, 0, sizeof (use));
		for (int i = n - 1; i >= 0; i--) {
			int ok = 0;
			for (int j = 0; j < n; j++)
				if (y[j] > x[i] + 1e-7 && !use[j]) {
					use[j] = 1;
					ok = 1;
					break;
				}
			if (!ok) {
				bad++;
				for (int j = 0; j < n; j++)
					if (!use[j]) {
						use[j] = 1;
						break;
					}	
			}
		}	
		cout << "Case #" << it << ": " << ans << " " << bad;
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}