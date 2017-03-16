#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string a[4];

void check()
{
	int k = 0;
	for(int i = 0 ; i <= 3 ; i++)
	{
		int s = 0, t = 0;
		for(int j = 0 ; j <= 3 ; j++)
		{
			if(a[i][j] == 'X') s++;
			else if(a[i][j] == 'O') s--;
			else if(a[i][j] == 'T') t = 1;
			else if(a[i][j] == '.') k = 1;
		}
		if(s == 4 || (s == 3 && t))
		{
			cout << "X won\n";
			return;
		}
		else if(s == -4 || (s == -3 && t))
		{
			cout << "O won\n";
			return;
		}
	}
	
	for(int j = 0 ; j <= 3 ; j++)
	{
		int s = 0, t = 0;
		for(int i = 0 ; i <= 3 ; i++)
		{
			if(a[i][j] == 'X') s++;
			else if(a[i][j] == 'O') s--;
			else if(a[i][j] == 'T') t = 1;
			else if(a[i][j] == '.') k = 1;
		}
		if(s == 4 || (s == 3 && t))
		{
			cout << "X won\n";
			return;
		}
		else if(s == -4 || (s == -3 && t))
		{
			cout << "O won\n";
			return;
		}
	}
	
		int s = 0, t = 0;
		for(int i = 0 ; i <= 3 ; i++)
		{
			if(a[i][i] == 'X') s++;
			else if(a[i][i] == 'O') s--;
			else if(a[i][i] == 'T') t = 1;
			else if(a[i][i] == '.') k = 1;
		}
		if(s == 4 || (s == 3 && t))
		{
			cout << "X won\n";
			return;
		}
		else if(s == -4 || (s == -3 && t))
		{
			cout << "O won\n";
			return;
		}
		
		s = 0, t = 0;
		for(int i = 0 ; i <= 3 ; i++)
		{
			if(a[i][3-i] == 'X') s++;
			else if(a[i][3-i] == 'O') s--;
			else if(a[i][3-i] == 'T') t = 1;
			else if(a[i][3-i] == '.') k = 1;
		}
		if(s == 4 || (s == 3 && t))
		{
			cout << "X won\n";
			return;
		}
		else if(s == -4 || (s == -3 && t))
		{
			cout << "O won\n";
			return;
		}
	
	if(k)
	{
		cout << "Game has not completed\n";
	}
	else 
	{
		cout << "Draw\n";
	}
}	

int main()
{
	freopen("QA.in", "r", stdin);
	freopen("QA.out", "w", stdout);
	int T;
	cin >> T;
	for(int tt = 1 ; tt <= T ; tt++)
	{
		for(int i = 0 ; i <= 3 ; i++)
			cin >> a[i];
		cout << "Case #" << tt << ": ";
		check();
	}
	return 0;
}
