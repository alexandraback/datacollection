#include <iostream>
#include <climits>
using namespace std;

typedef long double ld;

ld solve(ld C, ld F, ld X) {
	ld performance = 2.0;
	ld elapsed = 0.0;
	ld answer = (X / performance);
	for(int i = 1; i <= 100 * 1000 + 5; ++i) {
		elapsed += C / performance;
		performance += F;
		answer = min(answer, elapsed + X / performance);
	}
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	cout.precision(8);
	for(int t = 0; t < T; ++t) {
		ld C, F, X;
		cin >> C >> F >> X;
		printf("Case #%d: %.8Lf\n", t + 1, solve(C, F, X));
	}
}