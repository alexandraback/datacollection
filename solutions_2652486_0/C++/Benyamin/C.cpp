// In The Name of God
#include <iostream>
#include <algorithm>
#include <fstream>
#define cin fin
#define cout fout
using namespace std;

ifstream fin("C-small-1-attempt0.in");
ofstream fout("C-small-1-attempt0.out");

int T, r, n, m, k, prd[10], adad[7];

int main() {
	ios_base::sync_with_stdio(false);
	cin >> T;
	for(int i = 1; i <= T; ++i) {
		cin >> r >> n >> m >> k;
		cout << "Case #" << i << ":" << endl;
		for(int j = 0; j < r; ++j) {
			for(int h = 0; h < k; h++)
				cin >> prd[h];
			adad[2] = adad[3] = adad[4] = adad[5] = 0;
			for(int h = 0; h < k; ++h) {
				int tmp = 0;
				while(prd[h] % 5 == 0) {
					prd[h] /= 5;
					tmp++;
				}
				adad[5] = max(adad[5], tmp);
				tmp = 0;
				while(prd[h] % 4 == 0) {
					prd[h] /= 4;
					tmp++;
				}
				adad[4] = max(adad[4], tmp);
				if(prd[h] % 2 == 0) {
					prd[h] /= 2;
					adad[2] = max(adad[2], 1);
				}
				tmp = 0;
				while(prd[h] % 3 == 0) {
					tmp++;
					prd[h] /= 3;
				}
				adad[3] = max(adad[3], tmp);
			}
			int s = n - adad[2] - adad[3] - adad[4] - adad[5];
			for(int h = 0; h < adad[2] + s; h++)
				cout << 2;
			for(int h = 0; h < adad[3]; ++h)
				cout << 3;
			for(int h = 0; h < adad[4]; ++h)
				cout << 4;
			for(int h = 0; h < adad[5]; ++h)
				cout << 5;
			cout << endl;
		}
	}
	return 0;
}
