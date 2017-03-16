#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }
#define mp(x, y) make_pair(x, y)

int n, S, p;
vector<int> a;

void solve(int t) {
	int d[105][105];
	memset(d, 0, sizeof(d));
	
	for(int i = 1; i <= n; i++) {
		for(int x = 0; x <= 10; x++) {
			for(int y = 0; y <= 10; y++) {
				if(a[i]-x-y >= 0) {
					int z = a[i]-x-y;
					if(abs(x-y) <= 2 && abs(y-z) <= 2 && abs(z-x) <= 2) {
						bool good = (x>=p) || (y>=p) || (z>=p),
							surp = (abs(x-y) == 2) || (abs(y-z) == 2) || (abs(z-x) == 2);
						
						if(surp) {
							for(int s = 1; s <= n; s++) {
								d[i][s] = max(d[i][s], d[i-1][s-1]+good);
							}
						} else {
							for(int s = 0; s <= n; s++) {
								d[i][s] = max(d[i][s], d[i-1][s]+good);
							}
						}
					}
				}
			}
		}
	}
	
	cout << "Case #" << t << ": " << d[n][S] << endl;
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	
	int T; scanf("%d\n", &T);
	for(int t = 1; t <= T; t++) {
		cin >> n >> S >> p;
		a = vector<int>(n+1);
		for(int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		solve(t);
	}
}
