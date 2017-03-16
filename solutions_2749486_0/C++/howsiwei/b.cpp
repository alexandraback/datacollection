#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

void solve()
{
	int X, Y;
	int x, y;
	fin >> X >> Y;
	x = X;
	if (x < 0) x = -x;
	y = Y;
	if (y < 0) y = -y;
	string ans;

	if (Y < 0) {
		for (int i = 1; i <= y; ++i) {
			ans += "NS";
		}
	}
	else if (Y > 0) {
		for (int i = 1; i <= y; ++i) {
			ans += "SN";
		}
	}
	if (X < 0) {
		for (int i = 1; i <= x; ++i) {
			ans += "EW";
		}
	}
	else if (X > 0) {
		for (int i = 1; i <= x; ++i) {
			ans += "WE";
		}
	}

	fout << ans;
}

int main()
{
	int n;
	fin >> n;

	for (int case_num = 1; case_num <= n; ++case_num) {
		fout << "Case #" << case_num << ": ";
		solve();
		fout << '\n';
	}

	return 0;
}
