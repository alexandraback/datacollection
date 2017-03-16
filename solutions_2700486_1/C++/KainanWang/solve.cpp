#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
using namespace std;


double comb[5005][5005];

double calc(int size, int cnt, int limit) {
	double res = 0;
	memset(comb, 0, sizeof(comb));
	comb[0][0] = 1.0;
	for (int i = 0; i <= size; ++i)
		for (int j = 0; i + j <= cnt; ++j) {
			double t = comb[i][j];
			if (i + j == cnt && i >= limit) res += t;
			int o = 0;
			if (i + 1 <= size) ++o;
			if (j + 1 <= size) ++o;
			if (i + 1 <= size) comb[i + 1][j] += t / o;
			if (j + 1 <= size) comb[i][j + 1] += t / o;
		}
	//	cout << "ds" << size << ' ' << cnt << ' ' << limit  << ' ' << comb[1][0] << endl;
	return res;
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("b22.out", "w", stdout);


	int nc;
	cin >> nc;
	for (int cs = 1; cs <= nc; ++cs) {
		int n, x, y;
		cin >> n >> x >> y;
		
		int sum = 0, delta = -3;
		double res = 0;
		
	
		for (int c = 0; ; c += 2) {
			if (sum > n) break;
			delta += 4;
			sum += delta;
			if (abs(x) + y > c) continue;
			
			if (n >= sum) {
				res = 1;
				break;
			}
			
			int size = (delta - 1) / 2;
			int o = n - (sum - delta);
			int limit = size - abs(x) + 1;
			res = calc(size, o, limit);
			break;
		}
		
		if (x == 0 && y == 0) res = 1.0;
		
		printf("Case #%d: %.7f\n", cs, res);
	}
	return 0;
}

