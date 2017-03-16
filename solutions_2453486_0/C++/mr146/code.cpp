#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>


using namespace std;


string s[5];


bool checkWinHor(char c)
{
	for(int i = 0; i < 4; i++)
	{
		int cnt1 = 0;
		int cnt2 = 0;
		for(int j = 0; j < 4; j++)
			if(s[i][j] == c)
				cnt1++;
			else if(s[i][j] == 'T')
				cnt2++;
		if(cnt1 + cnt2 == 4 && cnt1 >= 3)
			return true;
	}
	return false;
}


bool checkWinDiag(int c)
{
	int cnt1 = 0;
	int cnt2 = 0;
	for(int j = 0; j < 4; j++)
		if(s[j][j] == c)
			cnt1++;
		else if(s[j][j] == 'T')
			cnt2++;
	if(cnt1 + cnt2 == 4 && cnt1 >= 3)
		return true;
	return false;
}


bool checkWin(char c)
{
	if(checkWinHor(c))
		return true;
	for(int i = 0; i < 4; i++)
		for(int j = i + 1; j < 4; j++)
			swap(s[i][j], s[j][i]);
	if(checkWinHor(c))
		return true;
	if(checkWinDiag(c))
		return true;
	for(int i = 0; i < 4; i++)
		reverse(s[i].begin(), s[i].end());
	if(checkWinDiag(c))
		return true;
	return false;
}


void solve(int t)
{
	for(int i = 0; i < 4; i++)
		cin >> s[i];
	if(checkWin('O'))
	{
		printf("Case #%d: O won\n", t);
		return;
	}
	if(checkWin('X'))
	{
		printf("Case #%d: X won\n", t);
		return;
	}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(s[i][j] == '.')
			{
				printf("Case #%d: Game has not completed\n", t);
				return;
			}
	printf("Case #%d: Draw\n", t);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		solve(i + 1);
}