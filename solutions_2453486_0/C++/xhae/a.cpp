#include <iostream>
#include <string>

using namespace std;

int main(void)
{
	int T;
	cin >> T;
	for(int caseN=1;caseN<=T;caseN++)
	{
		cout << "Case #" << caseN << ": ";
		string str[4];
		bool isEmpty = false;
		int tx, ty;
		for(int i=0;i<4;i++) 
		{
			cin >> str[i];
			for(int j=0;j<4;j++) if(str[i][j] == '.') isEmpty = true; else if (str[i][j] == 'T') { tx = j; ty = i; }
		}

		str[ty][tx] = 'X';
		bool diag[2] = {true, true};
		bool isAble = false;
		for(int i=0;i<4;i++)
		{
			if(str[i][i] != 'X') diag[0] = false;
			if(str[i][3 - i] != 'X') diag[1] = false;
			bool hor = true, ver = true;
			for(int j=0;j<4;j++)
			{
				if(str[i][j] != 'X') hor = false;
				if(str[j][i] != 'X') ver = false;
			}
			if(hor || ver) isAble = true;
		}

		if(diag[0] || diag[1]) isAble = true;

		if(isAble) { cout << "X won" << endl; continue; }

		str[ty][tx] = 'O';
		diag[0] = diag[1] = true;
		isAble = false;
		for(int i=0;i<4;i++)
		{
			if(str[i][i] != 'O') diag[0] = false;
			if(str[i][3 - i] != 'O') diag[1] = false;
			bool hor = true, ver = true;
			for(int j=0;j<4;j++)
			{
				if(str[i][j] != 'O') hor = false;
				if(str[j][i] != 'O') ver = false;
			}
			if(hor || ver) isAble = true;
		}

		if(diag[0] || diag[1]) isAble = true;

		if(isAble) { cout << "O won" << endl; continue; }

		if(isEmpty) { cout << "Game has not completed" << endl; continue; }
		cout << "Draw" << endl;
	}

	return 0;
}
