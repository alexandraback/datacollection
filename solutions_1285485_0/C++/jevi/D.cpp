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

int n, m, d, t[205][205], vis[205][205], X, Y;
/*enum {
	UP, RIGHT, DOWN, LEFT
};

bool eq(double a, double b) {
	return fabs(a-b) < 1e-9;
}*/

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

void solve(int test) {
	int ka = 200/n, kb = 200/m;
	
	for(int x = 0; x < n; x++) {
		for(int y = 0; y < m; y++) {
			for(int a = 0; a < ka; a++) {
				for(int b = 0; b < kb; b++) {
					t[(a%2?n-x-1:x)+a*n][(b%2?m-y-1:y)+b*m] = t[x][y];
				}
			}
		}
	}
	
	int qa = ka/2, qb = kb/2;
	if(qa%2) qa--;
	if(qb%2) qb--;
	X += qa*n;
	Y += qb*m;
	int res = 0;
	
	
	n *= ka;
	m *= kb;
//	cout << X << ' ' << Y << " : " << n << ' ' << m << endl;
	memset(vis, 0, sizeof(vis));
	set<pair<int,int> > cnt;
	for(int x = X-d; x <= X+d; x++) {
		for(int y = Y-d; y <= Y+d; y++) {
			if(t[x][y] == 1 && (x!=X || y !=Y) && (x-X)*(x-X)+(y-Y)*(y-Y)<=d*d) {
				int g = gcd(abs(x-X), abs(y-Y));
				cnt.insert(mp((x-X)/g, (y-Y)/g));
			}
		}
	}
	
//	twod(t, X-d, X+d+1, Y-d, Y+d+1);

	cout << "Case #" << test << ": " << cnt.size() << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int T; scanf("%d\n", &T);
	for(int test = 1; test <= T; test++) {
		cin >> n >> m >> d;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				char c; cin >> c;
				if(c == 'X') {
					X = i-1;
					Y = j-1;
					t[i-1][j-1] = 1;
				} else if(c == '.') {
					t[i-1][j-1] = 0;
				}
			}
		}
		n-=2;
		m-=2;
		solve(test);
	}
}
