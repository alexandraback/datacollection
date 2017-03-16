#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int i, t, j, p, d;
	cin >> t;
	for (i = 1; i <= t; ++i) {
		cin >> d;
		int wyn = 0, podz = 0;
		int tab[1001];
		for (j = 0; j <= 1000; ++j)
		    tab[j] = 0;
		for (j = 1; j <= d; ++j) {
		    cin >> p;
		    tab[p]++;
		    if (p > wyn)
		        wyn = p;
		}
		for (j = wyn; j >= 1; --j) {
			if (tab[j] > 0) {
			    wyn = min(wyn, podz + j);
		        podz += tab[j];
		        if (j % 2 == 1) {
					tab[j / 2] += tab[j];
					tab[j / 2 + 1] += tab[j];
				} else
					tab[j / 2] += 2 * tab[j];
			}
		}
		cout << "Case #" << i << ": " << wyn << std::endl;
	}
	return 0;
}
