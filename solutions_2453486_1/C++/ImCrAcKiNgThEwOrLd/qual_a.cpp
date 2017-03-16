#include <iostream>
#include <vector>
#include <string>
using namespace std;

string field[4];
int cnt[255];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t = 0;
	cin >> t; getchar();
	for (int counter = 1; counter <= t; ++counter)
	{
		cout << "Case #" << counter << ": ";
		for (int i = 0; i < 4; ++i)
			getline(cin, field[i]);
		getchar();
		bool found = false;
		for (int i = 0; i < 4; ++i)	
		{
			cnt['T'] = cnt['X'] = cnt['O'] = cnt['.'] = 0;
			for (int j = 0; j < 4; ++j)
				++cnt[field[i][j]];
			if (cnt['X'] == 4 || cnt['X'] == 3 && cnt['T'] == 1)
			{
				cout << "X won" << endl;
				found = true;
				break;
			}
			if (cnt['O'] == 4 || cnt['O'] == 3 && cnt['T'] == 1)
			{
				cout << "O won" << endl;
				found = true;
				break;
			}
		}
		if (found)
			continue;
		for (int i = 0; i < 4; ++i)	
		{
			cnt['T'] = cnt['X'] = cnt['O'] = cnt['.'] = 0;
			for (int j = 0; j < 4; ++j)
				++cnt[field[j][i]];
			if (cnt['X'] == 4 || cnt['X'] == 3 && cnt['T'] == 1)
			{
				cout << "X won" << endl;
				found = true;
				break;
			}
			if (cnt['O'] == 4 || cnt['O'] == 3 && cnt['T'] == 1)
			{
				cout << "O won" << endl;
				found = true;
				break;
			}
		}
		if (found)
			continue;
		cnt['T'] = cnt['X'] = cnt['O'] = cnt['.'] = 0;
		for (int i = 0; i < 4; ++i)
			++cnt[field[i][i]];
		if (cnt['X'] == 4 || cnt['X'] == 3 && cnt['T'] == 1)
		{
			cout << "X won" << endl;
			found = true;
			continue;
		}
		if (cnt['O'] == 4 || cnt['O'] == 3 && cnt['T'] == 1)
		{
			cout << "O won" << endl;
			found = true;
			continue;
		}
		cnt['T'] = cnt['X'] = cnt['O'] = cnt['.'] = 0;
		for (int i = 0; i < 4; ++i)
			++cnt[field[i][3 - i]];
		if (cnt['X'] == 4 || cnt['X'] == 3 && cnt['T'] == 1)
		{
			cout << "X won" << endl;
			found = true;
			continue;
		}
		if (cnt['O'] == 4 || cnt['O'] == 3 && cnt['T'] == 1)
		{
			cout << "O won" << endl;
			found = true;
			continue;
		}
		cnt['.'] = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				++cnt[field[i][j]];
		if (cnt['.'] == 0)
			cout << "Draw" << endl; 
		else
			cout << "Game has not completed" << endl;
	}
}