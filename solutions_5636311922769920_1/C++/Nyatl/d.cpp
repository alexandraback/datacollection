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

int k, c, s;

void read() {
	scanf("%d %d %d", &k, &c, &s);
}

void solve() {
	if (c == 1) {
		if (s != k) {
			printf("IMPOSSIBLE\n");
			return;
		}
		fi(1, s) {
			printf("%d ", i);
		}
		printf("\n");
		return;
	}
	if (2 * s < k) {
		printf("IMPOSSIBLE\n");
		return;
	}
	long long l = 1;
	fi(1, c - 1) {
		l *= k;
	}
	for (int i = 1; i <= k; i += 2) {
		if ((i - 1) * l + i + 1 <= l * k) {
			printf("%lld ", (i - 1) * l + i + 1);
		} else {
			printf("%lld ", (i - 1) * l + i);
		}
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
	scanf("%d", &number_of_tests);
	for (test_number = 1; test_number <= number_of_tests; test_number++) {
		read();
		printf("Case #%d: ", test_number);
		solve();
		fflush(stdout);
	}
	return 0;
}
