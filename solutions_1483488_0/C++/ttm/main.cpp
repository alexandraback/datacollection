#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define maxbound 2223

bool irot(int a, int b) {
	int dig = (int)floor(log10(a) + 1);
	if (dig != (int)floor(log10(b) + 1)) return false;
	int m = (int)pow(10, dig - 1);
	for (int r = 0; r < dig - 1; ++r) {
		a = m * (a % 10) + a / 10;
		if (a == b)
			return true;
	}
	return false;
}

int main (int argc, char *argv[]) {

	vector<int> v(maxbound);
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	/*v[0] = 0;
	for (int i = 0; i < maxbound; ++i) {
		if (i > 0) v[i] = v[i - 1];
		for (int j = 0; j < i; ++j) {
			v[i] += irot(i, j) ? 1 : 0;
		}
	}*/


	int cases;
	cin >> cases;

	for (int cas = 1; cas <= cases; ++cas) {
		int a, b;
		cin >> a >> b;
		int m = a + 1, n = a, res = 0;
		while (true) {
			if (irot(m, n)) {
				res++;
			}
			if (m < b) m++;
			else if (n + 1 < b) {
				n++;
				m = n + 1;
			}
			else break;
		}
		//cout << "Case #" << cas << ": " << v[b] - v[max(0, a - 1)] << endl;
		cout << "Case #" << cas << ": " << res << endl;
	}

	return 0;
}