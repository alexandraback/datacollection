#include <iostream>
#include <iomanip>
using namespace std;

int T;
double C, F, X;

void solve(int tc)
{
	cin >> C >> F >> X;

	double total = 0.0;
	double rate = 2.0;

	while (C/F < X/(rate + F)) {
		total += C/rate;
		rate += F;
	}
	total += X/rate;

	cout << "Case #" << tc << ": ";
	cout << total << endl;
}

int main()
{
	cin >> T;
	cout << fixed << setprecision(7);
	for (int i = 1; i <= T; i++) {
		solve(i);
	}

	return 0;
}