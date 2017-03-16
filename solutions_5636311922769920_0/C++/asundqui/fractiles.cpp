#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int K, C, S;
		cin >> K >> C >> S;

		if (K != S)
		{
			cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
			continue;
		}
		long double x = 1;
		long double stride = 1;
		for (int i = 1; i < C; ++i)
			stride *= K;

		cout << "Case #" << case_num << ":";
		for (int i = 0; i < S; ++i)
		{
			cout << " " << setprecision(20) << x;
			x += stride;
		}
		cout << endl;
	}
	return 0;
}
