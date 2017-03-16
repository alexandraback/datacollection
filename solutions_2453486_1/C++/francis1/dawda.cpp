#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
char a[10][10];
bool WIN(char c)
{
	for(int i=0;i<4;i++)
	{
		bool ok=1;
		for(int j=0;j<4;j++)
			if(a[i][j]!=c&&a[i][j]!='T')
				ok=0;
		if(ok)return 1;
	}
	for(int i=0;i<4;i++)
	{
		bool ok=1;
		for(int j=0;j<4;j++)
			if(a[j][i]!=c&&a[j][i]!='T')
				ok=0;
		if(ok)return 1;
	}
	bool ok=1;
	for(int i=0;i<4;i++)
		if(a[i][i]!=c&&a[i][i]!='T')
			ok=0;
	if(ok)return 1;
	ok=1;
	for(int i=0;i<4;i++)
		if(a[i][3-i]!=c&&a[i][3-i]!='T')
			ok=0;
	if(ok)return 1;
	return 0;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<4;i++)scanf("%s",a[i]);
		printf("Case #%d: ",++cas);
		if(WIN('X'))puts("X won");
		else if(WIN('O'))puts("O won");
		else
		{
			bool empty=0;
			for(int i=0;i<4;i++)
				for(int j=0;j<4;j++)
					if(a[i][j]=='.')
						empty=1;
			if(empty)
				puts("Game has not completed");
			else
				puts("Draw");
		}
	}
}
