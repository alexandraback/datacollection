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

char w[600000][11];
int wl[600000];
char s[10000];
int d[10000][5];

int main() {
	FILE *f = fopen("garbled_email_dictionary.txt", "r");
	int m = 0;
	while (!feof(f)) {
		w[m][0] = 0;
		fscanf(f, "%s", w[m]);
		if (wl[m] = strlen(w[m])) ++m;
	}
	fclose(f);
	int T; scanf("%d\n", &T);
	for (int tt = 1; tt <= T; ++tt) {
		cin >> s;
		int n = strlen(s);
		memset(d, ~0, sizeof(d));
		d[0][4] = 0;
		int result = n;
		for (int i = 0; i < n; ++i) {
			map<pair<int, pair<int, int> >, int> q;
			for (int j = 0; j < m; ++j) if (i + wl[j] <= n) {
				int first = -1, last = -1;
				bool f = true;
				int c = 0;
				for (int k = 0; k < wl[j]; ++k) {
					if (w[j][k] != s[i + k]) {
						++c;
						if (first == -1) first = k;
						if (last != -1 && k - last <= 4) {
							f = false;
							break;
						}
						last = k;
					}
				}
				if (f) {
					pair<int, pair<int, int> > v = mp(wl[j], mp(first, last));
					//cout << i << " " << w[j] << " " << c << " " << first << " " << last << endl;
					if (q.find(v) == q.end()) {
						q[v] = c;
					} else {
						if (q[v] > c) q[v] = c;
					}
				}
			}
			for (int j = 0; j < 5; ++j) if (d[i][j] != -1) {
				for (map<pair<int, pair<int, int> >, int>::iterator it = q.begin(); it != q.end(); ++it) {
					int l = it->first.first;
					int first = it->first.second.first;
					int last = it->first.second.second;
					int c = it->second;
					if (first == -1 || first + j + 1 >= 5) {
						int x = i + l;
						int y = l - last - 1;
						if (last == -1) y = j + l;
						if (y > 4) y = 4;
						if (d[x][y] == -1 || d[x][y] > d[i][j] + c) {
							d[x][y] = d[i][j] + c;
						}
					}
				}
			}
		}

		for (int i = 0; i < 5; ++i) {
			if (d[n][i] != -1 && result > d[n][i]) {
				result = d[n][i];
			}
		}

		printf("Case #%d: %d", tt, result);
		putchar('\n');
	}
	return 0;
}
