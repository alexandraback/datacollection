#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;


#ifdef DEBUG
#define Dprintf(fmt, ...) fprintf(stderr, fmt, __VA_ARGS__);
#else
#define Dprintf(fmt, ...) 
#endif

int main(int argc, char const* argv[])
{
	int T;
	cin >> T;
	for (int ii = 0; ii < T; ii++) {
		int A, B;
		vector<double> p;
		cin >> A >> B;
		B = B - A;
		for (int i = 0; i < A; i++) {
			double buf;
			cin >> buf;
			p.push_back(buf);
		}
		double ans = 99999999.0; // INF

		// case 1
		{
			double st1, st2, ex;
			st1 = B + 1; st2 = B + 1 + A + B + 1;
			double pos1 = 1.0, pos2 = 0;
			for (int i = 0; i < p.size(); i++) {
				pos1 *= p.at(i);
			}
			pos2 = 1.0 - pos1;
			ex = pos1 * st1 + pos2 * st2;
			if (ex < ans) {
				ans = ex;
			}
			Dprintf("(pos, st) = (%lf, %.0lf) and (%lf, %.0lf)\n", pos1, st1, pos2, st2);
			Dprintf("case1: ex = %lf\n", ex);
		}
		// case 2
		{
			for (int i = 1; i <= A; i++) {
				double st1, st2, ex;
				st1 = i + i + B + 1; // no mis before i
				st2 = i + i + B + 1 + A + B + 1;
				double pos1 = 1, pos2;
				for (int j = 0; j < A-i; j++) {
					pos1 *= p.at(j);
				}
				pos2 = 1.0 - pos1;
				ex = pos1 * st1 + pos2 * st2;
				if (ex < ans) {
					ans = ex;
				}
				Dprintf("case2 (bs %d): ex = %lf\n", i, ex);
			}
		}
		// case 3
		{
			double ex = 1 + A + B + 1;
			if (ex < ans) {
				ans = ex;
			}
			Dprintf("case3: ex = %lf\n", ex);
		}

		printf("Case #%d: %.6lf\n", ii + 1, ans);
	}
	return 0;
}
