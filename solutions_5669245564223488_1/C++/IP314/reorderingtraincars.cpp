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
			lli ways = 1;
			int floats = 0;
			vector<string> newcars;
			newcars.reserve(n);
			for (char cc = 'a'; cc <= 'z'; ++cc) {
				int allsame = 0, front = 0, back = 0, middle = 0;
				string fs = "", bs = "";
				for (unsigned int f = 0; f < cars.size(); ++f) {
					string &s = cars.at(f);
					int cnt = 0;
					for (string::const_iterator c = s.begin(); c < s.end(); ++c) {
						if (*c == cc) {
							++cnt;
						}
					}
					if (cnt == static_cast<int>(s.size())) {
						++allsame;
					} else {
						bool nfb = true;
						if (s.at(0) == cc) {
							--cnt;
							++front;
							fs = s;
							nfb = false;
						}
						if (s.at(s.size() - 1) == cc) {
							--cnt;
							++back;
							bs = s;
							nfb = false;
						}
						if ((s.at(0) == cc) && (s.at(s.size() - 1) == cc)) {
							middle += 42;
						}
						if (cnt > 0) {
							middle += cnt;
						}
						if (nfb) {
							newcars.push_back(s);
						}
					}
				}
				//cerr << cc << " " << allsame << " " << front << " " << back << " " << middle << endl;
				if (middle > 1) {
					ways = 0;
					break;
				} else if (middle > 0) {
					if ((allsame > 0) || (front > 0) || (back > 0)) {
						ways = 0;
						break;
					}
				} else if ((front > 1) || (back > 1)) {
					ways = 0;
					break;
				} else {
					ways *= factorial(allsame);
					ways %= MOD;
					if (allsame + front + back > 0) {
						string ns = bs + string(1, cc) + fs;
						if ((ns.at(0) <= cc) && (ns.at(ns.size() - 1) <= cc)) {
							++floats;
						}
						newcars.push_back(normalize(ns));
					}
				}
				cars.clear();
				swap(cars, newcars);
			}
			//cerr << "F " << floats << endl;
			ways *= factorial(floats);
			ways %= MOD;
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
