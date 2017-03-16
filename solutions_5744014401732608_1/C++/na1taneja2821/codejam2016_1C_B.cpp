#include <bits/stdc++.h>
using namespace std;
long long int power(int n) {
	if(n < 0) {
		return 0;
	}
	long long int res = 1;
	int i;
	for(i = 0; i < n; i++) {
		res *= 2;
	}
	return res;
}
int getbase(long long int m) {
	long long int res = 1;
	int i = 0;
	while(1) {
		if(res >= m) {
			return i;
		}
		res *= 2;
		i++;
	}
}
int main() {
	int t;
	cin >> t;
	int run;
	for(run = 1; run <= t; run++) {
		int n;
		long long int m;
		cin >> n;
		cin >> m;
		int mat[55][55] = {0, 0};
		cout << "Case #" << run << ": ";
		if(power(n - 2) < m) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			int base = getbase(m);
			cout << "POSSIBLE" << endl;
			int i, j, bitsize = 0;
			m--;
			for(i = n - 2; i >= n - 2 - base; i--) {
				if(i == n - 1) {
					for(j = 0; j < n; j++) {
						mat[i][j] = 0;
					}
				} else {
					long long int val = power(bitsize);
					if(val <= m) {
						for(j = 0; j < n - 1 - bitsize; j++) {
							mat[i][j] = 0;
						}
						int cnt = 0;
						for(;cnt < bitsize; cnt++) {
							mat[i][j++] = 1;
						}
						mat[i][n - 1] = 1;
						m -= val;
					} else if (m != 0) {
						m--;
						for(j = n - 2; j >= 0; j--) {
							if(m & 1) {
								mat[i][j] = 1;
							}
							m >>= 1;
						}
						mat[i][n - 1] = 1;
						m = 0;
					}
					bitsize++;
				}
			}
			//cout << base << endl;
			for(i = n - 1; i >= n - base - 1; i--) {
				mat[0][i] = 1;
			}
			for(i = 0; i < n; i++) {
				for(j = 0; j < n; j++) {
					cout << mat[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}