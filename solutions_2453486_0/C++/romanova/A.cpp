#include <cstdio>
#include <iostream> 
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std;


char s[4][5];

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int tt = 0; tt < t; ++tt)
	{
		for(int i = 0; i < 4; ++i)
			scanf("%s", &s[i]);

		bool owin = 0, xwin = 0, emp = 0;
		int oq, xq;
		for(int i = 0; i < 4; ++i)
		{
			oq = xq = 0;
			for(int j = 0; j < 4; ++j)
				if(s[i][j] == 'T')
					oq++, xq++;
				else if(s[i][j] == 'O')
					oq++;
				else if(s[i][j] == 'X')
					xq++;
				else 
					emp = 1;
			if(oq == 4) owin = 1;
			if(xq == 4) xwin = 1;
		}

		for(int i = 0; i < 4; ++i)
		{
			oq = xq = 0;
			for(int j = 0; j < 4; ++j)
				if(s[j][i] == 'T')
					oq++, xq++;
				else if(s[j][i] == 'O')
					oq++;
				else if(s[j][i] == 'X')
					xq++;
				else 
					emp = 1;
			if(oq == 4) owin = 1;
			if(xq == 4) xwin = 1;
		}

		oq = xq = 0;
		for(int i = 0; i < 4; ++i)
			if(s[i][i] == 'T')
				oq++, xq++;
			else if(s[i][i] == 'O')
				oq++;
			else if(s[i][i] == 'X')
				xq++;
			else 
				emp = 1;
		if(oq == 4) owin = 1;
		if(xq == 4) xwin = 1;

		oq = xq = 0;
		for(int i = 0; i < 4; ++i)
			if(s[i][3-i] == 'T')
				oq++, xq++;
			else if(s[i][3-i] == 'O')
				oq++;
			else if(s[i][3-i] == 'X')
				xq++;
			else 
				emp = 1;
		if(oq == 4) owin = 1;
		if(xq == 4) xwin = 1;

		if(owin && xwin)
			printf("Case #%d: Draw\n", tt+1);
		else if(owin)
			printf("Case #%d: O won\n", tt+1);
		else if(xwin)
			printf("Case #%d: X won\n", tt+1);
		else if(emp)
			printf("Case #%d: Game has not completed\n", tt+1);
		else
			printf("Case #%d: Draw\n", tt+1);
	}


	return 0;
}