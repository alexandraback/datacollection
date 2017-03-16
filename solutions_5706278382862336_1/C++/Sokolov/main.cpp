#pragma comment(linker, "/STACK:500000000")
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define y0 y123
#define y1 y1234
#define ll long long
#define llu long long unsigned
#define PI 3.1415926535897932384626433832795
#define EPS 1e-9
#define INF 2147483647
#define N 10005
#define M 10005
#define long long long

long gcd(long a, long b) { return (!b) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

long nextLong() {
	long n;
	scanf("%lld", &n);
	return n;
}

bool isPower(long n) {
	while (n % 2 == 0) {
		n /= 2;
	}
	return n == 1;
}

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int t = nextInt();
	for (int tt = 1; tt <= t; tt++) {
		long a, b;
		scanf("%lld/%lld", &a, &b);
		long g = gcd(a, b);
		a /= g;
		b /= g;
		printf("Case #%d: ", tt);
		if (!isPower(b)) {
			printf("impossible\n");
			continue;
		}
		int res = 0;
		while (b % 2 == 0) {
			b /= 2;
			res++;
			if (a >= b) {
				break;
			}
		}
		if (a >= b && res <= 40) {
			printf("%lld\n", max(res, 1));
		} else {
			printf("impossible\n");
		}
	}
	return 0;
}