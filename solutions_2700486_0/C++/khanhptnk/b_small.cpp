#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

int ntest;
int n, X, Y;
bool has[110][110];

double ans;

void go(int at, double p) {
	if (at >= n) {
		if (has[X][Y]) ans += p;
		return;
	}
	int x = 50;
	int y = 50;
	while (has[x][y]) y += 2;
	int xl = x;
	int yl = y;
	while (yl > 50 && !has[xl - 1][yl - 1]) xl--, yl--;
	int xr = x;
	int yr = y;
	while (yr > 50 && !has[xr + 1][yr - 1]) xr++, yr--;
	//cout << xr << ' ' << yr << endl;
	if (xl == x && yl == y) {
		has[xr][yr] = true;
		go(at + 1, p);
		has[xr][yr] = false;
	}
	else
	if (xr == x && yr == y) {
		has[xl][yl] = true;
		go(at + 1, p);
		has[xl][yl] = false;
	}
	else {
		has[xl][yl] = true;
		go(at + 1, p * 0.5);
		has[xl][yl] = false;
		
		has[xr][yr] = true;
		go(at + 1, p * 0.5);
		has[xr][yr] = false;
	}
}

int main() {
	freopen("input_small.txt", "r", stdin);
	freopen("output_small.txt", "w", stdout);
	cin >> ntest;
	for (int test = 0; test < ntest; test++) {
		cin >> n >> X >> Y;
		X += 50;
		Y += 50;
		if (X > 100 || X < 0 || Y > 100 || Y < 0) {
			cout << "Case #" << test + 1 << ": " << "0.000000000" << endl; 
			continue;
		}
		memset(has, false, sizeof(has));
		has[50][50] = true;
		ans = 0;
		go(1, 1.0);
		cout << (fixed) << setprecision(9);
		cout << "Case #" << test + 1 << ": " << ans << endl;
	}
}
