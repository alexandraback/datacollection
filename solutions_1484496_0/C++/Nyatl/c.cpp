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

int n;

#define MAX 1000

int64 a[MAX];

void Read() {
	int i;
	scanf("%d", &n);
	fi(1, n) {
		scanf("%lld", &a[i]);
	}
}

int64 s1, s2;

vector <int64> v1, v2;

bool Fun(int x) {
	if (x == n + 1) {
		if (s1 > 0 && s1 == s2) {
			return true;
		}
		return false;
	}
	s1 += a[x];
	v1.pb(a[x]);
	if (Fun(x + 1)) return true;
	s1 -= a[x];
	v1.pop_back();

	s2 += a[x];
	v2.pb(a[x]);
	if (Fun(x + 1)) return true;
	s2 -= a[x];
	v2.pop_back();

	if (Fun(x + 1)) return true;

	return false;
}

void Solve() {
	int i;
	s1 = 0;
	s2 = 0;
	v1.clear();
	v2.clear();
	printf("\n");
	if (Fun(1)) {
		fi(0, SIZE(v1) - 1) {
			printf("%d ", v1[i]);
		}
		printf("\n");
		fi(0, SIZE(v2) - 1) {
			printf("%d ", v2[i]);
		}
		printf("\n");
	} else {
		printf("Impossible\n");
	}
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