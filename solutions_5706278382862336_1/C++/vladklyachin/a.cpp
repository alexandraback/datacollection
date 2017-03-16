#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstring>
#include <cstdlib>

using namespace std;

int64_t nod(int64_t p, int64_t q) // p < q
{
	while (p != 0) {
		int64_t r = q % p;
		q = p;
		p = r;
	}
	return q;
}

#define NN 40

int main(int argc, char ** argv)
{
	if (argc != 3) {
		cerr << "Usage: infile outfile\n";
		return 1;
	}
	ifstream fi(argv[1]);
	if (!fi) {
		cerr << argv[1] << ": " << strerror(errno) << endl;
		return 1;
	}
	ofstream fo(argv[2]);
	if (!fo) {
		cerr << argv[2] << ": " << strerror(errno) << endl;
		return 1;
	}

	int T;
	fi >> T;
	for (int t = 1; t <= T; ++t) {
		string s;
		fi >> s;
		auto p = s.find('/');
		string Ps = string(s, 0, p);
		string Qs = string(s, p+1);
		int64_t P, Q;
		P = atoll(Ps.c_str());
		Q = atoll(Qs.c_str());
		int64_t n = nod(P, Q);
		P /= n;
		Q /= n;
		if (Q & (Q-1)) {
			fo << "Case #" << t << ": impossible\n";
		} else {
			int i;
			for (i = 0; i <= NN; ++i) {
				if (P >= Q) {
					fo << "Case #" << t << ": " << i << endl;
					break;
				}
				P <<= 1;
			}
			if (i > NN) {
				fo << "Case #" << t << ": impossible\n";
			}
		}
	}
}

/* vim: set ts=4 sw=4 noet: */
