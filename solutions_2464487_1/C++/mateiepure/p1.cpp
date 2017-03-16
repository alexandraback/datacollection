#include <fstream>

using namespace std;

ifstream in("p1.in");
ofstream out("p1.out");

unsigned long long solve(unsigned long long r, unsigned long long t) {
	unsigned long long step, i;

	for (step = 1; step < t; step <<= 1);
	for (i = 0; step; step >>= 1) {
		unsigned long long n = i + step;
		if (n > 1000000000)
			continue;

		unsigned long long sum = n * (2*n + 2*r - 1);
		
		if (sum <= t) {
			i += step;
		}
	}

	return i;
}

int main() {
	int t;
	in >> t;

	for (int i = 1; i <= t; ++i) {
		long long r, d;
		in >> r >> d;

		out << "Case #" << i << ": " << solve(r, d) << "\n";
	}

	return 0;
}
