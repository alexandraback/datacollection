#include <bits/stdc++.h>

using namespace std;

int use[200][200];

string s[] = {"ZERO",
"ONE",
"TWO",
"THREE",
"FOUR",
"FIVE",
"SIX",
"SEVEN",
"EIGHT",
"NINE"};

char a[101010];

map<pair<char, int>, int> m;

char tmp[] = "XZGWSHRFIO";

int main()
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < s[i].length(); ++j)
		{
			use[i][s[i][j]]++;
		}
	}
	m[{'X', 1}] = 6;
	m[{'Z', 1}] = 0;
	m[{'G', 1}] = 8;
	m[{'W', 1}] = 2;
	m[{'S', 1}] = 7;
	m[{'H', 1}] = 3;
	m[{'R', 1}] = 4;
	m[{'F', 1}] = 5;
	m[{'I', 1}] = 9;
	m[{'O', 1}] = 1;

	int t;
	scanf("%d", &t);
	for (int tc = 1; tc <= t; ++tc)
	{
		scanf("%s", a);
		int cnt['z' + 1] = {};
		for (int i = 0; a[i]; ++i)
		{
			cnt[a[i]]++;
		}
		printf("Case #%d: ", tc);
		vector<int> v;
		for (int i = 0; i < 10; ++i)
		{
			int p = m[{tmp[i], 1}];
			while (cnt[tmp[i]] > 0)
			{
				for (int j = 'A'; j <= 'Z'; ++j)
				{
					cnt[j] -= use[p][j];
				}
				v.push_back(p);
			}
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); ++i)
		{
			printf("%d", v[i]);
		}
		printf("\n");
	}
}
