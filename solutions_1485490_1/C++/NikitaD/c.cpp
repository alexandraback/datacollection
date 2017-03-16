
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (i = 0; i < (int)(n); ++i)
#define sz(v) ((v).size())
#define all(v) (v).begin(), (v).end()
#define sqr(x) ((x)*(x))
#define updMax(a, b) ((a) = max((a), (b)))
#define updMin(a, b) ((a) = min((a), (b)))

const int maxn = 100 + 5;

ll a[maxn];
int A[maxn];
ll b[maxn];
int B[maxn];

ll d[maxn][maxn];
int n, m;

ll f(int i1, int i2, ll t1, ll t2)
{
	if (i1 == n || i2 == m)
		return 0;
	if (t1 != 0 && t2 != 0) {
		cout << "Error ";
		return 0;
	}
	if (t1 == 0 && t2 == 0) {
		if (d[i1][i2] == -1) {
			if (A[i1] == B[i2]) {
				if (a[i1] < b[i2])
					d[i1][i2] = a[i1] + f(i1 + 1, i2, 0, a[i1]);
				else if (a[i1] > b[i2])
					d[i1][i2] = b[i2] + f(i1, i2 + 1, b[i2], 0);
				else
					d[i1][i2] = a[i1] + f(i1 + 1, i2 + 1, 0, 0);
			} else {
				ll f1 = f(i1 + 1, i2, 0, 0);
				ll f2 = f(i1, i2 + 1, 0, 0);
				d[i1][i2] = max(f1, f2);
				//d[i1][i2] = max(f(i1 + 1, i2, 0, 0), f(i1, i2 + 1, 0, 0));				
			}
		}
		return d[i1][i2];
	} else if (t1 != 0) {
		if (A[i1] != B[i2]) {
			return max(f(i1, i2 + 1, t1, 0), f(i1 + 1, i2, 0, 0));
		} else {
			if (a[i1] - t1 < b[i2])
				return a[i1] - t1 + f(i1 + 1, i2, 0, a[i1] - t1);
			else if (a[i1] - t1 == b[i2])
				return a[i1] - t1 + f(i1 + 1, i2 + 1, 0, 0);
			else if (a[i1] - t1 > b[i2])
				return b[i2] + f(i1, i2 + 1, t1 + b[i2], 0);
		}
	} else if (t2 != 0) {
			if (A[i1] != B[i2]) {
			return max(f(i1 + 1, i2, 0, t2), f(i1, i2 + 1, 0, 0));
		} else {
			if (a[i1] < b[i2] - t2)
				return a[i1] + f(i1 + 1, i2, 0, t2 + a[i1]);
			else if (a[i1] == b[i2] - t2)
				return a[i1] + f(i1 + 1, i2 + 1, 0, 0);
			else if (a[i1] > b[i2] - t2)
				return b[i2] - t2 + f(i1, i2 + 1, b[i2] - t2, 0);
		}
	}
}

void solve()
{
	cin >> n >> m;
	int i, j;
	forn(i, n) {
		cin >> a[i] >> A[i];
	}
	forn(i, m) {
		cin >> b[i] >> B[i];
	}
	memset(d, -1, sizeof(d));
	ll res = f(0, 0, 0, 0);
	cout << res;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ios::sync_with_stdio(false);

	int t, test;
	cin >> t;
	forn(test, t) {
		cout << "Case #" << test + 1 << ": ";
		solve();
		cout << "\n";
	}


	return 0;
}