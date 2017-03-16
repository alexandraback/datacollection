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

int a, b;
vector<double> p;

void solve(int t) {
	double minExp = min(b+2, a+b+1);
	
	double dp = 1;
	for(int i = 0, k = a-1; i < a; i++, k--) {
		dp *= p[i];
		int s = 2*k+b-a+1;
		minExp = min(minExp, dp * s + (1-dp) * (s+b+1));
	}
	
	cout << fixed;
	cout << "Case #" << t << ": " << setprecision(8) << minExp << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T; scanf("%d\n", &T);
	for(int t = 1; t <= T; t++) {
		cin >> a >> b;
		p = vector<double>(a);
		for(int i = 0; i < a; i++) {
			cin >> p[i];
		}
		solve(t);
	}
}
