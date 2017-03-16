#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

long double C, F, X, best, next;

long double lastTime;
long double lastRate;
inline long double solve(int a)
{
	if (a == 0) {
		lastTime = 0.L;
		lastRate = 2.L;
		return X / 2.L;
	}
	long double time = lastTime;
	long double rate = lastRate;
	time += C / rate;
	rate += F;
	lastTime = time;
	lastRate = rate;
	time += X / rate;
	return time;
}

int main()
{
	cout << setprecision(7) << fixed;
	int T; cin >> T;
	for (int caseNum = 1; caseNum <= T; caseNum++)
	{
		// Read in constants
		cin >> C >> F >> X;
		best = solve(0);
		next = solve(1);
		for (int i = 2; next < best; i++)
		{
			best = next;
			next = solve(i);
		}
		cout << "Case #" << caseNum << ": " << best << endl;
	}
	return 0;
}
