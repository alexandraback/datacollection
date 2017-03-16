#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;
#define mp make_pair

pair<int, string> a[15];

int n;

int c[26];

bool is_valid()
{
	for (int i = 0; i < 26; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < a[i].second.size(); j++)
		c[a[i].second[j] - 'a']++;
	int cur_letter = a[0].second[0];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < a[i].second.size(); j++)
	{
		if (a[i].second[j] != cur_letter && c[cur_letter - (int)'a'] != 0)
			return 0;
		cur_letter = a[i].second[j];
		c[cur_letter - (int)'a']--;
	}
	return 1;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int q = 0; q < tests; q++)
	{
		printf("Case #%d: ", q + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].second;
			a[i].first = i;
		}
		int ans = 0;
		do
		{
			if (is_valid())
				ans++;
		} while (next_permutation(a, a + n));
		printf("%d\n", ans);
	}
	return 0;
}