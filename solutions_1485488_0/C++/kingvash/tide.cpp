#include<iostream>
#include<fstream>

using namespace std;

int t[101][101];
int f[101][101];
int c[101][101];
bool change[101][101];
int H0;

ifstream inFile;
ofstream outFile;


inline int wAt(int t)
{
	if (t < 0)
		return H0;

	return H0 - t;
}


bool attemptMove(int si, int sj, int ei, int ej)
{
	int curT = t[si][sj];

	if (!((f[si][sj] + 50 <= c[ei][ej]) && (f[ei][ej] + 50 <= c[ei][ej]) && (f[ei][ej] + 50 <= c[si][sj])))
		return false;

	
	int wLevel = wAt(curT);
	if (wLevel + 50 > c[ei][ej])
	{
		// required to wait some more time
		double oldT = curT;
		curT = H0 - (c[ei][ej] - 50);
		wLevel = wAt(curT);

		if (curT < oldT)
			cout << "Wlevel ERROR!" << endl;
	}

	if (curT < 0)
	{
		//time has not started ticking yet
		if (t[ei][ej] != -1)
		{
			t[ei][ej] = -1;
			return true;
		}
		return false;
	}

	if (f[si][sj] + 20 <= wLevel)
	{

		if (curT + 10 < t[ei][ej])
		{
			t[ei][ej] = curT + 10;
			return true;
		}
	}
	else
	{
		if (curT + 100 < t[ei][ej])
		{
			t[ei][ej] = curT + 100;
			return true;
		}
	}
	return false;
}


void solve()
{
	int N, M, cases;
	inFile >> cases;
	for (int caseNum = 1; caseNum <= cases; caseNum++)
	{
			inFile >> H0 >> N >> M;

			cerr << H0 << " " << N << " " << M << endl;

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					inFile >> c[i][j];

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
					inFile >> f[i][j];

			for (int i = 0; i < N; i++)
				for (int j = 0; j < M; j++)
				{
					t[i][j] = 100000000;
					change[i][j] = -1;
				}
			t[0][0] = -1;

			if (caseNum == 26)
			{
					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < M; j++)
						{
							cout << f[i][j] << " ";
						}
						cout << endl;
					}
					cout << endl << endl;

					for (int i = 0; i < N; i++)
					{
						for (int j = 0; j < M; j++)
						{
							cout << c[i][j] << " ";
						}
						cout << endl;
					}
					cout << endl << endl;
			}

			bool gChange = true;
			while (gChange)
			{
				gChange = false;
				for (int i = 0; i < N; i++)
					for (int j = 0; j < M; j++)
					{
						if (i > 0)
							gChange |= attemptMove(i,j, i-1, j);
						if ((i+1) < N)
							gChange |= attemptMove(i,j, i+1, j);
						if (j > 0)
							gChange |= attemptMove(i,j, i, j-1);
						if ((j+1) < M)
							gChange |= attemptMove(i,j, i, j+1);
					}

				if (caseNum == 26)
				{
						for (int i = 0; i < N; i++)
						{
							for (int j = 0; j < M; j++)
							{
								cout << t[i][j] << " ";
							}
							cout << endl;
						}
						cout << endl << endl;
				}
			}
			if (t[N-1][M-1] < 0)
				t[N-1][M-1] = 0;

			cout << "Case #" << caseNum << ": " << t[N-1][M-1]/10.0 << endl;
			outFile << "Case #" << caseNum << ": ";
			outFile << t[N-1][M-1] / 10 << "." << t[N-1][M-1] % 10 << endl;
	}
}



int main(void)
{
//	inFile.open("test.in", ios::in);
//	outFile.open("test.out", ios::out);

	inFile.open("B-small-attempt0.in", ios::in);
	outFile.open("B-small-attempt0.out", ios::out);

	solve();

	inFile.close();
	outFile.close();
	return 0;
}

