#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int t, r, n, m, k, i, j, x, a, b, c, p;
	int pr[8];
	int ex[8];
	int max = 0, cur;
	int best[3];
	int coe[8][3];
	cin >> t >> r >> n >> m >> k;
	
	
	coe[0][0] = 0; coe[0][1] = 0; coe[0][2] = 0;
	coe[1][0] = 0; coe[1][1] = 0; coe[1][2] = 1;
	coe[2][0] = 0; coe[2][1] = 1; coe[2][2] = 0;
	coe[3][0] = 0; coe[3][1] = 1; coe[3][2] = 1;
	coe[4][0] = 1; coe[4][1] = 0; coe[4][2] = 0;
	coe[5][0] = 1; coe[5][1] = 0; coe[5][2] = 1;
	coe[6][0] = 1; coe[6][1] = 1; coe[6][2] = 0;
	coe[7][0] = 1; coe[7][1] = 1; coe[7][2] = 1;
	
	cout << "Case #1:" << endl;
	for (x = 1; x <= r; ++x)
	{
		for (i = 0; i < 7; ++i)
		{
			cin >> pr[i];
			ex[i] = 0;
		}
		max = 0;
		for (a = 2; a < 6; ++a)
			for (b = a; b < 6; ++b)
				for (c = b; c < 6; ++c)
				{
					for (i = 0; i < 8; ++i)
					{
						p = 1;
						if (coe[i][0])
							p = a;
						if (coe[i][1])
							p *= b;
						if (coe[i][2])
							p *= c;
						for (j = 0; j < 7; ++j)
							if (p == pr[j])
								ex[j]++;
					}
					cur = 1;
					for (i = 0; i < 7; ++i)
					{
						cur *= ex[i];
						ex[i] = 0;
					}
					if (cur > max)
					{
						max = cur;
						best[0] = a;
						best[1] = b;
						best[2] = c;
					}
				}
		cout << best[0] << best[1] << best[2] << endl;
	}

	return 0;
}
