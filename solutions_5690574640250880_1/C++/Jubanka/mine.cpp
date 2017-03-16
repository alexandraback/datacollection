#include <iostream>

using namespace std;

#define MIN(x, y) ( ((x) < (y)) ? (x) : (y))
#define MAX(x, y) ( ((x) > (y)) ? (x) : (y))

char board[50][50], tmpb[50][50];
int R, C, M;

inline bool blocked(int x, int y)
{
	if (x >= C || y >= R || x < 0 || y < 0)	return true;
	return (board[y][x] == '*');
}

void print(ostream &s = cout)
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			s << board[i][j];
		}
		s << endl;
	}
}

void printb(void)
{
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cerr << tmpb[i][j];
		}
		cerr << endl;
	}
}

bool floodRow(int r, int c, int res)
{
	//cerr << "floodRow" << endl;

	int cnt = 0;
	int xs;
	for (xs = 0; ! blocked(xs, r); xs++, cnt++);
	
	int put;
	if (cnt	<= M)
		put = cnt;
	else if (M + res < cnt)
		put = M;
	else
		put = cnt - res;
	//cerr << M << " " << put << " " << cnt << " " << r << " " << c << endl;
	if (put <= 0)	return false;

	for (int x = 0; x < put; board[r][xs - 1 - x] = '*', x++);
	//print(cerr);
	M -= put;
	return (put == cnt);
}

bool floodCol(int r, int c, int res)
{
	//cerr << "floodCol" << endl;

	int cnt = 0;
	int ys;
	for (ys = R - 1; ! blocked(C  - 1 - c, ys); ys--, cnt++);

	int put;
	if (cnt	<= M)
		put = cnt;
	else if (M + res < cnt)
		put = M;
	else
		put = cnt - res;
	//cerr << M << " " << put << " " << cnt << " " << r << " " << c << endl;
	if (put <= 0)	return false;

	for (int y = 0; y < put; board[ys + 1 + y][C - 1 - c] = '*', y++);
	//print(cerr);
	M -= put;
	return (put == cnt);
}

bool solve(void)
{
	int i, j, m;

	m = MIN(R, C);
	if (R * C - M == 0)	return false;

	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			board[i][j] = '.';

	int rtg = 0, ctg = 0;
	while (true) {
		if (M == 0)	return true;
		bool row = (R - rtg >= C - ctg);
		if (row) {
			if (! floodRow(rtg, ctg, 2)) {
				rtg++;
				if (! floodCol(rtg, ctg, 2))
					return false;
				else
					ctg++;
			} else
				rtg++;
		} else {
			if (! floodCol(rtg, ctg, 2)) {
				ctg++;
				if (! floodRow(rtg, ctg, 2))
					return false;
				else
					rtg++;
			} else
				ctg++;
		}
	}
}

bool hasstar(int r, int c)
{
	for (int i = MAX(0, r - 1); i <= MIN(r + 1, R - 1); i++)
		for (int j = MAX(0, c - 1); j <= MIN(c + 1, C - 1); j++)
			if (tmpb[i][j] == '*')
				return true;
	return false;
}

void vr(int r, int c)
{
	//cerr << r << c << hasstar(r,c) << endl;
	if (tmpb[r][c] == 'X')	return;
	tmpb[r][c] = 'X';
	if (hasstar(r, c))		return;
	for (int i = MAX(0, r - 1); i <= MIN(r + 1, R - 1); i++)
		for (int j = MAX(0, c - 1); j <= MIN(c + 1, C - 1); j++) {
			//cerr << "Rec" << i << j << "-" << MAX(0, c-1) << MIN (c+1, C -1) << endl;
			vr(i, j);
			//cerr << "Recout" << i << j << endl;
		}
}

bool verify(void)
{
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			tmpb[i][j] = board[i][j];
	vr(R - 1, 0);
	//printb();
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (tmpb[i][j] == '.')
				return false;
	return true;
}

int main(void)
{
	int T, Mo;

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> R >> C >> M;
		Mo = M;
		cout << "Case #" << t << ":" << endl;
		cerr << "Case #" << t << ":" << endl;
		solve();
		if (M == 0 && verify()) {
			board[R - 1][0] = 'c';
			print();
		} else {
			cout << "Impossible" << endl;
			//cerr << M << " " << Mo << endl;
			//print(cerr);
			//printb();
		}
	}
	return 0;
}
