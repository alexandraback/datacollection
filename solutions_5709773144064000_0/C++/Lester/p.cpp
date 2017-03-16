#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define sz(x) (int)(x).size()
#define double long double

typedef long long ll;

void init() {
	ios_base::sync_with_stdio(false);
}

int main() {
	init();
	int tests;
	cin >> tests;
	cout.precision(7);
	cout.setf(ios::fixed);
	for(int t = 1;t <= tests;t++) {
		double c, f, x, res = 0.0;
		cin >> c >> f >> x;
		if(c >= x) {
			res = x / 2.0;
		} else {
			double cur = 0.0, speed = 2.0;
			while(cur < x) {
				if(cur >= c) {
					double oldT = (x - cur) / speed;
					double newT = (x - cur + c) / (speed + f);
					if(newT < oldT) {
						cur -= c;
						speed += f;
					} else {
						res += (x - cur) / speed;
						break;
					}
				} else {
					res += (c - cur) / speed;
					cur = c;
				}
			}
		}
		cout << "Case #" << t << ": " << res << '\n';
	}

	return 0;
}
