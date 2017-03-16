#include <iostream>
#include <math.h>
using namespace std;
int main() {
	freopen("a-in.txt", "r", stdin);
	freopen("a-out.txt", "w", stdout);
	int ttt, tt, i, N, x, M;
	double A[1000], sum2;
	cin >> ttt;
	for(tt = 1; tt <= ttt; tt++) {
		cout << "Case #" << tt << ": ";
		cin >> N;
		double sum = 0.0;
		for(i = 0; i < N; i++) {
			cin >> A[i];
			sum += A[i];
		}
		M = 0;
		sum2 = 2.0;
		for(i = 0; i < N; i++) {
			if (sum2 / (N-M) < A[i] / sum) {
				M++;
				sum2 -= A[i] / sum;
			}
		}
//		cout << M << " " << sum2 << " ";
		for(i = 0; i < N; i++) {
			cout.setf(ios::fixed,ios::floatfield);
			cout.precision(5);
			cout << max((sum2 / (N-M) - A[i] / sum) * 100.0, 0.0);
			if (i + 1 < N) cout << " "; else cout << endl;
		}
	}
//ystem("pause");
	return 0;
}
