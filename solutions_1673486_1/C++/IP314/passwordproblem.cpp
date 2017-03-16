#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class passwordproblem
{
	private:
		int at, lt;
		vector<long double> pep;

		long double sol;

	public:
		passwordproblem(){}

		void input() {
			scanf("%d%d", &at, &lt);
			pep.resize(at);
			for (int f = 0; f < at; ++f) {
				scanf("%Lf", &(pep.at(f)));
			}
		}

		void solve() {
			sol = 2 + lt;
			long double ppr = 1.;
			for (int f = 0; f < at; ++f) {
				sol = min(sol, lt - at + 1 + 2 * (at - f) + (1. - ppr) * (lt + 1));
				ppr *= pep.at(f);
			}
			sol = min(sol, lt - at + 1 + (1. - ppr) * (lt + 1));
		}

		void output(int caseno) {
			printf("Case #%d: %.8Lf\n", caseno, sol);
		}
};

int main(void) {
	int nt;
	scanf("%d", &nt);
	for(int znj = 1; znj <= nt; ++znj) {
		passwordproblem task;
		task.input();
		task.solve();
		task.output(znj);
	}
	return 0;
}
