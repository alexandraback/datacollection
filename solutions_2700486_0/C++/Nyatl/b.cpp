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

int testq;
int test;

#define MAX 100

int n, x, y;

void Read() {
	scanf("%d %d %d", &n, &x, &y);
}

int h[MAX];
int q;

int Try(int mask) {
	int i;
	int X, Y;
	int res;
	ZERO(h);
	fi(0, MAX - 1) {
		if (i % 2 == 0) {
			h[i] = -2;
		} else {
			h[i] = -1;
		}
	}

	h[50] = 0;

	if (mask & 1) return -1;
	if (x == 0 && y == 0) {
		res = 1;
	} else {
		res = 0;
	}

	fi(1, n - 1) {
		X = 50;
		Y = h[X] + 2;

		if (((h[X - 1] == Y - 1) || (h[X + 1] == Y - 1)) && ((1 << i) & mask)) {
			return -1;
		}

		if (h[X - 1] != Y - 1 && h[X + 1] != Y - 1) {

			if (!((1 << i) & mask)) {
				X--;
				Y--;
			} else {
				X++;
				Y--;
			}

		}

		while (h[X - 1] != Y - 1 || h[X + 1] != Y - 1) {			
			if (h[X - 1] != Y - 1) {
				X--;
				Y--;
			} else {
				X++;
				Y--;
			}
		}
		if (X - 50 == x && Y == y) {
			res = 1;
		}
		h[X] = Y;
	}
	return res;
}

void Solve() {
	int i;
	double ans;
	ans = 0;
	q = 0;
	fi(0, (1 << n) - 1) {
		switch(Try(i)) {
			case 1:
				ans++;
			case 0:
				q++;
		}
	}
	ans /= q;
	printf("%.9lf\n", ans);
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
