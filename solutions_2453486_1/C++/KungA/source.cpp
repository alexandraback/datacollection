#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "rt", stdin);
		freopen("output.txt", "wt", stdout);
	#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		string s[4];
		bool inc = 0, X, O, winX = 0, winO = 0;
		cin >> s[0] >> s[1] >> s[2] >> s[3];

		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (s[i][j] == '.')
					inc = 1;

		for (int i = 0; i < 4; i++)
		{
			X = O = 1;
			for (int j = 0; j < 4; j++)
			{
				if (s[i][j] == '.')
					X = O = 0;
				if (s[i][j] == 'X')
					O = 0;
				if (s[i][j] == 'O')
					X = 0;
			}

			if (X)
				winX = 1;
			if (O)
				winO = 1;
		}

		for (int i = 0; i < 4; i++)
		{
			X = O = 1;
			for (int j = 0; j < 4; j++)
			{
				if (s[j][i] == '.')
					X = O = 0;
				if (s[j][i] == 'X')
					O = 0;
				if (s[j][i] == 'O')
					X = 0;
			}

			if (X)
				winX = 1;
			if (O)
				winO = 1;
		}

		X = O = 1;
		for (int i = 0; i < 4; i++)
		{
			if (s[i][i] == '.')
				X = O = 0;
			if (s[i][i] == 'X')
				O = 0;
			if (s[i][i] == 'O')
				X = 0;
		}
		if (X)
			winX = 1;
		if (O)
			winO = 1;

		X = O = 1;
		for (int i = 0; i < 4; i++)
		{
			if (s[i][3 - i] == '.')
				X = O = 0;
			if (s[i][3 - i] == 'X')
				O = 0;
			if (s[i][3 - i] == 'O')
				X = 0;
		}
		if (X)
			winX = 1;
		if (O)
			winO = 1;

		cout << "Case #" << t + 1 << ": ";

		//cout << "\n\t" << s[0] << "\n\t" << s[1] << "\n\t" << s[2] << "\n\t" << s[3] << endl;

		if (winX)
			cout << "X won";
		else
			if (winO)
				cout << "O won";
			else
				if (inc)
					cout << "Game has not completed";
				else
					cout << "Draw";
		cout << endl;
	}
}
































