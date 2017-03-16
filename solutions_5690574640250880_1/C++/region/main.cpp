#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int** copy(int** t, int x, int y)
{
	int ** ret = new int*[x];
	for (int  i = 0; i < x; i++)
	{
		ret[i] = new int[y];
		for (int j = 0; j < y; j++)
		{
			ret[i][j] = t[i][j];
		}
	}
	return ret;
}

string fill(int x, int y, int w, int h, int rem, int** t)
{
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (x + i >= 0 && x + i < w && y + j >= 0 && y + j < h)
			{
				if (t[x + i][y + j] == 0)
				{
					t[x + i][y + j] = 2;
					rem--;
				}
			}
		}
	}
	t[x][y] = 1;
	if (rem == 0)
	{
		string ret = "";
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (i == 0 && j == 0)
					ret += "c";
				else
					ret += ((t[j][i] == 0) ? "*" : ".");
			}
			ret += "\n";
		}
		return ret;
	}
	else if (rem < 0)
		return "";
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (x + i >= 0 && x + i < w && y + j >= 0 && y + j < h && !(i == 0 && j == 0) && t[x+i][y+j] != 1)
			{
				string f = fill(x + i, y + j, w, h, rem, copy(t, w, h));
				if (f.compare("") != 0)
					return f;
			}
		}
	}
	return "";
}

int main()
{
	ifstream fin("minesin.txt");
	ofstream fout("minesout.txt");

	int T = 0;

	fin >> T;

	int R, C, M;

	for (int i = 0; i < T; i++)
	{
		cout << "Case #" << i + 1 << '\n';
		fin >> R >> C >> M;
		int** b = new int*[C];
		for (int j = 0; j < C; j++)
		{
			b[j] = new int[R];
			for (int k = 0; k < R; k++)
			{
				b[j][k] = 0;
			}
		}
		int rem = R*C - M;
		if (R == 1 || C == 1)
		{
			fout << "Case #" << i + 1 << ":\n";
			fout << "c" << ((C == 1) ? "\n":"");
			for (int j = 0; j < rem-1; j++)
			{
				fout << "." << ((C == 1) ? "\n" : "");
			}
			for (int j = 0; j < M; j++)
			{
				fout << "*" << ((C == 1) ? "\n" : "");
			}
			fout << ((C != 1) ? "\n" : "");
		}
		else if (rem == 1)
		{
			fout << "Case #" << i + 1 << ":\nc";
			string str = "";
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					if (!(i==0 && j==0))
					str += "*";
				}
				str += "\n";
			}
			fout << str;
		}
		else if ((R == 2 || C == 2) && rem%2 == 1)
		{
			fout << "Case #" << i + 1 << ":\nImpossible\n";
		}
		else if (rem < 4 || (rem == 5 || rem == 7))
		{
			fout << "Case #" << i + 1 << ":\nImpossible\n";
		}
		else
		{
			fout << "Case #" << i + 1 << ":\n";	
			fout << fill(0, 0, C, R, rem, copy(b, C, R));
		}
	}
	fout.close();
	fin.close();
}