#include <iostream>
#include <vector>
using namespace std;

int main() {
	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; ++test) {
		int j, p, s, k;
		cin >> j >> p >> s >> k;

		cout << "Case #" << test << ": ";
		if (k >= s) {
			cout << j*p*s << endl;
			for (int ij = 1; ij <= j; ++ij) {
				for (int ip = 1; ip <= p; ++ip) {
					for (int is = 1; is <= s; ++is) {
						cout << ij << " " << ip << " " << is << endl;
					}
				}
			}
		} else {
			cout << j*p*k << endl;
			for (int ij = 1; ij <= j; ++ij) {
				int is = ij;
				for (int ip = 1; ip <= p; ++ip) {
					for (int ik = 1; ik <= k; ++ik) {
						cout << ij << " " << ip << " " << (is - 1 + ik - 1) % s + 1 << endl;
					}
					++is;
				}
			}
		}
	}
}
