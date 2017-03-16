#include <iostream>
#include <set>

#define mp make_pair

using namespace std;

typedef pair < pair <int, int>, int > piii;

set <piii> rowmemo, colmemo;
char board[55][55];
int rowCnt, colCnt;
bool fin;

/////Prototypes
void emptyboard(int, int);
void heightTwo(int, int,int);
void widthTwo(int, int,int);
void solveRowMajor(int, int, int);
void solveColMajor(int, int, int);
void printAnswer();
void printFullBoard();

/////main
int main()
{
	int T,R,C,M;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		rowmemo.clear();
		colmemo.clear();
		fin = false;
		cin >> R >> C >> M;

		cout << "Case #" << tt << ":\n";

		if (R == 1)
		{
			int i;
			for (i = 0; i < M; i++)
				cout << '*';
			for (; i < C - 1; i++)
				cout << '.';
			cout << "c\n";

			continue;
		}

		if (C == 1)
		{
			int j;
			for (j = 0; j < M; j++)
				cout << "*\n";
			for (; j < R - 1; j++)
				cout << ".\n";
			cout << "c\n";

			continue;
		}

		rowCnt = R;
		colCnt = C;

		if (M + 1 == R*C)
		{
			printFullBoard();
			continue;
		}

		if (M >= (R*C) - 3)
		{
			cout << "Impossible\n";
			continue;
		}

		solveRowMajor(0, 0, M);
		if (!fin)
			solveColMajor(0, 0, M);

		if (fin)
			printAnswer();
		else
			cout << "Impossible\n";

	}
}

/////Functions

void emptyboard(int curR, int curC)
{
	fin = true;
	for (int i = curR; i < rowCnt; i++)
	{
		for (int j = curC; j < colCnt; j++)
			board[i][j] = '.';
	}
	board[rowCnt - 1][colCnt - 1] = 'c';
}

void heightTwo(int curR, int curC,int rem)
{
	if (rem % 2)
		return;
	int j;
	for (j = curC; rem > 0; j++, rem -= 2)
		board[curR][j] = board[curR + 1][j] = '*';
	emptyboard(curR, j);
}

void widthTwo(int curR, int curC,int rem)
{
	if (rem % 2)
		return;
	int i;
	for (i = curR; rem > 0; i++, rem -= 2)
		board[i][curC] = board[i][curC + 1] = '*';
	emptyboard(i, curC);
}

void solveRowMajor(int curR, int curC, int rem)
{
	if (!rem)
	{
		emptyboard(curR, curC);
		return;
	}

	piii curConfig = mp(mp(curR, curC), rem);
	if (rowmemo.find(curConfig) != rowmemo.end())
		return;

	if (curR == rowCnt - 2)
	{
		heightTwo(curR, curC, rem);
		return;
	}

	if (curC == colCnt - 2)
	{
		widthTwo(curR, curC, rem);
		return;
	}

	if (fin)
		return;

	int i, j;
	for (j = curC; j<colCnt - 2 && rem>0; j++)
	{
		board[curR][j] = '*';
		rem--;
	}

	for (; j<colCnt - 2; j++)
		board[curR][j] = '.';

	if (rem > 1)
	{
		board[curR][j] = board[curR][j + 1] = '*';
		rem -= 2;
	}
	else
		board[curR][j] = board[curR][j + 1] = '.';

	solveRowMajor(curR + 1, curC, rem);

	if (fin)
		return;

	solveColMajor(curR + 1, curC, rem);

	if (!fin)
		rowmemo.insert(curConfig);
}

void solveColMajor(int curR, int curC, int rem)
{
	if (!rem)
	{
		emptyboard(curR, curC);
		return;
	}

	piii curConfig = mp(mp(curR, curC), rem);
	if (colmemo.find(curConfig) != colmemo.end())
		return;

	if (curR == rowCnt - 2)
	{
		heightTwo(curR, curC, rem);
		return;
	}

	if (curC == colCnt - 2)
	{
		widthTwo(curR, curC, rem);
		return;
	}

	if (fin)
		return;

	int i, j;
	for (i = curR; i < rowCnt - 2 && rem>0; i++)
	{
		board[i][curC] = '*';
		rem--;
	}
	for (; i < rowCnt - 2; i++)
		board[i][curC] = '.';

	if (rem>1)
	{
		board[i][curC] = board[i + 1][curC] = '*';
		rem -= 2;
	}
	else
		board[i][curC] = board[i + 1][curC] = '.';

	solveColMajor(curR, curC + 1, rem);

	if (fin)
		return;

	solveRowMajor(curR, curC + 1, rem);

	if (!fin)
		colmemo.insert(curConfig);
}

void printAnswer()
{
	for (int i = 0; i < rowCnt; i++)
	{
		for (int j = 0; j < colCnt; j++)
			cout << board[i][j];
		cout << endl;
	}
}

void printFullBoard()
{
	for (int i = 0; i < rowCnt; i++)
	{
		for (int j = 0; j < colCnt; j++)
			board[i][j] = '*';
	}
	board[rowCnt - 1][colCnt - 1] = 'c';
	printAnswer();
}
