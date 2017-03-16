#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

char s[100000];
char d[100000];

bool ta[3][8];
bool taw[3][8];

bool dp(int l)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			ta[i][j] = false;
		}
	}
	ta[0][0] = true;
	for (int k = 0; k < l; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				taw[i][j] = false;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			switch (d[k])
			{
			case 'i':
				taw[i][2] = ta[i][0];
				taw[i][3] = ta[i][1];
				taw[i][1] = ta[i][2];
				taw[i][0] = ta[i][3];
				taw[i][7] = ta[i][4];
				taw[i][6] = ta[i][5];
				taw[i][4] = ta[i][6];
				taw[i][5] = ta[i][7];
				break;
			case 'j':
				taw[i][4] = ta[i][0];
				taw[i][5] = ta[i][1];
				taw[i][6] = ta[i][2];
				taw[i][7] = ta[i][3];
				taw[i][1] = ta[i][4];
				taw[i][0] = ta[i][5];
				taw[i][3] = ta[i][6];
				taw[i][2] = ta[i][7];
				break;
			case 'k':
				taw[i][6] = ta[i][0];
				taw[i][7] = ta[i][1];
				taw[i][5] = ta[i][2];
				taw[i][4] = ta[i][3];
				taw[i][2] = ta[i][4];
				taw[i][3] = ta[i][5];
				taw[i][1] = ta[i][6];
				taw[i][0] = ta[i][7];
				break;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				ta[i][j] = taw[i][j];
			}
		}
		ta[1][0] |= ta[0][2];
		ta[2][0] |= ta[1][4];
	}
	return ta[2][6];
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++)
	{
		int l, x;
		scanf("%d%d", &l, &x);
		int nw = min(x, x % 4 + 8);
		scanf("%s", s);
		for (int i = 0; i < nw; i++)
		{
			for (int j = 0; j < l; j++)
			{
				d[i * l + j] = s[j];
			}
		}
		if (dp(l * nw))
		{
			printf("Case #%d: YES\n", k + 1);
		}
		else
		{
			printf("Case #%d: NO\n", k + 1);
		}
	}
}
