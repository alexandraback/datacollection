#include <fstream>
using namespace std;

int c, d, t, v, sum, coin[300];
int i, j;

int main() {
	ifstream fi("coin.in");
	ofstream fo("coin.out");
	fi >> t;
	for(int T = 1; T <= t; T++) {
		fi >> c >> d >> v;
		int d_init = d;
		for (i = 0; i < d; i++) fi >> coin[i];

		for (j = 1; j <= v; j++) {
			bool ok = false;
			for (int mask = 1; mask < (1<<d); mask++) {
				int sum = 0;
				for (i = 0; i < d; i++)
					if (((1<<i)&mask) > 0) {
						sum += coin[i];
					}
					if (j == sum) ok = true;
			}
			if (ok == false) {
				coin[d] = j;
				d++;
			}
		}

		fo << "Case #" << T << ": " << d - d_init << "\n";
	}
	return 0;
}