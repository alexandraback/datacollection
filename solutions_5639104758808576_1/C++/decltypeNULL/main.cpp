#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n;
string s;

bool ok(int start)
{
	for (int i = 0; i <= n && i <= start; i++)
	{
		start += s[i] - '0';
		if (i == n) return true;
	}
	return false;
}

int solve_case()
{
	int L = 0, R = n, M;
	while (R - L > 1)
	{
		M = (L + R) / 2;
		if (ok(M)) R = M;
		else L = M;
	}
	if (ok(L)) return L;
	else return R;
}

void solve()
{
	ifstream in("input.txt");
	ofstream out("output.txt");

	int T;
	in >> T;
	for (int i = 1; i <= T; i++)
	{
		in >> n >> s;
		int temp = solve_case();
		out << "Case #" << i << ": " << temp << "\n";
	}

	in.close();
	out.close();
}

int main()
{
	solve();
	return 0;
}