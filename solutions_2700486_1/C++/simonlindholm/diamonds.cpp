#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

vector<vector<double> > mem(2000, vector<double>(2000, -2));
double prob(int rem, int remRight) {
	if (remRight <= 0)
		return 1;
	if (remRight > rem)
		return 0;
	double& res = mem[rem][remRight];
	if (res > -1)
		return res;
	return res = (prob(rem-1, remRight) + prob(rem-1, remRight-1)) / 2;
}

double solve() {
	int N, X, Y;
	cin >> N >> X >> Y;
	int which = (abs(X) + Y) / 2;
	int fallen = 0;
	int nextfall = 1;
	int iteration = 0;
	for (;;) {
		if (fallen + nextfall <= N) {
			fallen += nextfall;
			++iteration;
			nextfall += 4;
			continue;
		}
		break;
	}
	// 'iteration' is the incomplete iteration.
	if (which < iteration)
		return 1;
	if (which > iteration)
		return 0;

	N -= fallen;
	int maxh = iteration * 2;

	// there are N diamonds falling, and the maximum tower height is 'iteration*2'.
	// What is the probability that >= Y+1 fall on the right side?

	if (maxh == Y)
		return 0;

	if (maxh + Y + 1 <= N)
		return 1; // forced to happen

	// otherwise not forced to happen, so we can allow arbitrary stacks on each side (not just maxh)

	return prob(N, Y+1);
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cout << "Case #" << i << ": " << setprecision(10) << fixed << solve() << endl;
	}
}
