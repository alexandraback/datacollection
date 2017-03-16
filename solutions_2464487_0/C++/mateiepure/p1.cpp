#include <fstream>
#define M_PI 3.14159265358979323846

using namespace std;

ifstream in("p1.in");
ofstream out("p1.out");

long long solve(long long r, long long t) {
	long long last = r * r;
	long long cur;
	long long sum = 0;
	long long numCirc = 0;
	int alt = 0;

	while (sum <= t) {
		++r;
		alt ^= 1;
		cur = r * r;

		if (alt && sum + cur - last <= t) {
			numCirc += alt;
		}
		sum += alt * (cur - last);

		last = cur;
	}
	
	return numCirc;
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
