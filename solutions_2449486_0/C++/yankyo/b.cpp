
#include <iostream>

using namespace std;


int pole[200][200];
int stav[200][200];
int N, M;


bool lowercol(int c)
{
	bool res = false;
	int max = 0;
	for (int i = 0; i < N; i++) if (pole[i][c] > max) max = pole[i][c];
	for (int i = 0; i < N; i++)
	{
		if (stav[i][c] > max)
		{
			stav[i][c] = max;
			res = true;
		}
	}
	return res;
}

bool lowerrow(int r)
{
	bool res = false;
	int max = 0;
	for (int i = 0; i < M; i++) if (pole[r][i] > max) max = pole[r][i];
	for (int i = 0; i < M; i++)
	{
		if (stav[r][i] > max)
		{
			stav[r][i] = max;
			res = true;
		}
	}
	return res;
}

bool done()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (pole[i][j] != stav[i][j]) return false;
		}
	}
	return true;
}


int main()
{
	int C;
	cin >> C;

	for (int c = 0; c < C; c++)
	{
		cin >> N >> M;
		for (int n = 0; n < N; n++)
		{
			for (int m = 0; m < M; m++)
			{
				cin >> pole[n][m];
				stav[n][m] = 100;
			}
		}

		bool cont = true;

		while (cont)
		{
			cont = false;
			for (int i = 0; i < N; i++) cont = lowerrow(i) || cont;
			for (int j = 0; j < M; j++) cont = lowercol(j) || cont;
		}

		cout << "Case #" << (c+1) << ": " << (done() ? "YES" : "NO") << endl;
	}

	return 0;
}
