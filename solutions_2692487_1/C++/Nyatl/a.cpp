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

long long testq;
long long test;

#define MAX 100010

long long a, n;
long long s[MAX];

void Read() {
	long long i;
	ZERO(s);
	scanf("%lld %lld", &a, &n);
	fi(1, n) {
		scanf("%lld", &s[i]);
	}
}

void Solve() {
	long long i;
	long long ans;
	long long q;
	ans = n;
	q = 0;
	sort(s + 1, s + n + 1);

	fi(1, n) {
		if (s[i] < a) {
			a += s[i];
			ans = min(ans, q + n - i);
		} else {
			if (a == 1) break;
			a += a - 1;
			q++;
			i--;
		}
	}

	printf("%lld\n", ans);
}

int main(int argc, char **argv) {
	if (argc == 1) {
		freopen("input.txt","r",stdin);
	} else {
		freopen(argv[1], "r",stdin);
	}
	freopen("output.txt","w",stdout);
	scanf("%lld", &testq);
	for (test = 1; test <= testq; test++) {
		Read();
		printf("Case #%lld: ", test);
		Solve();
		fflush(stdout);
	}
	return 0;
}
