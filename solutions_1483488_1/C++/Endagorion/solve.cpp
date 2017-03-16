#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int main() {
	fout.precision(10);
	fout << fixed;

	int T;
	fin >> T;
	for (int t = 1; t <= T; ++t) {
		int A, B;
		fin >> A >> B;
		int ans = 0;
		for (int n = A; n < B; ++n) {
			int p = 1;
			while (10 * p <= n) {
				p *= 10;
			}
			int q = 10;
			while (q < n) {
				int m = n / q + (n % q) * p;
				if (m > n && m <= B) {
					++ans;
				}
				if (m == n) {
					break;
				}
				p /= 10;
				q *= 10;
			}
		}
		fout << "Case #" << t << ": " << ans << '\n';
	}

	return 0;
}
