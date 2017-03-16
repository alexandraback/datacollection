#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char s[5][5];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int t;
	scanf("%d", &t);
	int n = 4;

	for(int tt = 0; tt < t; tt++)
	{
		int ans = 0;
		for(int i = 0; i < n; i++)
			scanf("%s", s[i]);
		for(int i = 0; i < n; i++)
		{
			int x = 0, y = 0, te = 0;
			for(int j = 0; j < n; j++) 
			{
				if(s[i][j] == 'X')
					x++;
				else if(s[i][j] == 'O')
					y++;
				else if(s[i][j] == 'T')
					te++;
			}
			if(x + te == 4)
				ans = 1;
			if(y + te == 4)
				ans = 2;
		}
		for(int i = 0; i < n; i++)
		{
			int x = 0, y = 0, te = 0;
			for(int j = 0; j < n; j++) 
			{
				if(s[j][i] == 'X')
					x++;
				else if(s[j][i] == 'O')
					y++;
				else if(s[j][i] == 'T')
					te++;
			}
			if(x + te == 4)
				ans = 1;
			if(y + te == 4)
				ans = 2;
		}
		int x = 0, y = 0, te = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i][i] == 'X')
					x++;
			else if(s[i][i] == 'O')
				y++;
			else if(s[i][i] == 'T')
				te++;
		}
		if(x + te == 4)
			ans = 1;
		if(y + te == 4)
			ans = 2;
		x = 0, y = 0, te = 0;
		for(int i = 0; i < n; i++)
		{
			if(s[i][n - i - 1] == 'X')
					x++;
			else if(s[i][n - i - 1] == 'O')
				y++;
			else if(s[i][n - i - 1] == 'T')
				te++;
		}
		if(x + te == 4)
			ans = 1;
		if(y + te == 4)
			ans = 2;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if(s[i][j] == '.' && !ans)
					ans = 3;
		if(ans == 0)
			printf("Case #%d: Draw\n", tt + 1);
		else if(ans == 1)
			printf("Case #%d: X won\n", tt + 1);
		else if(ans == 2)
			printf("Case #%d: O won\n", tt + 1);
		else
			printf("Case #%d: Game has not completed\n", tt + 1);
	}

	return 0;
}