#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>

using namespace std;

string m[4];

bool Check(string ss, char ch)
{
	int nc = 0, nt = 0;
	for (int i = 0; i < 4; i ++)
	{
		nc += ss[i] == ch;
		nt += ss[i] == 'T';
	}
	return nc == 4 || (nc == 3 && nt == 1);
}

string Work()
{
	for (int i = 0; i < 4; i ++)
		cin >> m[i];

	
	int nd = 0, nx = 0, no = 0;
	for (int i = 0; i < 4; i ++)
		for (int j = 0; j < 4; j ++)
		{
			nd += m[i][j] == '.';
			nx += m[i][j] == 'X';
			no += m[i][j] == 'O';
		}
	
	string sd1 = "", sd2 = "", ss;
	for (int i = 0; i < 4; i ++)
	{
		sd1 = sd1 + m[i][i];
		sd2 = sd2 + m[i][3-i];
	}

	if (nx > no)
	{
		for (int i = 0; i < 4; i ++)
			if (Check(m[i], 'X'))  return "X won";
		for (int j = 0; j < 4; j ++)
		{
			ss = "";
			for (int i = 0; i < 4; i ++)
				ss = ss + m[i][j];
			if (Check(ss, 'X'))  return "X won";
		}
		if (Check(sd1, 'X'))  return "X won";
		if (Check(sd2, 'X'))  return "X won";

		for (int i = 0; i < 4; i ++)
			if (Check(m[i], 'O'))  return "O won";
		for (int j = 0; j < 4; j ++)
		{
			ss = "";
			for (int i = 0; i < 4; i ++)
				ss = ss + m[i][j];
			if (Check(ss, 'O'))  return "O won";
		}
		if (Check(sd1, 'O'))  return "O won";
		if (Check(sd2, 'O'))  return "O won";
	} else 
	{
		for (int i = 0; i < 4; i ++)
			if (Check(m[i], 'O'))  return "O won";
		for (int j = 0; j < 4; j ++)
		{
			ss = "";
			for (int i = 0; i < 4; i ++)
				ss = ss + m[i][j];
			if (Check(ss, 'O'))  return "O won";
		}
		if (Check(sd1, 'O'))  return "O won";
		if (Check(sd2, 'O'))  return "O won";

		for (int i = 0; i < 4; i ++)
			if (Check(m[i], 'X'))  return "X won";
		for (int j = 0; j < 4; j ++)
		{
			ss = "";
			for (int i = 0; i < 4; i ++)
				ss = ss + m[i][j];
			if (Check(ss, 'X'))  return "X won";
		}
		if (Check(sd1, 'X'))  return "X won";
		if (Check(sd2, 'X'))  return "X won";
	}

	if (nd == 0)  return "Draw";
	return "Game has not completed";
}

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	cin >> T;

	for (int tt = 1; tt <= T; tt ++)
		cout << "Case #" << tt << ": " << Work() << endl;

	return 0;
}