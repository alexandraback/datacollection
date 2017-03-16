#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long int lli;

class partelf
{
	private:
		const lli MAXGEN;

		lli p, q;

		lli gcd(lli a, lli b) {
			if (a < b) {
				return gcd(b, a);
			} else if (b == 0) {
				return a;
			} else {
				return gcd(b, a % b);
			}
		}

	public:
		partelf() : MAXGEN(40) {}

		void input() {
			char divc;
			cin >> p >> divc >> q;
		}

		string solve() {
			ostringstream oss;
			lli pqgcd = gcd(p, q);
			p /= pqgcd;
			q /= pqgcd;
			lli l2q = 0;
			for (; (q & 1) == 0; q >>= 1, ++l2q);
			if ((q > 1) || (l2q > MAXGEN)) {
				oss << "impossible";
			} else {
				lli mg = l2q + 1;
				for (lli cea = 1; cea <= p; cea <<= 1, --mg);
				oss << mg;
			}
			return oss.str();
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		partelf task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
