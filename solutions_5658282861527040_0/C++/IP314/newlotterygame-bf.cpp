#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class newlotterygame
{
	private:
		int a, b, k;

	public:
		newlotterygame() {}

		void input() {
			cin >> a >> b >> k;
		}

		string solve() {
			ostringstream oss;
			int sol = 0;
			for (int i = 0; i < a; ++i) {
				for (int j = 0; j < b; ++j) {
					if ((i & j) < k) {
						++sol;
					}
				}
			}
			oss << sol;
			return oss.str();
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		newlotterygame task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
