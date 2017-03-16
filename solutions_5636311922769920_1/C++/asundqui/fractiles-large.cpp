#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double GetLocation(int coord, int K, int remaining_C)
{
	long double x = 0;
	if (remaining_C > 1)
		x = GetLocation((coord == (K - 1)) ? coord : (coord+1), K, remaining_C - 1)*K;
	return x + coord;
}

int main()
{
	int T;
	cin >> T;
	for (int case_num = 1; case_num <= T; ++case_num)
	{
		int K, C, S;
		cin >> K >> C >> S;

		if ((S*C) < K)
		{
			cout << "Case #" << case_num << ": IMPOSSIBLE" << endl;
			continue;
		}

		cout << "Case #" << case_num << ":";
		for (int i = 0; (i*C) < K; ++i)
			cout << " " << setprecision(20) << (GetLocation(i * C, K, C) + 1);
		cout << endl;
	}
	return 0;
}
