#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class dancingwiththegooglers
{
	private:
		int n, sur, thr;
		vector<int> psums;

		int sol;

	public:
		dancingwiththegooglers(){}

		void input() {
			scanf("%d%d%d", &n, &sur, &thr);
			psums.resize(n);
			for (int f = 0; f < n; ++f) {
				scanf("%d", &(psums.at(f)));
			}
		}

		void solve() {
			sol = 0;
			int surc = sur;
			for (vector<int>::const_iterator fi = psums.begin(); fi < psums.end(); ++fi) {
				if (thr + 2 * (thr - 1) <= *fi) {
					++sol;
				} else if ((surc > 0) && (thr >= 2) && ((thr + 2 * (thr - 2) <= *fi))) {
					--surc;
					++sol;
				}
			}
		}

		void output(int caseno) {
			printf("Case #%d: %d\n", caseno, sol);
		}
};

int main(void) {
	int nt;
	scanf("%d", &nt);
	for(int znj = 1; znj <= nt; ++znj) {
		dancingwiththegooglers task;
		task.input();
		task.solve();
		task.output(znj);
	}
	return 0;
}
