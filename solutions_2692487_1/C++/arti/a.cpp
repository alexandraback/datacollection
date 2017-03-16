#include <iostream>

#include <algorithm>
#include <functional>
#include <utility>

#include <cmath>
#include <numeric>
#include <complex>

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cassert>

#include <iomanip>
#include <sstream>

#include <cctype>
#include <cstring>
#include <string>

#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

typedef unsigned char uchar;
typedef short int sint;
typedef unsigned short int usint;
typedef unsigned int uint;
typedef long long i64;
typedef unsigned long long ui64;
typedef double dbl;
typedef long double ldbl;

#define pb push_back
#define mp make_pair

#define abs(x) ((x) < 0 ? (-(x)) : (x))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define max(x, y) ((x) > (y) ? (x) : (y))

const long double EPS = 1e-9;
const int iINF = INT_MAX;
const long double ldblINF = 1e100;

const int dd[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int dd2[8][2] = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};

int b[1000];

int main() {
	int T; scanf("%d\n", &T);
	for (int tt = 1; tt <= T; ++tt) {
		i64 a;
		int n;
		cin >> a >> n;
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		sort(b, b + n);
		int r = n;
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (a > b[i]) {
				a += b[i];
			} else {
				r = min(r, k + n - i);
				if (a > 1) {
					while (a <= b[i]) {
						a += a - 1;
						++k;
					}
					a += b[i];
				} else {
					break;
				}
			}
			if (i == n - 1) {
				r = min(r, k);
			}
		}
		printf("Case #%d: %d", tt, r);
		putchar('\n');
	}
	return 0;
}
