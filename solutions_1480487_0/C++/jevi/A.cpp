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
double x;
vector<int> s;

void solve(int test) {
	vector<double> p(n);
	
	for(int k = 0; k < n; k++) {
		double l = 0, r = 1;
		
		while(fabs(l-r) > 1e-13) {
			double m = (l+r)/2;
			
			double score = s[k]+m*x;
			
			double rest = 0;
			for(int i = 0; i < n; i++) {
				if(i != k) {
					rest += max(0.0, (score-s[i]) / x);
				}
			}
			
			if(rest + m > 1) {
				r = m;
			} else {
				l = m;
			}
		}
		
		p[k] = 100*l;
	}
	
	cout << "Case #" << test << ":";
	cout << fixed << setprecision(8);
	for(int i = 0; i < n; i++) {
		cout << " " << p[i];
	}
	cout << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int testNumber; scanf("%d\n", &testNumber);
	for(int test = 1; test <= testNumber; test++) {
		x = 0;
		cin >> n;
		s = vector<int>(n);
		for(int i = 0; i < n; i++) {
			cin >> s[i];
			x += s[i];
		}
		solve(test);
	}
}
