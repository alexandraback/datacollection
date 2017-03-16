//#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

double C, F, X;
const double INF = 1E10;
const int MAX_FARMS = 1000 * 1000;

double solve(void)
{
	double first_part = 0.0;
	double result = INF;

	for (int farms = 0; farms <= MAX_FARMS; farms++)
	{
		result = min(result, first_part + X / (2 + farms*F));
		first_part += C / (2 + farms*F);
	}

	return result;
}

void solve_B(void)
{
	ifstream in("input.txt");
	ofstream out("output.txt");
	out << setprecision(10);
	
	int T;
	in >> T;
	for (int t = 1; t <= T; t++)
	{
		in >> C >> F >> X;
		out << "Case #" << t << ": " << solve() << '\n';
	}

	in.close();
	out.close();
}

int main()
{
	//solve_A();
	solve_B();
	return 0;
}