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


string s[15];
int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
		}
		int res = 0;
		int a[15];
		for (int i = 0; i < n; i++) {
			a[i] = i;
		}
		bool used[255];
		do {
			bool ok = true;
			for (char i = 'a'; i <= 'z'; i++) {
				used[i] = false;
			}
			char p = s[a[0]][0];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < s[a[i]].length(); j++) {
					if (s[a[i]][j] != p) {
						used[p] = true;
						p = s[a[i]][j];
						if (used[p]) {
							ok = false;
							i = n;
							break;
						}
					}
				}
			}
			if (ok) {
				res++;
			}
		} while (next_permutation(a, a+n));
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}