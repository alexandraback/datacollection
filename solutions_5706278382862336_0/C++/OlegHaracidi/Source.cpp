#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main() {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");
	istream& in = fin;
	ostream& out = fout;

	int T;
	in >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		long long p, q;
		char buf[100] = {};
		in >> buf;
		sscanf_s(buf, "%I64d/%I64d", &p, &q);
		
		long long d = gcd(p, q);
		p /= d; 
		q /= d;

		long long m = 1LL << 40;
		if (m % q == 0) {
			long long n = m / q * p;
			int deg = -1;
			while (n > 0) {
				n >>= 1;
				deg++;
			}

			out << "Case #" << test_case << ": " << 40 - deg << endl;
		} else
			out << "Case #" << test_case << ": impossible" << endl;
	}

	out.flush();
	return 0;
}