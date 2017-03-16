#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int M = 20005;
const int inf = 0x7fffffff;

char mp[4][5];
int T;

bool check(char c)
{
	for(int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for(int j = 0; j < 4; j++)
			if(mp[i][j] == c || mp[i][j] == 'T')
				cnt++;
		if(cnt == 4)
			return true;
	}
	for(int i = 0; i < 4; i++)
	{
		int cnt = 0;
		for(int j = 0; j < 4; j++)
			if(mp[j][i] == c || mp[j][i] == 'T')
				cnt++;
		if(cnt == 4)
			return true;
	}
	int ct = 0;
	for(int i = 0; i < 4; i++)
	{
		if(mp[i][i] == c || mp[i][i] == 'T')
			ct++;
	}
	if(ct == 4)
		return true;
	ct = 0;
	for(int i = 0; i < 4; i++)
	{
		if(mp[i][3 - i] == c || mp[i][3 - i] == 'T')
			ct++;
	}
	if(ct == 4)
		return true;
	return false;
}

bool find()
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(mp[i][j] == '.')
				return true;
	return false;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("out.out", "w", stdout);
	scanf("%d", &T);
	int cs = 1;
	while(T--)
	{
		for(int i = 0; i < 4; i++)
		{
			scanf("%s", mp[i]);
		}
		printf("Case #%d: ", cs++);
		if(check('X'))
		{
			printf("X won\n");
		}
		else if(check('O'))
		{
			printf("O won\n");
		}
		else if(find())
		{
			printf("Game has not completed\n");
		}
		else
		{
			printf("Draw\n");
		}
	}
	return 0;
}
