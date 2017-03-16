#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class consonants
{
	private:
		string s;
		int n;

	public:
		void input() {
			cin >> s >> n;
		}

		int solve() {
			vector<int> lastwi(s.size(), -1);
			int csl = 0;
			for (unsigned int f = 0; f < s.size(); ++f) {
				if (s.at(f) == 'a' || s.at(f) == 'e' || s.at(f) == 'i' || s.at(f) == 'o' || s.at(f) == 'u') {
					csl = 0;
				} else {
					++csl;
				}
				if (csl >= n) {
					lastwi.at(f) = f - n + 1;
				} else if (f > 0) {
					lastwi.at(f) = lastwi.at(f - 1);
				}
			}
			int sol = 0;
			for (unsigned int f = 0; f < s.size(); ++f) {
				if (lastwi.at(f) >= 0) {
					sol += lastwi.at(f) + 1;
				}
			}
			return sol;
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		consonants task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
