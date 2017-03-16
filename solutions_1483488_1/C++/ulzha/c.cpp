#include <iostream>
#include <algorithm>
using namespace std;

const int bmax = 2000000;
int seenn[bmax + 1];

int main() {
	int nc, ic;
	
	cin >> nc;
	for (ic = 1; ic <= nc; ic++) {
		int a, b, i, j, n, m, p = 0, p10 = 1, r = 0;
		
		cin >> a >> b;
		fill(seenn, seenn + b + 1, 0);
		for (i = a; i < b; i++) {
			n = m = i;
			while (p10 * 10 <= n) p++, p10 *= 10;
			for (j = 0; j < p; j++) {
				m = m / 10 + m % 10 * p10;
//				cout << n << ',' << m << '\n';
				if (m > n && m <= b) {
					if (seenn[m] != n) r++;
					seenn[m] = n;
				}
			}
		}
		
		cout << "Case #" << ic << ": " << r << endl;
	}
	
	return 0;
}
