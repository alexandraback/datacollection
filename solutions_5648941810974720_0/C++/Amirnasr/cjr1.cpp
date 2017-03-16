#include <bits/stdc++.h>
using namespace std;

/*
*/

string nums[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

char S[2005];

int main()
{
	freopen("input.in", "r", stdin);
	freopen("input.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int z = 1; z <= T; z++)
	{
		scanf("%s", S);
		int cnt[10] = {0};
		int n = strlen(S);
		int f[26] = {0};
		for (int i = 0; i < n; i++)
			f[S[i]-'A']++;
		pair<int, int> ord[10] = {make_pair(0, 'Z'-'A'), make_pair(6, 'X'-'A'), make_pair(7, 'S'-'A'),
		 make_pair(5, 'V'-'A'), make_pair(4, 'F'-'A'), make_pair(3, 'R'-'A'), make_pair(2, 'W'-'A'),
		 make_pair(1, 'O'-'A'), make_pair(8, 'G'-'A'), make_pair(9, 'E'-'A')};
		for (int i = 0; i < 10; i++)
		{
			while (f[ord[i].second])
			{
				cnt[ord[i].first]++;
				for (int j = 0; j < nums[ord[i].first].size(); j++)
					f[nums[ord[i].first][j]-'A']--;
			}
		}
		printf("Case #%d: ", z);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < cnt[i]; j++)
				printf("%d", i);
		}
		printf("\n");
	}
};