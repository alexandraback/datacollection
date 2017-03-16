#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int m, h;
double add;

void rec(int num, double & prob, int got) {
	if(num == m) {
		if(got >= h)
			prob += add;
	}
	else {
		rec(num + 1, prob, got + 1);
		rec(num + 1, prob, got);
	}
}

int main(int argc, const char * argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t) {
		int n, x, y;
		cin >> n >> x >> y;
		x = abs(x);
		int line = (x + y) / 2;
		int need = (2 * line + 1) * (line + 1);
		int prev = (2 * line - 1) * line;
		if(x == 0 && n < need) {
			cout << "Case #" << t + 1 << ": 0.0" << endl;
			continue;
		}
		if(n >= need - x) {
			cout << "Case #" << t + 1 << ": 1.0" << endl;
			continue;
		}
		else if(n <= prev + y) {
			cout << "Case #" << t + 1 << ": 0.0" << endl;
			continue;
		}
		double prob = 0.0;
		m = n - prev;
		add = pow(2.0, -m);
		h = y + 1;
		rec(0, prob, 0);
		printf("Case #%d: %lf\n", t + 1, prob);
	}
    
    return 0;
}
