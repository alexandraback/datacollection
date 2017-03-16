#include <iostream>
#include <sstream>
#include <climits>
#include <cstddef>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;
typedef pair<int,int> P;


int T;
string board[10];

bool checker(char symbol)
{
	bool win=false;

	for (int i = 0; i < 4; i++)
	{
		int counter=0;
		for (int j = 0; j < 4; j++)
		{
			if (board[i][j]==symbol || board[i][j]=='T') counter++;
		}
		if (counter==4) win=true;
	}

	for (int j = 0; j < 4; j++)
	{
		int counter=0;
		for (int i = 0; i < 4; i++)
		{
			if (board[i][j]==symbol || board[i][j]=='T') counter++;
		}
		if (counter==4) win=true;
	}

	int c1=0,c2=0;
	for (int i = 0; i < 4; i++)
	{
		if (board[i][i]==symbol || board[i][i]=='T') c1++;
		if (board[3-i][i]==symbol || board[3-i][i]=='T') c2++;
	}
	if (c1==4 || c2==4) win=true;

	return win;
}

int main()
{
	cin>>T;
	for (int CASE = 1; CASE <= T; CASE++)
	{
		for (int i = 0; i < 4; i++) cin>>board[i];

		if (checker('O'))
		{
			cout<<"Case #"<<CASE<<": O won"<<endl;
			continue;
		}
		if (checker('X'))
		{
			cout<<"Case #"<<CASE<<": X won"<<endl;
			continue;
		}


		bool fin=true;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (board[i][j]=='.') fin=false;
			}
		}

		if (fin) cout<<"Case #"<<CASE<<": Draw"<<endl;
		else cout<<"Case #"<<CASE<<": Game has not completed"<<endl;
	}

	return 0;
}
