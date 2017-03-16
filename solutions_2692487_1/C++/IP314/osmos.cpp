#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class osmos
{
	private:
		int a, n;
		vector<int> ms;

		int greedyabsorb(int bs, int upto) {
			int added = 0;
			for (int f = 0; f < upto; ++f) {
				while (bs <= ms.at(f)) {
					bs += bs - 1;
					++added;
				}
				bs += ms.at(f);
			}
			return added;
		}

	public:
		void input() {
			cin >> a >> n;
			ms.resize(n);
			for (int f = 0; f < n; ++f) {
				cin >> ms.at(f);
			}
		}

		int solve() {
			if (a <= 1) {
				return n;
			}
			sort(ms.begin(), ms.end());
			int sol = n;
			for (int ma = 0; ma <= n; ++ma) {
				sol = min(sol, n - ma + greedyabsorb(a, ma));
			}
			return sol;
		}
};

int main(void) {
	int nt;
	cin >> nt;
	for (int znj = 0; znj < nt; ++znj) {
		osmos task;
		task.input();
		cout << "Case #" << (znj + 1) << ": " << task.solve() << endl;
	}
	return 0;
}
