#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

int e, r, n;
vector<int> v;

unsigned long long rec(int x1, int y1, int x2, int y2) {
	if (x1 == x2) return 0;

	auto max_it = max_element(v.begin() + x1, v.begin() + x2);
	int xm = max_it - v.begin();

	ll y1_1 = min((ll)e, (ll)y1 + (xm-x1)*r);
	ll y2_1 = max((ll)0, (ll)y2 - (x2-1-xm)*r);

	ll gain = -(y2_1-y1_1)*(ll)v[xm];
	return (unsigned long long)gain + rec(x1, y1, xm, y1_1-r) + rec(xm+1, y2_1+r, x2, y2);
}

int main() {
	int ti;
	cin >> ti;
	for (int ii = 0; ii < ti; ii++) {
		cin >> e >> r >> n;
		v.clear();
		v.resize(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];

		cout << "Case #" << (ii+1) << ": " << rec(0, e, n, 0) << endl;
	}
	return 0;
}
