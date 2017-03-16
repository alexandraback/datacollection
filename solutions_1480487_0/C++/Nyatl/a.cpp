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

#define MAX 300

int n;

int a[MAX];

void Read() {
	int i;
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d", &a[i]);
	}
}

int s;

bool Check(double t, double b, int x) {
	int i;
	fi(1, n) {
		if (i == x) continue;
		if (a[i] > b) continue;
		t -= (b - a[i]) / s;
	}
	return t >= 0;
}

void Solve(int x) {
	int i;
	double l, r, h;
	l = 0;
	r = 1;
	fi(1, 100) {
		h = (l + r) / 2;
		if (Check(1 - h, a[x] + s * h, x)) {
			l = h;
		} else {
			r = h;
		}
	}
	printf("%.10lf ", (l + r) / 2 * 100);
}

void Solve() {
	int i;
	s = 0;
	fi(1, n) {
		s += a[i];
	}
	fi(1, n) {
		Solve(i);
	}
	printf("\n");
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