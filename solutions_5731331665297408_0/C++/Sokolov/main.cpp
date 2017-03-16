#pragma comment(linker, "/STACK:500000000")
#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stack>
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

int gcd(int a, int b) { return (!b) ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

int nextInt() {
	int n;
	scanf("%d", &n);
	return n;
}

string codes[10];
bool a[10][10];
int p[10];

int main() {
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int t = nextInt();
	for (int tt = 1; tt <= t; tt++) {
		int n = nextInt();
		int m = nextInt();
		for (int i = 1; i <= n; i++) {
			cin >> codes[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				a[i][j] = false;
			}
		}
		for (int i = 0; i < m; i++) {
			int x = nextInt();
			int y = nextInt();
			a[x][y] = true;
			a[y][x] = true;
		}
		string res = "z";
		for (int i = 0; i < n; i++) {
			p[i] = i+1;
		}
		int used[10];
		do {
			int s = 0;
			bool ok = true;
			for (int i = 0; i < n; i++) {
				if (i > 0) {
					int j = s-1;
					while (j >= 0) {
						if (a[p[i]][used[j]]) {
							break;
						}
						j--;
					}
					if (j < 0) {
						ok = false;
						break;
					} else {
						s = j+1;
					}
				}
				used[s++] = p[i];
			}
			if (ok) {
				string t = "";
				for (int i = 0; i < n; i++) {
					t += codes[p[i]];
				}
				if (res.compare(t) > 0) {
					res = t;
				}
			}
		} while (next_permutation(p, p+n));
		cout << "Case #" << tt << ": " << res << endl;
	}
	return 0;
}