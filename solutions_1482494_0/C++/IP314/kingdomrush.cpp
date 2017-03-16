#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

class kingdomrush
{
	private:
		int n;
		vector<pii> st;

		int sol;

	public:
		kingdomrush(){}

		void input() {
			scanf("%d", &n);
			st.resize(n);
			for (int f = 0; f < n; ++f) {
				scanf("%d%d", &(st.at(f).second), &(st.at(f).first));
			}
		}

		void solve() {
			sort(st.begin(), st.end());
			sol = 0;
			vector<int> pea(n, 0);
			int nc2 = 0;
			int csk = 0;
			while (nc2 < n) {
				int cb01 = -1, cb12 = -1, cb02 = -1;
				for (int f = 0; f < n; ++f) {
					if ((pea.at(f) == 0) && (st.at(f).second <= csk)) {
						cb01 = f;
					}
					if ((pea.at(f) == 1) && (st.at(f).first <= csk)) {
						cb12 = f;
					}
					if ((pea.at(f) == 0) && (st.at(f).first <= csk)) {
						cb02 = f;
					}
				}
				++sol;
				if (cb02 > -1) {
					csk += 2;
					pea.at(cb02) = 2;
					++nc2;
				} else if (cb12 > -1) {
					csk += 1;
					pea.at(cb12) = 2;
					++nc2;
				} else if (cb01 > -1) {
					csk += 1;
					pea.at(cb01) = 1;
				} else {
					sol = -1;
					return;
				}
			}
		}

		void output(int caseno) {
			printf("Case #%d: ", caseno);
			if (sol < 0) {
				printf("Too Bad");
			} else {
				printf("%d", sol);
			}
			printf("\n");
		}
};

int main(void) {
	int nt;
	scanf("%d", &nt);
	for(int znj = 1; znj <= nt; ++znj) {
		kingdomrush task;
		task.input();
		task.solve();
		task.output(znj);
	}
	return 0;
}
