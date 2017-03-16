#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	cin >> T;
	for (int ti = 1; ti <= T; ti++) {
		long double r, t;
		cin >> r >> t;
		long double b = 2 * r - 1;
		long long n = (long long) ((b * -1 + sqrt(b * b + 8.0 * t)) / 4.0);
		for ( ; n >= 0; n -= 1) {
			long double x = (long double) 2.0 * n * n + (2.0 * r - 1) * n;
			if (x <= t) break;
		}
		cout << "Case #" << ti << ": " << (long long) n << endl;
	}

	return 0;
}
