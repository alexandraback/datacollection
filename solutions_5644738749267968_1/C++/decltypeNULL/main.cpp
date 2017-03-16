//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cassert>
using namespace std;

const int MAXN = 1000 + 9;
int N;
double a[MAXN];
double b[MAXN];

int solve_deceitful()
{
	//int iter_L = 0;
	int iter_R = N - 1;
	int result = 0;

	for (int i = N - 1; i >= 0; i--)
	{
		if (a[iter_R] > b[i])
		{
			result++;
			iter_R--;
		}
		//else iter_L++;
	}

	return result;
}

int solve_war()
{
	swap(a, b);
	int temp = solve_deceitful();
	swap(a, b);
	return N-temp;
}

void solve_D(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		in >> N;
		for (int i = 0; i < N; i++) in >> a[i];
		for (int i = 0; i < N; i++) in >> b[i];

		sort(a, a + N);
		sort(b, b + N);

		out << "Case #" << t << ": " << solve_deceitful() << ' ' << solve_war() << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	//solve_A();
	//solve_B();
	//solve_C();
	solve_D();
	return 0;
}