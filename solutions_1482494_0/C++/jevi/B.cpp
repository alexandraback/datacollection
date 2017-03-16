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

int n;
vector<int> a, b;
int avis[2005][1005], bvis[2005][1005];

void solve(int t) {
	int bMax = 0;
	for(int i = 0; i < n; i++) {
		bMax = max(bMax, b[i]);
	}
	
	memset(avis, 0, sizeof(avis));
	memset(bvis, 0, sizeof(bvis));
	int inf = 1000000000;
	vector<int> s(2005, inf);
	s[0] = 0;
	
	for(int i = 1; i <= 2*n; i++) {
		int d = inf, k, p, isa;
		for(int j = 0; j < n; j++) {
			if(a[j] < i && !avis[i-1][j]) {
				if(s[i-1]+1 < d) {
					d = s[i-1]+1;
					k = j;
					p = i-1;
					isa = true;
				}
			}
			if(b[j] < i && avis[i-1][j] && !bvis[i-1][j]) {
				if(s[i-1] < d) {
					d = s[i-1];
					k = j;
					p = i-1;
					isa = false;
				}
			}
			if(i > 1 && b[j] < i-1 && !avis[i-2][j] && !bvis[i-2][j]) {
				if(s[i-2] < d) {
					d = s[i-2];
					k = j;
					p = i-2;
					isa = false;
				}
			}
		}
//		cout << i << ' ' << d << " | " << k << ' ' << isa << endl;
		if(d < inf) {
			s[i] = d;
			for(int j = 0; j < n; j++) {
				avis[i][j] = avis[p][j];
				bvis[i][j] = bvis[p][j];
			}
			if(isa) {
				avis[i][k] = true;
			} else {
				bvis[i][k] = true;
			}
		}
	}
	
	int ans = inf;
	for(int g = bMax; g <= 2*n; g++) {
		ans = min(ans, s[g]);
	}
	
	if(ans < inf) {
		cout << "Case #" << t << ": " << ans+n << endl;
	} else {
		cout << "Case #" << t << ": Too Bad" << endl;
	}
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T; scanf("%d\n", &T);
	for(int t = 1; t <= T; t++) {
		cin >> n;
		a = vector<int>(n);
		b = vector<int>(n);
		for(int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
		}
		solve(t);
	}
}
