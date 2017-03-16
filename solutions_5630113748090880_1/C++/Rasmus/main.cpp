#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <iterator>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const dbl pi = 3.14159265358979323846;
const int inf = (int) 1e9;
const dbl eps = 1e-9;

const int N = 55;

int a[2 * N][N];
//int b[N][N];
VVI b(N,VI(N));
bool used[2 * N];
int n;

bool check() {
	FOR(i,n) {
		int pr = 0;
		FOR(j,n) {
			if (b[i][j] == 0) {
				continue;
			}
			if (b[i][j] <= pr) {
				return false;
			}
			pr = b[i][j];
		}
		pr = 0;
		FOR(j,n) {
			if (b[j][i] == 0) {
				continue;
			}
			if (b[j][i] <= pr) {
				return false;
			}
			pr = b[j][i];
		}
	}
	FOR(k,2 * n - 1) {
		bool ok = false;
		FOR(i,n) {
			bool t = true;
			FOR(j,n) {
				if (b[i][j] != 0 && b[i][j] != a[k][j]) {
					t = false;
					break;
				}
			}
			if (t) {
				ok = true;
			}
		}

		FOR(j,n) {
			bool t = true;
			FOR(i,n) {
				if (b[i][j] != 0 && b[i][j] != a[k][i]) {
					t = false;
					break;
				}
			}
			if (t) {
				ok = true;
			}
		}
		if (!ok) {
			return false;
		}
	}
	return true;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	int T;
	cin >> T;
	REPE(TT,1,T) {
		cout << "Case #" << TT << ": ";
		cerr << TT << "\n";
		memset(a, 0, sizeof(a));
		//memset(b, 0, sizeof(b));
		b.assign(N,VI(N,0));
		memset(used, false, sizeof(used));

		cin >> n;
		//n = 50;
		FOR(i,2 * n - 1) {
			FOR(j,n) {
				cin >> a[i][j];
				//a[i][j] = i / 2 + j + 1;
			}
		}

		int k = 0;
		int now = 0;
		int add = 1;
		int cnt = 0;
		while(cnt < n - 1) {
			if (add == 1) {
				now = inf;
			} else {
				now = -inf;
			}
			FOR(i,2 * n - 1) {
				if (used[i]) {
					continue;
				}
				if (add == 1) {
					now = min(now, a[i][k]);
				} else {
					now = max(now, a[i][k]);
				}
			}

			VI val;
			FOR(i,2 * n - 1) {
				if (used[i]) {
					continue;
				}
				if (a[i][k] == now) {
					val.pb(i);
				}
			}
			if (val.size() > 2) {
				throw 1;
			}
			if (val.size() < 2) {
				k = n - 1;
				add = -1;
				continue;
			}
			int x = val[0];
			int y = val[1];
			used[x] = true;
			used[y] = true;
			bool go = true;
			FOR(i,n) {
				if (b[k][i] != 0 && b[k][i] != a[x][i] ||
					b[i][k] != 0 && b[i][k] != a[y][i]) {
					go = false;
				}
			}
			if (go) {
				FOR(i,n) {
					b[k][i] = a[x][i];
					b[i][k] = a[y][i];
				}
			}
			if (TT == 37 && n == 8 && k == 1) {
				k = k;
			}
			if (!go || !check()) {
				if (!go) {
					go = true;
					FOR(i,n) {
						if (b[k][i] != 0 && b[k][i] != a[y][i] ||
							b[i][k] != 0 && b[i][k] != a[x][i]) {
							throw 1;
						}
					}
				}
				FOR(i,n) {
					b[k][i] = a[y][i];
					b[i][k] = a[x][i];
				}
			}
			if (!check()) {
				throw 1;
			}
			k += add;
			++cnt;
		}
		int x = 0;
		FOR(i,2 * n - 1) {
			if (!used[i]) {
				x = i;
				break;
			}
		}
		int out = 0;
		FOR(i,n) {
			if (i == k) {
				b[k][i] = a[x][i];
				continue;
			}
			if (b[k][i] != a[x][i]) {
				out = 1;
			}
		}

		if (!check()) {
			throw 1;
		}

		FOR(i,n) {
			if (i) {
				cout << " ";
			}
			if (out == 0) {
				cout << b[i][k];
			} else {
				cout << b[k][i];
			}
		}
		cout << "\n";
	}
    return 0;
}