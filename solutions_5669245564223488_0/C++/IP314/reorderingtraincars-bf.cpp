#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long int lli;

class reorderingtraincars
{
	private:
		const int MOD;

		int n; 
		vector<string> cars;

		lli factorial(int x) {
			lli res = 1;
			for (; x > 1; --x) {
				res *= x;
				res %= MOD;
			}
			return res;
		}

		string normalize(const string &s) {
			string fs = "";
			for (string::const_iterator c = s.begin(); c < s.end(); ++c) {
				if ((c == s.begin()) || (*c != *(c - 1))) {
					fs += *c;
				}
			}
			return fs;
		}

	public:
		reorderingtraincars() : MOD(1000000007) {}

		void input() {
			cin >> n;
			cars.resize(n);
			for (int i = 0; i < n; ++i) {
				cin >> cars.at(i);
			}
		}

		string solve() {
			ostringstream oss;
			for (int f = 0; f < n; ++f) {
				cars.at(f) = normalize(cars.at(f));
			}
			vector<int> inds(n);
			for (int f = 0; f < n; ++f) {
				inds.at(f) = f;
			}
			lli ways = 0;
			do {
				string cct = "";
				for (int f = 0; f < n; ++f) {
					cct += cars.at(inds.at(f));
				}
				bool possible = true;
				vector<bool> seen('z' - 'a' + 1, false);
				for (unsigned int f = 0; f < cct.size(); ++f) {
					if (seen.at(cct.at(f) - 'a') && (f > 0) && (cct.at(f) != cct.at(f - 1))) {
						possible = false;
						break;
					}
					seen.at(cct.at(f) - 'a') = true;
				}
				if (possible) {
					++ways;
					if (ways == MOD) {
						ways = 0;
					}
				}
			} while (next_permutation(inds.begin(), inds.end()));
			oss << ways;
			return oss.str();
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		reorderingtraincars task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
