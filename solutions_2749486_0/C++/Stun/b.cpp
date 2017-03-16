#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>
#include <stack>
#include <cassert>

using namespace std;
int X, Y;


string S, sol;
bool test2(int steps) {
	int x = X, y = Y;
	S = "";
	while (steps > 0) {
		if (abs(x) > abs(y)) {
			if (x > 0) {
				x = x - steps;
				S += "E";
			}else {
				x = x + steps;
				S += "W";
			}
		}else {
			if (y > 0) {
				y = y - steps;
				S += "N";
			} else {
				y = y + steps;
				S += "S";
			}
		}
		steps--;
		// cout << x << " " << y << " " << steps << endl;
	}
	// cout << X << " " << Y << endl;
	if (x == 0 && y == 0) {sol = S; return true;}
	// cout << x << " " << y << endl;
	return false;
}

bool test(int steps) {
	return test2(steps);
	int x = X, y = Y;
	while (steps > 0) {
		if (abs(x) > abs(y)) {
			x = abs(x) - steps;
		}else {
			y = abs(y) - steps;
		}
		steps--;
		// cout << x << " " << y << " " << steps << endl;
	}
	// cout << X << " " << Y << endl;
	if (x == 0 && y == 0) return true;
	// cout << x << " " << y << endl;
	return false;
}

int solve2(){
	for(size_t i = 1; i <= 500; ++i) {
		if (test2(i)) 
			return 1;
	}
}

int solve(int l = 0, int h = 500){
	int m = (h - l)/2 + l;
	// cout << m  << " " << l << " " << h << endl;
	if (m == l) return h;
	if (test(m)) {
		return solve(l, m);
	} else {
		if (m-1 > l && test(m-1)) return solve(l, m-1);
		return solve(m, h);
	}
}

int main(){
	int tcase;
	cin >> tcase;
	
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		cin >> X >> Y;
		// test(11);
		cout << "Case #" << casen + 1 << ": ";
		// cout << solve() << endl;
		solve2();
		std::reverse(sol.begin(),sol.end());
		cout << sol << endl;
		
	}
	

	return 0;
}
