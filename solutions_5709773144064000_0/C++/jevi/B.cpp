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
typedef pair<int,int> pii;
typedef vector<vector<int> > graph;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }

#define mp make_pair
#define pb push_back
#define fst first
#define snd second

int TESTS, CASE;

double c, f, x;

void solve() {
	cout << "Case #" << ++CASE << ": ";
	double ans = 0;
	double speed = 2;
	while(true) {
		double timeWait = x/speed;
		double timePick = c/speed + x/(speed+f);
		if(timePick < timeWait) {
			ans += c/speed;
			speed += f;
		} else {
			ans += timeWait;
			break;
		}
	}
	cout << fixed << setprecision(7) << ans << endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin >> TESTS;
	for(int i = 0; i < TESTS; i++) {
		cin >> c >> f >> x;
		solve();
	}
}
