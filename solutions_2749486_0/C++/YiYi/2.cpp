#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

bool vowels(char ch)
{
	bool ret = false;
	switch(ch)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			ret = true;
	}
	return ret;
}

char ans[512];

int main()
{
	//init();
	
	//printf("Input File Name ?");
	//char FileName[128];
	//scanf("%s", FileName);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B2.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	
	int Case;
	for(Case = 1;  Case <= T; Case ++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		
		int len = 0, i;
		if(x < 0)
		{
			for(i = 0; i > x; i --)
			{
				ans[len++] = 'E';
				ans[len++] = 'W';
			}
		}
		if(x > 0)
		{
			for(i = 0; i < x; i ++)
			{
				ans[len++] = 'W';
				ans[len++] = 'E';
			}
		}
		
		if(y < 0)
		{
			for(i = 0; i > y; i --)
			{
				ans[len++] = 'N';
				ans[len++] = 'S';
			}
		}
		if(y > 0)
		{
			for(i = 0; i < y; i ++)
			{
				ans[len++] = 'S';
				ans[len++] = 'N';
			}
		}
		ans[len] = '\0';
		printf("Case #%d: %s\n", Case, ans);
	}
	
	return 0;
}
