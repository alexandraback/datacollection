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

const int N = 100000000;

int n;
int m;

bitset<N> f;
int q[6000000];
int r = 0;

int main () {
	for (int i = 2; i < N; i++)
		if (!f[i]) {
			q[r++] = i;
			if (i <= N / i)
				for (int j = i * i; j < N; j += i)
					f[j] = 1;
		}
	cerr << r << endl;	
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> n >> m; n -= 2;
		cout << "Case #" << it << ": " << endl;
		for (int mask = 0; mask < (1 << n); mask++) {
			int ok = 1;
			vi p;
			for (int base = 2; base <= 10; base++) {
				ll cur = 1;
				for (int i = n - 1; i >= 0; i--)
					cur = cur * base + ((mask >> i) & 1);
				cur = cur * base + 1;	
				int ok2 = 0;
				for (int i = 0; q[i] <= cur / q[i]; i++)
					if (cur % q[i] == 0) {
						p.pb (q[i]);
						ok2 = 1;
						break;
					}
				if (!ok2) {
					ok = 0;
					break;
				}	
			}
			if (ok) {
				printf ("1");
				for (int i = n - 1; i >= 0; i--)
					printf ("%d", (mask >> i) & 1);
				printf ("1");
				for (int i = 0; i < sz (p); i++)
					printf (" %d", p[i]);	
				printf ("\n");
				m--;
				if (!m) break;
			}
		}
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}