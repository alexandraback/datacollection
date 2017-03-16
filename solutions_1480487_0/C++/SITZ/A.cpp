#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, M = 0;
		cin >> N;
		double vec[N];
		double sum = 0;
		for (int i = 0; i < N; i++) {
			cin >> vec[i];
			sum += vec[i];
		}
		sum *= 2.0;
		
		for (int i = 0; i < N; i++) {
			if (vec[i] * N < sum) ++M;
		}
		
		cout << "Case #" << t << ":";
		for (int i = 0; i < N; i++) {
			if (vec[i] * N >= sum) printf(" 0.000000");
			else {
				double val = (sum / M -  vec[i]) / sum * 100.0;
				if (M > 1) val *= 2;
				printf(" %.6lf", val);
			}
		}
		cout << endl;
	}
	return 0;
}
