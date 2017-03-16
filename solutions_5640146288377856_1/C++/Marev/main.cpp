#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>

using namespace std;

int run() {
	double r, c, w;
	cin >> r >> c >> w;
	return (r - 1.0) * floor(c / w) + ceil(c / w) + w - 1.0;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": " << run() << endl;
	}
	return 0;
}