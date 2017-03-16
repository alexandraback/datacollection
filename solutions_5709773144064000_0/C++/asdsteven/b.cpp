#include <iostream>
#include <iomanip>
using namespace std;

double solve() {
	double C, F, X;
	cin >> C >> F >> X;
	double ans = X / 2;
	double wer = 0;
	double prod = 2;
	while (wer + C / prod + X / (prod + F) < ans) {
		ans = wer + C / prod + X / (prod + F);
		wer += C / prod;
		prod += F;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
		cout << "Case #" << i << ": " << setiosflags(ios::fixed) << setprecision(7) << solve() << endl;
}
