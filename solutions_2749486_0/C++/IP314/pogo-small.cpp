#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class pogo_small
{
	private:
		int x, y;

	public:
		void input() {
			cin >> x >> y;
		}

		string solve() {
			string sol("");
			if (x > 0) {
				for (int f = 0; f < x; ++f) {
					sol += "WE";
				}
			}
			if (x < 0) {
				for (int f = 0; f < -x; ++f) {
					sol += "EW";
				}
			}
			if (y > 0) {
				for (int f = 0; f < y; ++f) {
					sol += "SN";
				}
			}
			if (y < 0) {
				for (int f = 0; f < -y; ++f) {
					sol += "NS";
				}
			}
			return sol;
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		pogo_small task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
