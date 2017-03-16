#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int  n, m;
unsigned __int64 ans;
bool ha[510][510];
vector  < vector < int > > E;
struct nnd
{
	int a, b;
	unsigned __int64 left, left1;
	unsigned __int64 val;
}cre, now;
queue < nnd > Q;
struct node
{
		unsigned __int64 v;
		int id;
}v[2][210];
#define min(a, b) a < b ? a : b
void judge()
{
	memset(ha, 0, sizeof(ha));
	while(!Q.empty())
		Q.pop();
	now.a = now.b = 1;
	now.val = 0;
	now.left = v[0][1].v;
	now.left1 = v[1][1].v;
	ha[1][1] = 1;
	Q.push(now);
	while(!Q.empty())
	{

	    cre = Q.front();
		Q.pop();
		if (cre.a == n + 1 || cre.b == m + 1)
		{
			if (cre.val > ans)
				ans = cre.val;
			continue;
		}
		now = cre;
		if (v[0][cre.a].id == v[1][cre.b].id)
		{
			unsigned __int64 p;
			p = min(cre.left, cre.left1);	
			now.val += p;
			now.left -= p;
			now.left1 -= p;
			if (now.left)
			{
				now.b++;
				now.left1 = v[1][now.b].v;
				Q.push(now);
			}else if (now.left1)
			{
				now.a++;
				now.left = v[0][now.a].v;
				Q.push(now);
			}else{
				now.a++;
				now.b++;
				now.left = v[0][now.a].v;
				now.left1 = v[1][now.b].v;
				if (now.left == v[0][now.a].v && now.left1 == v[1][now.b].v)
			{
				if (!ha[now.a][now.b])
				{
					ha[now.a][now.b] = 1;
					Q.push(now);
				}
			}
			else
				Q.push(now);
			}
		}
		else
		{
			now = cre;
			now.a++;
			now.left = v[0][now.a].v;
			if (now.left == v[0][now.a].v && now.left1 == v[1][now.b].v)
			{
				if (!ha[now.a][now.b])
				{
					ha[now.a][now.b] = 1;
					Q.push(now);
				}
			}
			else
				Q.push(now);
			now = cre;
			now.b++;
			now.left1 = v[1][now.b].v;
			if (now.left == v[0][now.a].v && now.left1 == v[1][now.b].v)
			{
				if (!ha[now.a][now.b])
				{
					ha[now.a][now.b] = 1;
					Q.push(now);
				}
			}
			else
				Q.push(now);
		}
		
	}
}
int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("444.out" ,"w", stdout);
	int cas, i, sum1;
	scanf("%d", &cas);
	for (int t = 1; t <= cas; t++)
	{
		scanf("%d%d", &n, &m);
		for(i = 1; i <= n; i++)
		{
			scanf("%I64u%d", &v[0][i].v, &v[0][i].id);
		}
		for(i = 1; i <= m; i++)
		{
			scanf("%I64u%d", &v[1][i].v, &v[1][i].id);
		}
		ans = 0;
		judge();
		printf("Case #%d: %I64u\n", t, ans);
		
	}
}