#include <iostream>
#include <fstream>
using namespace std;

int e[16], time;
int state[10] = {15, 15*16, 15*16*16, 15*16*16*16, 4369, 4369*2, 4369*4, 4369*8, 33825, 4680};
char a[4][4];

bool check(const char &sign) {
	int bitmap = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			if (a[i][j] == sign || a[i][j] == 'T')
				bitmap |= e[(i << 2) + j];
	cout << bitmap << endl;
	for (int i = 0; i < 10; ++i)
		if ((bitmap & state[i]) == state[i])
			return 1;
	return 0;
}

int main()
{
	ifstream read("a.in");
	ofstream write("a.out");
	read >> time;
	e[0] = 1;
	for (int i = 1; i < 16; ++i)
		e[i] = e[i - 1] << 1;
	for (int ite = 0; ite < time; ++ite) {
		int remain = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				read >> a[i][j];
				remain += (a[i][j] == '.');
			}
		write << "Case #" << ite + 1 << ": ";
		if (check('X')) write << "X won" << endl;
		else if (check('O')) write << "O won" << endl;
		else if (remain > 0) write << "Game has not completed" << endl;
		else write << "Draw" << endl;
	}
	return 0;
}
