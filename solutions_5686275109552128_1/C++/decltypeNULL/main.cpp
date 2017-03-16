#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int ceil(int A, int B)
{
	return (A + B - 1) / B;
}

const int MAX = 1009;
int D;
int P[MAX];

int solve_Q(int Q)
{
	int result = 0;
	for (int i = 0; i < D; i++)
	{
		result += ceil(P[i], Q);
	}
	return result - D + Q;
}

int solve_case()
{
	int result = solve_Q(1);
	for (int i = 2; i < MAX; i++) result = min(result, solve_Q(i));
	return result;
}

void solve()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		in >> D;
		for (int i = 0; i < D; i++) in >> P[i];

		int temp = solve_case();
		out << "Case #" << t << ": " << temp << "\n";
	}

	in.close();
	out.close();
}


int main()
{
	solve();
	return 0;
}