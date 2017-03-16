#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

#ifndef MAXN
#define MAXN 100000
#endif

int find_n(int N, int &R){
	int n = 1, i = 0;
	int step = 2;
	while(n <= N) {
		R = N - n;
		n += step * 2 + 1;
		step += 2;
		i++;
	}
	return i - 1;
}

int main(){
	int tcase;
	cin >> tcase;
	cout.precision(15);
	for(size_t casen = 0; casen < tcase; ++casen)
	{
		int N, X, Y, R;
		cin >> N >> X >> Y;
		
		cout << "Case #" << casen + 1 << ": ";
		int F = find_n(N, R);
		// cout << F << " " << R << endl;
		if (2 * F >= abs(X) + Y) {
			cout << 1.0 << endl;		
			continue;
		} else if (abs(X) + Y - 2 * F > 2) {
			cout << 0.0 << endl;
			continue;
		}

		int H = 2 * (F + 1);
		if (H < R){
			// cout << R << " " << H << endl;
			int T = 2 * H - R + 1;
			// if (T == 0 && Y <= H) cout << 1 << endl;
			// cout << T << " " << Y << " " << R-H << endl;
			cout << (T - max(0,(Y - (R - H) + 1))) / double(T) << endl;
		}else {
			double sol = 0;
			// cout << Y << " " << R << endl;
			for(int i = Y; i < R; ++i) {
				sol += pow(0.5,i+1);
			}
			cout << sol << endl;
		}
	}
	

	return 0;
}
