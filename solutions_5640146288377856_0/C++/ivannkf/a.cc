#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int cas = 1; cas < t+1; ++cas) {
		int r,c,w;
		cin >> r >> c >> w;
		int find = ceil(double(c)/w);
		int res = find+w-1;
		res *= r;
		cout << "Case #" << cas << ": " << res << endl;
	}
}