#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) > (b)) ? (b) : (a))
#define abs(a) (((a) > 0) ? (a) : (-(a)))

using namespace std;

int main () {
	int T;
	cin >> T;
	for (int tests = 0; tests < T; tests++) {
		printf ("Case #%d: ", tests+1);
		int x, y;
		cin >> x >> y;
		int X = 0, Y = 0;
		int step = 1;
		bool q = true;
		while (X != x) {
			if (q) {X += step; cout << "E";} else {X -= step; cout << "W";}
			step++;
			q = !q;
		}
		if (y > 0) q = false; else q = true;
		while (Y != y) {
			if (q) {Y += step; cout << "N";} else {Y -= step; cout << "S";}
			step++;
			q = !q;
		}
		cout << endl;
	}
}

