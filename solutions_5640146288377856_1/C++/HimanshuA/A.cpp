#include<iostream>

using namespace std;

void main()
{
	int T, R, C, W, total;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> R >> C >> W;

		total = 0;

		while (true)
		{
			total += R - 1;

			if (2 * W <= C)
			{
				total++;
				C -= W;
			}
			else if (C == W)
			{
				total += W;
				break;
			}
			else
			{
				total += W + 1;
				break;
			}
		}

		cout << "Case #" << t << ": " << total << endl;
	}
}