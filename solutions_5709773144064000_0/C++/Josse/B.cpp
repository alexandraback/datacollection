#include <iostream>
#include <cassert>

using namespace std;

long double solve() {
	long double C, F, X;
	cin >> C >> F >> X;
	assert(C >= 1.0L && C <= 10000.0L);
	assert(F >= 1.0L && F <= 100.0L);
	assert(X >= 1.0L && X <= 100000.0L);
	long double bovengrens = X / C - 1.0L - 2.0L / F;
	long double antwoord = 0.0L;
	long double rate = 2.0L;
	for (int i = 0; i <= bovengrens; i++) {
		antwoord += C / rate;
		rate += F;
	}
	return antwoord + X / rate;
}

int main() {
	int T;
	cin >> T;
	cout.setf(ios::fixed);
	cout.precision(10);
	for (int i = 0; i < T; i++) {
		cout << "Case #" << (i + 1) << ": " << solve() << endl;
	}
	return 0;
}
