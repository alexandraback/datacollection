#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int CaseNum;
	cin >> CaseNum;
	for (int Case = 1; Case <= CaseNum; Case++)
	{
		cout << "Case #" << Case << ":" << endl;
		
		int R, C, M;
		cin >> R >> C >> M;
		bool impossible = false;

		char board[51][51];
		for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) board[i][j] = '.';
		for (int i = 0; i < R; i++) board[i][C] = '\0';
		board[R - 1][C - 1] = 'c';

		// cases
		if (C == 1) {
			for (int i = 0; i < M; i++) board[i][0] = '*';
		}
		else if (R == 1) {
			for (int i = 0; i < M; i++) board[0][i] = '*';
		}

		else if (M <= (R - 2) * (C - 2)) 
		{
			for (int i = 0; i < R - 2; i++) {
				for (int j = 0; j < C - 2; j++) {
					if (M == 0) break;
					board[i][j] = '*';
					M--;
				}
				if (M == 0) break;
			}
		}

		else 
		{
			int a = R * C - M;
			M -= (R - 2) * (C - 2);

			if (M % 2 == 0)
			{
				if (a < 4) impossible = true;
				else {
					for (int i = 0; i < R - 2; i++)	for (int j = 0; j < C - 2; j++)
						board[i][j] = '*';

					for (int i = 0; i < R - 2; i++) {
						if (M == 0) break;
						board[i][C - 2] = board[i][C - 1] = '*';
						M -= 2;
					}
					for (int i = 0; i < C - 2; i++) {
						if (M == 0) break;
						board[R - 2][i] = board[R - 1][i] = '*';
						M -= 2;
					}
				}
			}

			else 
			{
				if (1 < a && a < 9) impossible = true;
				else if (a == 1) {
					for (int i = 0; i < R; i++) for (int j = 0; j < C; j++)
						board[i][j] = '*';
					board[R - 1][C - 1] = 'c';
				}
				else if (R == 2 || C == 2) {
					impossible = true;
				}
				else {
					for (int i = 0; i < R - 2; i++)	for (int j = 0; j < C - 2; j++)
						board[i][j] = '*';
					board[R - 3][C - 3] = '.';
					M++;

					for (int i = 0; i < R - 3; i++) {
						if (M == 0) break;
						board[i][C - 2] = board[i][C - 1] = '*';
						M -= 2;
					}
					for (int i = 0; i < C - 3; i++) {
						if (M == 0) break;
						board[R - 2][i] = board[R - 1][i] = '*';
						M -= 2;
					}
				}
			}
		}

		// printing section
		if (impossible)	
			cout << "Impossible" << endl;
		else 
			for (int i = 0; i < R; i++) 
				cout << board[i] << endl;

	}
}