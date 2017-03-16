#include <iostream>
#include <vector>

using namespace std;

long reverse(long a);

int main(void)
{
	int T;
	int n = 1;
	long N;

	cin >> T;
	while (n <= T) {
		cout << "Case #" << n++ << ": ";
		cin >> N;

		int C[N + 1];
		for (long i = 0; i <= N; i++) {
			C[i] = INT_MAX;
		}
		C[1] = 1;
		for (long i = 2; i <= N; i++) {
			int min = C[i - 1] + 1;
			long ri = reverse(i);
			if (ri < i && min > C[ri] + 1) {
				min = C[ri] + 1;
			}
			C[i] = min;
		}
		cout << C[N] << endl;
	}

	return 0;
}

long reverse(long a)
{
	if (a % 10 == 0) return LONG_MAX;
	long A = 0;

	while (a > 0) {
		A = A * 10 + a % 10;
		a /= 10;
	}
	return A;
}
