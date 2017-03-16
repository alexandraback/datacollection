#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<queue>
using namespace std;


char s[5][5];

bool CheckS(char c)
{
	for(int i = 0; i < 4; i++)
	{
		bool f = 1;
		for(int j = 0; j < 4; j++)
		{
			if(!(s[i][j] == 'T' || s[i][j] == c))
				f = 0;
		}
		if(f)
			return 1;
	}
	
	for(int j = 0; j < 4; j++)
	{
		bool f = 1;
		for(int i = 0; i < 4; i++)
		{
			if(!(s[i][j] == 'T' || s[i][j] == c))
				f = 0;
		}
		if(f)
			return 1;
	}

	bool f = 1;
	for(int i = 0; i < 4; i++)
	{
		if(!(s[i][i] == 'T' || s[i][i] == c))
			f = 0;
	}
	if(f)
		return 1;
	f = 1;
	for(int i = 0; i < 4; i++)
	{
		if(!(s[i][3-i] == 'T' || s[i][3-i] == c))
			f = 0;
	}
	if(f)
		return 1;

	return 0;
}

void Check()
{
	if(CheckS('O'))
	{
		printf("O won\n");
		return;
	}
	if(CheckS('X'))
	{
		printf("X won\n");
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			if(s[i][j] == '.')
			{
				printf("Game has not completed\n");
				return;
			}
		}
	}
	printf("Draw\n");
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int T;
	int tc = 1;
	scanf("%d", &T);
	while(T > 0)
	{
		printf("Case #%d: ", tc);
		for(int i = 0; i < 4; i++)
			scanf("%s", s[i]);
		Check();
		T--;
		tc++;
	}

	return 0;
}