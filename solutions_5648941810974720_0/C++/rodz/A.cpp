#include <bits/stdc++.h>

using namespace std;

string num[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int order[10][2] = {{0,'Z'}, {2, 'W'}, {4, 'U'}, {6, 'X'}, {8, 'G'}, {7, 'S'}, {5, 'V'}, {9, 'I'}, {1, 'O'}, {3, 'T'}};
int cnt[27];

int removedigits(string& s, int k)
{
	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i]-'A'] -= k;
	}
}

int main()
{
	int T, tcnt = 0;
	cin >> T;
	while(T--)
	{
		string s;
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < s.size(); i++)
		{
			cnt[s[i]-'A']++;
		}
		int ans[10] = {0};
		
		for (int i = 0; i < 10; i++)
		{
			int d = order[i][0], l = order[i][1];
			ans[d] += cnt[l-'A'];
			removedigits(num[d], ans[d]);
		}
		printf("Case #%d: ", ++tcnt);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < ans[i]; j++)
			{
				printf("%d", i);
			}
		}
		printf("\n");
	}
	return 0;
}
