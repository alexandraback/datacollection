#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <string.h>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char s[4][4];
int jud1()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)if(s[j][i]=='O'||s[j][i]=='.')
			break;
		if(j==4)
			return 1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)if(s[i][j]=='O'||s[i][j]=='.')
			break;
		if(j==4)
			return 1;
	}
	for(i=0;i<4;i++)if(s[i][i]=='O'||s[i][i]=='.')
		break;
	if(i==4)
		return 1;
	for(i=0;i<4;i++)if(s[i][3-i]=='O'||s[i][3-i]=='.')
		break;
	if(i==4)
		return 1;
	return 0;
}
int jud2()
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)if(s[j][i]=='X'||s[j][i]=='.')
			break;
		if(j==4)
			return 1;
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)if(s[i][j]=='X'||s[i][j]=='.')
			break;
		if(j==4)
			return 1;
	}
	for(i=0;i<4;i++)if(s[i][i]=='X'||s[i][i]=='.')
		break;
	if(i==4)
		return 1;
	for(i=0;i<4;i++)if(s[i][3-i]=='X'||s[i][3-i]=='.')
		break;
	if(i==4)
		return 1;
	return 0;
}
int jud3()
{
	int i,j;
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)if(s[i][j]=='.')
			return 1;
	return 0;
}
int main()
{
	freopen("1.txt","w",stdout);
	int t,i,j;
	cin>>t;
	for(int ii=1;ii<=t;ii++)
	{
		for(i=0;i<4;i++)
			scanf("%s",s[i]);
		printf("Case #%d: ",ii);
		if(jud1())
			puts("X won");
		else if(jud2())
			puts("O won");
		else if(jud3())
			puts("Game has not completed");
		else
			puts("Draw");
	}
}