#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;
char buf[1024];
char m[5][5];

template <char C>
bool IsWon()
{
	for(int i=0;i<4;i++)
	{
		int cnt = 0;
		int cntT = 0;
		for(int j=0;j<4;j++)
		{
			if(m[i][j]==C)
				cnt++;
			if(m[i][j]=='T')
				cntT++;
		}
		if(cnt==4)
			return true;
		if(cnt==3 && cntT==1)
			return true;
	}
	for(int i=0;i<4;i++)
	{
		int cnt = 0;
		int cntT = 0;
		for(int j=0;j<4;j++)
		{
			if(m[j][i]==C)
				cnt++;
			if(m[j][i]=='T')
				cntT++;
		}
		if(cnt==4)
			return true;
		if(cnt==3 && cntT==1)
			return true;
	}
	{
		int cnt = 0;
		int cntT = 0;
		for(int i=0;i<4;i++)
		{
			if(m[i][i]==C)
				cnt++;
			if(m[i][i]=='T')
				cntT++;
		}
		if(cnt==4)
			return true;
		if(cnt==3 && cntT==1)
			return true;
	}
	{
		int cnt = 0;
		int cntT = 0;
		for(int i=0;i<4;i++)
		{
			if(m[i][4-1-i]==C)
				cnt++;
			if(m[i][4-1-i]=='T')
				cntT++;
		}
		if(cnt==4)
			return true;
		if(cnt==3 && cntT==1)
			return true;
	}
	return false;
}


bool IsFull()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(m[i][j]=='.')
				return false;
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int kcase = 1; kcase <=T; kcase++)
	{
		gets(buf);
		for(int i=0;i<4;i++)
		{
			gets(m[i]);
		}
		if(IsWon<'X'>())
		{
			printf("Case #%d: X won\n", kcase);
		}
		else if(IsWon<'O'>())
		{
			printf("Case #%d: O won\n", kcase);
		}
		else if(IsFull())
		{
			printf("Case #%d: Draw\n", kcase);
		}
		else
		{
			printf("Case #%d: Game has not completed\n", kcase);

		}
	}
}
