#include <cstdlib>
#include <iostream>

using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t, tt;
	cin >> t;
	for (tt = 1; tt <= t; tt++) {
		cout << "Case #" << tt << ": ";
		double c, f, x;
		cin >> c >> f >> x;
		double passed = 0.0, cRate = 2.0, thusFar;
		double nRate, nThusFar;
		while (1) {
			thusFar = passed+x/cRate;
			nRate = cRate+f;
			nThusFar = c/cRate+x/nRate+passed;
			if (thusFar <= nThusFar) 
				break;
			else {
				passed += c/cRate;
				cRate += f;
			}
		}
		printf("%.7lf\n", thusFar);
	}
	return 0;
}