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

int n, m;
int h[MAX][MAX];

void Read() {
	int i, j;
	scanf("%d %d", &m, &n);
	ZERO(h);
	fj(1, m) {
		fi(1, n) {
			scanf("%d", &h[j][i]);
		}
	}
}

int a[MAX][MAX];

void Solve() {
	int i, j;
	int b;
	ZERO(a);
	fj(1, m) {
		fi(1, n) {
			a[j][i] = 100;
		}
	}
	fj(1, m) {
		b = 0;
		fi(1, n) {
			b = max(b, h[j][i]);
		}
		fi(1, n) {
			a[j][i] = min(a[j][i], b);
		}
	}

	fi(1, n) {
		b = 0;
		fj(1, m) {
			b = max(b, h[j][i]);
		}
		fj(1, m) {
			a[j][i] = min(a[j][i], b);
		}
	}

	fj(1, m) {
		fi(1, n) {
			if (a[j][i] != h[j][i]) {
				printf("NO\n");
				return;
			}
		}
	}

	printf("YES\n");
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
