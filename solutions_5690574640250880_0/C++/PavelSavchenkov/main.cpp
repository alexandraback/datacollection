#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

int n, m;
char a[60][60];
bool sw;

bool solve( int M ) {
	sw = false;
//	int _M = M;   

	forn(i, 60)
		forn(j, 60)
			a[i][j] = '.';

	a[0][0] = 'c';

	if  (M == n * m - 1) {
		forn(i, n)
			forn(j, m)
				if  (i || j)
					a[i][j] = '*';
		return true;
	}

	sw = m < n;
	if  (sw)
		swap(n, m);
	
	if  (n > 2) {
		// m >= 3
		for (int i = n - 1; i >= 2; --i)
			for (int j = 0; j < m; ++j)
				if  (M) {
					a[i][j] = '*';
					--M;

					if  (!M && j != m - 2) {
						return true;
					}

					if  (!M) {
						for (int jj = 0; jj < m; ++jj)
							a[i][jj] = '.';
						M += m - 1;

						for (int ii = i; ii >= 0; --ii)
							if  (M) {
								a[ii][m - 1] = '*';
								--M;

								if  (!M) {
									if  (ii != 1) {
										return true;
									}
									if  (m == 3) {
										assert(i == 2);
										return false;
									}
									a[1][m - 1] = '.';
									a[i][m - 2] = '*';
									return true;
								}
							}

						for (int jj = m - 2; jj >= 2; --jj)
							if  (M) {
								a[i][jj] = '*';
								--M;
							}

						assert(!M);
						return true;	
					}
				}

		for (int j = m - 1; j >= 2; --j)
			for (int i = 0; i <= 1; ++i)
				if  (M) {
					a[i][j] = '*';
					--M;

					if  (!M) {
						if  (i == 1) {
							return true;
						}

						if  (j <= 3) {
							return false;
						}

						forn(jj, 3)
							a[2][jj] = '.';
						a[0][j - 1] = a[1][j] = a[1][j - 1] = '*';
						return true;
					}
				}

		if  (M) {
			return false;
		}

	  	return true;
	}	

	if  (n == 1) {
		for (int j = m - 1; j >= 2; --j)
			if  (M) {
				a[0][j] = '*';
				--M;
			}

		if  (M) {
			return false;
		}

		return true;
	}

	if  (M & 1) {
		return false;
	}

	for (int j = m - 1; j >= 2; --j)
		for (int i = 0; i <= 1; ++i)	
			if  (M) {
				a[i][j] = '*';
				--M;
			}	

	if  (M) {
		return false;
	}

	return true;
}

bool was[60][60];
int cnt[60][60];

bool on( int i, int j ) {
	return 0 <= i && i < n && 0 <= j && j < m;
}

bool check() {
	return true;
	memset (cnt, 0, sizeof cnt);

	forn(i, n)
		forn(j, m)
			for (int di = -1; di <= 1; ++di)
				for (int dj = -1; dj <= 1; ++dj) {
					int ii = i + di;
					int jj = i + dj;

					if  (on(ii, jj) && a[ii][jj] == '#') {
						++cnt[i][j];	
				   	}
				}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	forn(it, t) {
		int M;
		scanf("%d%d%d", &n, &m, &M);

//		solve();
//		continue;

		printf("Case #%d:\n", it + 1);
		if  (!solve(M)) {
			if  (M < n * m - 1) {
				assert(M == n * m - 5 || M == n * m - 7 || (M > n * m - 4 && n > 1 && m > 1) || (M % 2 == 1 && n == 2));
			}

			puts("Impossible");
			continue;
		}

		if  (sw) {
			forn(j, m) {
				forn(i, n)
					putchar(a[i][j]);
				puts("");
			}
		} else {
			forn(i, n) {
				forn(j, m)
					putchar(a[i][j]);
				puts("");
			}
		}
	}
		
	return 0;
}
