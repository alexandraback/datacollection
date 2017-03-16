#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>
#include <queue>
#include <cstring>
#include <ctime>
#include <cfloat>

using namespace std;

#define SZ 105
#define INF 10000001

typedef pair<int, int> PII;
/*
int n, m;
int maze[SZ][SZ][SZ];
int par[SZ][SZ][SZ];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

queue<pair<PII, int> > que;

int bfs(int str, int stc, int enr, int enc)
{
	par[0][0][0] = -1;
	maze[0][0][0] = 0;
	que.push(make_pair(make_pair(0, 0), 0));
	while(!que.empty())
	{
		pair<PII, int> pp = que.top();
		que.pop();
		PII pos = pp.first;
		int lst = pp.second;
		lst++;
		for(i = 0; i < 4; i++)
		{
			int nr = pos.first + lst * dx[i];
			int nc = pos.second + lst * dy[i];
			if(nr <= 0 || nr > SZ ||)
		}
	}
}
*/
int main()
{
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("B-small.out", "wt", stdout);

	//freopen("B-large.in", "rt", stdin);
	//freopen("B-large.out", "wt", stdout);

	int inp, kase, i, j, k, n, m;
	scanf("%d", &inp);
	for(kase = 1; kase <= inp; kase++)
	{
		scanf("%d %d", &n, &m);
		//memset(maze, -1, sizeof(maze));
		printf("Case #%d: ", kase);
		int x = 0;
		int cnt = 1;
		while(x != n)
		{
			printf("E");
			x += cnt;
			cnt++;

			if(x == n)
				break;

			printf("W");
			x -= cnt;
			cnt++;
		}
		int y = 0;
		if(m < 0)
		{
			while(y != m)
			{
				printf("N");
				y += cnt;
				cnt++;
				if(y == m)
					break;
				printf("S");
				y -= cnt;
				cnt++;
			}
		}
		else
		{
			while(y != m)
			{
				printf("S");
				y -= cnt;
				cnt++;
				if(y == m)
					break;
				printf("N");
				y += cnt;
				cnt++;
			}
		}
		printf("\n");
	}

	return 0;
}
