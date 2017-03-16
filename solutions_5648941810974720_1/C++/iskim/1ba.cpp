#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char str[3000];
int cnt[256];
int num[10];

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\A-large.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\A-large.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%s", str);
		for (int i = 0; str[i]; i++)
		{
			cnt[str[i]]++;
		}
		num[2] = cnt['W'];
		for (int i = 0; i < num[2]; i++)
		{
			cnt['T']--;
			cnt['W']--;
			cnt['O']--;
		}
		num[6] = cnt['X'];
		for (int i = 0; i < num[6]; i++)
		{
			cnt['S']--;
			cnt['I']--;
			cnt['X']--;
		}
		num[0] = cnt['Z'];
		for (int i = 0; i < num[0]; i++)
		{
			cnt['Z']--;
			cnt['E']--;
			cnt['R']--;
			cnt['O']--;
		}

		num[7] = cnt['S'];
		for (int i = 0; i < num[7]; i++)
		{
			cnt['S']--;
			cnt['E']--;
			cnt['V']--;
			cnt['E']--;
			cnt['N']--;
		}

		num[8] = cnt['G'];
		for (int i = 0; i < num[8]; i++)
		{
			cnt['E']--;
			cnt['I']--;
			cnt['G']--;
			cnt['H']--;
			cnt['T']--;
		}

		num[4] = cnt['U'];
		for (int i = 0; i < num[4]; i++)
		{
			cnt['F']--;
			cnt['O']--;
			cnt['U']--;
			cnt['R']--;
		}

		num[5] = cnt['V'];
		for (int i = 0; i < num[5]; i++)
		{
			cnt['F']--;
			cnt['I']--;
			cnt['V']--;
			cnt['E']--;
		}

		num[1] = cnt['O'];
		for (int i = 0; i < num[1]; i++)
		{
			cnt['O']--;
			cnt['N']--;
			cnt['E']--;
		}

		num[3] = cnt['T'];
		for (int i = 0; i < num[1]; i++)
		{
			cnt['T']--;
			cnt['H']--;
			cnt['R']--;
			cnt['E']--;
			cnt['E']--;
		}

		num[9] = cnt['I'];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < num[i]; j++)
			{
				printf("%d", i);
			}
		}
		printf("\n");
		memset(cnt, 0, sizeof(cnt));
	}
}