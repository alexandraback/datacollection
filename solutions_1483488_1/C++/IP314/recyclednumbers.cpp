#include <cstdio>
using namespace std;

class recyclednumbers
{
	private:
		int lb, ub;

		int sol;

		int countdigits(int n) {
			int ndd = 0;
			for (; n > 0; n /= 10, ++ndd);
			return ndd;
		}

		int pow10(int p) {
			int p10 = 1;
			for (; p > 0; --p, p10 *= 10);
			return p10;
		}

		int rotate(int n, int mdxb) {
			return 10 * (n % mdxb) + (n / mdxb);
		}

	public:
		recyclednumbers() {}

		void input() {
			scanf("%d%d", &lb, &ub);
		}

		void solve() {
			int ndl = countdigits(lb);
			int mdxb = pow10(ndl - 1);
			sol = 0;
			for (int cc = lb; cc <= ub; ++cc) {
				for (int c2 = rotate(cc, mdxb); c2 != cc; c2 = rotate(c2, mdxb)) {
					if ((c2 > cc) && (c2 <= ub)) {
						++sol;
					}
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
		recyclednumbers task;
		task.input();
		task.solve();
		task.output(znj);
	}
	return 0;
}
