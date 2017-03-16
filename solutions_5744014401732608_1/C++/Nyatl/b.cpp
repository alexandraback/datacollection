#define _CRT_SECURE_NO_DEPRECATE

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>

using namespace std;

#define pb push_back
#define pf push_front
#define mp make_pair
#define fi(a, b) for(int i=a; i<=b; i++)
#define fj(a, b) for(int j=a; j<=b; j++)
#define fo(a, b) for(int o=a; o<=b; o++)
#define fdi(a, b) for(int i=a; i>=b; i--)
#define fdj(a, b) for(int j=a; j>=b; j--)
#define fdo(a, b) for(int o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

int number_of_tests;
int test_number;

int64 n, k;

#define MAX 52

int64 temp[MAX][MAX];

void mult(int64 a[MAX][MAX], int64 b[MAX][MAX], int64 c[MAX][MAX]) {
	ZERO(temp);
	fi(1, n) {
		fj(1, n) {
			int64 sum = 0;
			fo(1, n) {
				sum += a[i][o] * b[o][j];
			}
			temp[i][j] = sum;
		}
	}
	COPY(c, temp);
}

void read() {
	scanf("%lld %lld", &n, &k);
}

int64 a[MAX][MAX];
int64 t[MAX][MAX];

int64 d[MAX];

int64 calc() {
	ZERO(d);
	d[1] = 1;
	fi(1, n) {
		fj(1, n) {
			if (a[j][i]) {
				d[i] += d[j];
			}
		}
	}
	return d[n];
}

int u[MAX][MAX];

bool find() {
	ZERO(a);
	ZERO(u);
	fi(1, n - 1) {
		a[i][i + 1] = 1;
	}
	while (calc() != k) {
		vector <pair<int, int> > v;
		fi(1, n) {
			fj(1, n - i) {
				int x = j;
				int y = j + i;
				if (a[x][y] == 0 && !u[x][y]) {
					v.pb(mp(x, y));
				}
			}
		}
		if (SIZE(v) == 0) return false;
		fi(0, SIZE(v) - 1) {
			a[v[i].first][v[i].second] = 1;
			if (calc() > k) {
				a[v[i].first][v[i].second] = 0;
				u[v[i].first][v[i].second] = 1;
			}
		}
	}
	return true;
}

bool find_random() {
	ZERO(a);
	ZERO(u);
	fi(1, n - 1) {
		a[i][i + 1] = 1;
	}
	while (calc() != k) {
		vector <pair<int, int> > v;
		fi(1, n) {
			fj(1, n - i) {
				int x = j;
				int y = j + i;
				if (a[x][y] == 0 && !u[x][y]) {
					v.pb(mp(x, y));
				}
			}
		}
		if (SIZE(v) == 0) return false;
		random_shuffle(v.begin(), v.end());
		fi(0, SIZE(v) - 1) {
			a[v[i].first][v[i].second] = 1;
			if (calc() > k) {
				a[v[i].first][v[i].second] = 0;
				u[v[i].first][v[i].second] = 1;
			}
		}
	}
	return true;
}

void solve() {
	if (k > (1LL << (n - 2))) {
		printf("IMPOSSIBLE\n");
		return;
	}
	printf("POSSIBLE\n");
	if (!find()) {
		fprintf(stderr, "FAIL! (%lld -> %lld)\n", calc(), k);
		while (!find_random()) {
			fprintf(stderr, "FAIL RANDOM! (%lld -> %lld)\n", calc(), k);
		}
	}

	fj(1, n) {
		fi(1, n) {
			printf("%d", a[j][i]);
		}
		printf("\n");
	}
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &number_of_tests);
	for (test_number = 1; test_number <= number_of_tests; test_number++) {
		read();
		printf("Case #%d: ", test_number);
		solve();
		fflush(stdout);
	}
	return 0;
}
