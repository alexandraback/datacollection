#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int k, l, s;
char alph[110], word[110];

int maxOcc;
char cur[110];
int occ[110];
int all;

bool is_occ(int pos)
{
	for (int i = 0; i < l; i++)
	{
		if (word[i] != cur[pos + i])
			return false;
	}
	return true;
}

void check()
{
	all++;
	int curOc = 0;
	for (int i = 0; i + l <= s; i++)
	{
		if (is_occ(i))
		{
			curOc++;
		}
	}
	occ[curOc]++;
	if (curOc > maxOcc)
	{
		maxOcc = curOc;
	}
}

void rec(int pos)
{
	if (pos == s)
	{
		check();
		return;
	}
	for (int i = 0; i < k; i++)
	{
		cur[pos] = alph[i];
		rec(pos + 1);
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		all = 0;
		maxOcc = 0;
		memset(occ, 0, sizeof(occ));
		scanf("%d%d%d\n%s%s", &k, &l, &s, alph, word);
		rec(0);
		double ans = 0;
		for (int i = 1; i <= maxOcc; i++)
		{
			ans += i * occ[i] * 1.0 / all;
		}
		ans = maxOcc - ans;
		printf("Case #%d: %.8lf\n", q + 1, ans);
	}
	return 0;
}