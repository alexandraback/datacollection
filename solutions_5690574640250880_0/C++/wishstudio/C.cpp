#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char ans[100][100];

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++)
	{
		bool swapped = false, impossible = false;
		int R, C, M, MM;
		cin >> R >> C >> M;
		MM = M;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
				ans[i][j] = '*';
			ans[i][C] = 0;
		}
		M = R * C - M;

		if (M == 1)
			ans[0][0] = 'c';
		else if (R == 1)
		{
			for (int j = 1; j < M; j++)
				ans[0][j] = '.';
			ans[0][0] = 'c';
		}
		else if (C == 1)
		{
			for (int i = 1; i < M; i++)
				ans[i][0] = '.';
			ans[0][0] = 'c';
		}
		else if (M < 4 || M == 5 || M == 7)
			impossible = true;
		else if (R == 2)
		{
			for (int j = 0; M > 1; j++)
			{
				ans[0][j] = ans[1][j] = '.';
				M -= 2;
			}
			ans[0][0] = 'c';
			impossible = (M == 1);
		}
		else if (C == 2)
		{
			for (int i = 0; M > 1; i++)
			{
				ans[i][0] = ans[i][1] = '.';
				M -= 2;
			}
			ans[0][0] = 'c';
			impossible = (M == 1);
		}
		else
		{
			ans[0][0] = 'c';
			ans[0][1] = ans[1][0] = ans[1][1] = '.';
			if (M >= 6)
			{
				ans[0][2] = ans[1][2] = '.';
				if (M >= 8)
				{
					ans[2][0] = ans[2][1] = '.';
					M -= 8;

					int count = min(M / 2, C - 3);
					M -= count * 2;
					for (int i = 0; i < count; i++)
						ans[0][3 + i] = ans[1][3 + i] = '.';

					count = min(M / 2, R - 3);
					M -= count * 2;
					for (int i = 0; i < count; i++)
						ans[3 + i][0] = ans[3 + i][1] = '.';

					for (int i = 2; i < R && M > 0; i++)
						for (int j = 2; j < C && M > 0; j++)
						{
							ans[i][j] = '.';
							M--;
						}
				}
			}
		}
		cout << "Case #" << z << ":" << endl;
		if (impossible)
			cout << "Impossible" << endl;
		else
			for (int i = 0; i < R; i++)
				cout << ans[i] << endl;
		if (!impossible)
		{
			for (int i = 0; i < R; i++)
				for (int j = 0; j < C; j++)
					if (ans[i][j] == '*')
						MM--;
			if (MM != 0 || ans[0][0] != 'c')
				cout << "ERROR" << endl;
		}
	}
	return 0;
}
