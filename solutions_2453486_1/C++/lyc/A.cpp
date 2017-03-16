#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int T;
char s[10][10];

int calc()
{
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int j;
		j = 0;
		while (s[i][j] == 'X' || s[i][j] == 'T') j++;
		if (j == 4) ret |= 2;
		j = 0;
		while (s[i][j] == 'O' || s[i][j] == 'T') j++;
		if (j == 4) ret |= 1;
	}
	for (int i = 0; i < 4; i++)
	{
		int j;
		j = 0;
		while (s[j][i] == 'X' || s[j][i] == 'T') j++;
		if (j == 4) ret |= 2;
		j = 0;
		while (s[j][i] == 'O' || s[j][i] == 'T') j++;
		if (j == 4) ret |= 1;
	}
	int i;
	i = 0;
	while (s[i][i] == 'X' || s[i][i] == 'T') i++;
	if (i == 4) ret |= 2;
	i = 0;
	while (s[i][i] == 'O' || s[i][i] == 'T') i++;
	if (i == 4) ret |= 1;
	i = 0;
	while (i < 4 && (s[i][3 - i] == 'X' || s[i][3 - i] == 'T')) i++;
	if (i == 4) ret |= 2;
	i = 0;
	while (i < 4 && (s[i][3 - i] == 'O' || s[i][3 - i] == 'T')) i++;
	if (i == 4) ret |= 1;
	return ret;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	int ca = 0;
	while (T--)
	{
		ca++;
		for (int i = 0; i < 4; i++)
			scanf("%s", s[i]);
		int k = calc();
		while (k == 3);
		if (k == 2) printf("Case #%d: X won\n", ca);
		if (k == 1) printf("Case #%d: O won\n", ca);
		if (k == 0)
		{
			bool flag = true;
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (s[i][j] == '.') flag = false;
			if (flag)
				printf("Case #%d: Draw\n", ca);
			else printf("Case #%d: Game has not completed\n", ca);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
