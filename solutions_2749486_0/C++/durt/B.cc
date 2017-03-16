#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int X, Y;

int nsteps_total;

/*
int calcSteps(int a, int b) {
	if (a == 0 && b == 0)
		return 0;
	a = abs(a);
	b = abs(b);
	if (a < b) swap(a, b);
	// now (a,b) is in first octant
	int s = a+b;
	int i = 1;
	while (i*(i+1)/2 < s)
		i++;
	if (s + 1 == i*(i+1)/2)
		return i + 1;	// on the "bad line". takes an extra step
	else
		return i;
}
*/

int calcSteps(int a, int b) {
	if (a == 0 && b == 0)
		return 0;
	a = abs(a);
	b = abs(b);	
	int s = a+b;
	int i = 1;
	while (i*(i+1)/2 < s)
		i++;
	// i is minimal.. now increase it a couple if necessary
	// 
	//cout << " i = " << i << endl;
	int res;
	while (1) {
	if (i%4 == 1 || i%4 == 2) {
		// i gets us an odd sum
		if (s % 2 == 1)
			break;
		else
			i++;
	} else {
		// i gets us an even sum
		if (s % 2 == 0)
			break;
		else
			i++;
	}
	}
	res = i;
	//cout << " res = " << res << endl;
	return res;
}

bool workSteps(int a, int b, int steps) {
	int s = abs(a) + abs(b);
	if (steps * (steps + 1) / 2 < s)
		return false;
	if (steps%4 == 1 || steps%4 == 2) {
		if (s % 2 == 1)
			return true;
		return false;
	} else {
		if (s % 2 == 0)
			return true;
		return false;
	}
}

void verifyResult(string res, int X, int Y) {
	int n = res.length();
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		int len = i+1;
		char c = res[i];
		if (c == 'E') x += len;
		if (c == 'W') x -= len;
		if (c == 'N') y += len;
		if (c == 'S') y -= len;
	}
	if (X != x || Y != y)
		cout << "ERROR : incorrect result : x = " << x << " X = " << X << " y = " << y << " Y = " << y << endl;
}

/*
void solve(int a, int b, int steps) {
	// first flip... to first octant
	// then we know we came from East by 'steps' clicks
	// solve(a - steps, b, steps - 1);
	// if (steps == 1) ... just give a single 'E'
	// need some sort of rotation array?
	if (steps == 1) {
		// better be (+/- 1, 0) or (0, +/- 1)
		rotation[steps] = ...;
		return;
	}
	
}
*/

char dirchar[4] = {'E','N','W','S'};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

string solve(int a, int b) {
	string res = "";
	// previous step could have been one of four...
	for (int step = 1; step <= nsteps_total; step++) {
		for (int dir = 0; dir < 4; dir++) {
			int len = nsteps_total - step + 1;
			int ta = a - len * dx[dir];
			int tb = b - len * dy[dir];
			if (workSteps(ta, tb, nsteps_total - step)) {
				res = dirchar[dir] + res;
				a = ta;
				b = tb;
				break;
			}
		}
	}
	return res;
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> X >> Y;
		nsteps_total = calcSteps(X, Y);
		//cout << "*** X = " << X << " Y = " << Y << endl;
		//cout << "   *** nsteps_total = " << nsteps_total << endl;
		string res = solve(X, Y);
		//cout << "   *** res = " << res << endl;
		verifyResult(res, X, Y);
		cout << "Case #" << icase << ": " << res << endl;
	}
	return 0;
}
