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
#define fi(a, b) for(i=a; i<=b; i++)
#define fj(a, b) for(j=a; j<=b; j++)
#define fo(a, b) for(o=a; o<=b; o++)
#define fdi(a, b) for(i=a; i>=b; i--)
#define fdj(a, b) for(j=a; j>=b; j--)
#define fdo(a, b) for(o=a; o>=b; o--)
#define ZERO(x) memset(x, 0, sizeof(x))
#define COPY(x,y) memcpy(x, y, sizeof(y))
#define LEN(x) (int)x.length()
#define SIZE(x) (int)x.size()

typedef long long int64;

#define MAX 110

int testq;
int test;

int k;

int d[MAX];
int n[MAX];
int w[MAX];
int e[MAX];
int s[MAX];
int dd[MAX];
int dp[MAX];
int ds[MAX];

void Read() {
	int i;
	scanf("%d", &k);
	fi(1, k) {
		scanf("%d %d %d %d %d %d %d %d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
	}
}

struct Attack {
	int d;
	int x1, x2;
	int s;
	int type;
	bool operator<(const Attack &a) const {
		if (d != a.d) return d < a.d;
		return type < a.type;
	}
};

void Solve() {
	int i, j;
	vector <Attack> v;
	Attack t;
	map <int, int> h;
	int ans;
	int f;
	fi(1, k) {
		fj(0, n[i] - 1) {
			t.d = d[i] + dd[i] * j;
			t.x1 = 2 * (w[i] + dp[i] * j);
			t.x2 = 2 * (e[i] + dp[i] * j);
			t.s = s[i] + ds[i] * j;
			t.type = 0;
			v.pb(t);

			t.d = d[i] + dd[i] * j;
			t.x1 = 2 * (w[i] + dp[i] * j);
			t.x2 = 2 * (e[i] + dp[i] * j);
			t.s = s[i] + ds[i] * j;
			t.type = 1;
			v.pb(t);
		}
	}
	sort(v.begin(), v.end());
	ans = 0;
	fi(0, SIZE(v) - 1) {
		if (v[i].type == 0) {
			f = 0;
			fj(v[i].x1, v[i].x2) {
				if (h[j] < v[i].s) {
					f = 1;
				}
			}
			if (f) {
				ans++;
			}
		} else {
			fj(v[i].x1, v[i].x2) {
				if (h[j] < v[i].s) {
					h[j] = v[i].s;
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%d", &testq);
	for (test = 1; test <= testq; test++) {
		Read();
		printf("Case #%d: ", test);
		Solve();
		fflush(stdout);
	}
	return 0;
}
