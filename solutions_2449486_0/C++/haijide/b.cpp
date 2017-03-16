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

const int M = 105;
const int inf = 0x7fffffff;

int T;
int n, m;
int mp[M][M];

bool check(int r, int c)
{
	int w = mp[r][c];
	int cnt = 0;
	for(int i = 0; i < m; i++)
	{
		if(mp[r][i] > w)
		{
			cnt++;
			break;
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(mp[i][c] > w)
		{
			cnt++;
			break;
		}
	}
	if(cnt == 2)
		return true;
	return false;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-out.out", "w", stdout);
	scanf("%d", &T);
	int cs = 1;
	while(T--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &mp[i][j]);
		bool flag = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(check(i, j))
				{
					flag = true;
					break;
				}
			}
			if(flag)
				break;
		}
		printf("Case #%d: ", cs++);
		if(flag)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
