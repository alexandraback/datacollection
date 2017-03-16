#pragma comment(linker, "/STACK:67108864")

#include <iostream>
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
const int MAXN = 111;

int t, n, m, a[MAXN][MAXN];
int mx;
bool f;

int main() {

	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	
	scanf("%d\n", &t);
	forn(ii, t) {
		cout << "Case #" << ii + 1 << ": ";
		scanf("%d %d", &n, &m);
		f = 1;

		forn(i, n)
			forn(j, m)
				scanf("%d", &a[i][j]);
				
		forn(i, n)
			forn(j, m) {
				mx = a[i][j];
				forn(k, m)
					mx = max(mx, a[i][k]);
				if (mx == a[i][j])
					continue;

				mx = a[i][j];
				forn(k, n)
					mx = max(mx, a[k][j]);
				if (mx > a[i][j]) {
					f = 0;
					break;
				}
			}
		cout << (f ? "YES" : "NO") << '\n';
	}

    return 0;
}