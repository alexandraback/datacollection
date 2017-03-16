#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;

long double C, F, X, best, next;

inline long double solve(int a)
{
	long double time = 0.L;
	long double rate = 2.L;
	for (; a; a--)
	{
		time += C / rate;
		rate += F;
	}
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
