#include <iostream>
#include <cstring>
using namespace std;

main()
{
	int T;
	cin >> T;

	for (int in = 1; in <= T; in++)
	{
		cout << "Case #" << in << ": ";
		int N, M;
		cin >> N >> M;

		int lawn[N][M];
		int rowMajor[N];
		int colMajor[M];
		memset(rowMajor, -1, sizeof(rowMajor));
		memset(colMajor, -1, sizeof(colMajor));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> lawn[i][j];
				if (rowMajor[i] == -1 || rowMajor[i] < lawn[i][j])
				{
					rowMajor[i] = lawn[i][j];
				}
				if (colMajor[j] == -1 || colMajor[j] < lawn[i][j])
				{
					colMajor[j] = lawn[i][j];
				}
			}
		}

		bool fPossible = true;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (lawn[i][j] < rowMajor[i] && lawn[i][j] < colMajor[j])
				{
					fPossible = false;
					break;
				}
			}
			if (!fPossible)
			{
				break;
			}
		}
		if (fPossible)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}