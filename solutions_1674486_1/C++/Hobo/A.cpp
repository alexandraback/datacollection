#include <cstdio>
#include <cstring>

const int MAXN = 1010;
const int MAXE = MAXN * MAXN;

struct Edge
{
	int to;
	Edge *next;
} e[MAXE], *head[MAXN];
int ne;
void addedge(int f, int t)
{
	e[ne].to = t;
	e[ne].next = head[f];
	head[f] = e + (ne ++);
}

int n, s[MAXN];
void init()
{
	memset(head, 0, sizeof(head));
	ne = 0;

	scanf("%d", &n);
	for(int i = 1; i <= n; i ++)
	{
		scanf("%d", s + i);
		for(int j = 0; j < s[i]; j ++)
		{
			int t;
			scanf("%d", &t);
			addedge(i, t);
		}
	}
}

bool in[MAXN], find;
int cnt[MAXN];
void dfs(int now)
{
	if(find || in[now]) return;
	in[now] = true;
	cnt[now] ++;
	if(cnt[now] >= 2)
	{
		printf("Yes\n");
		find = true;
		return;
	}
	for(Edge *p = head[now]; p; p = p->next)
		dfs(p->to);

	in[now] = false;
}

void work()
{
	init();
	find = false;
	for(int i = 1; i <= n; i ++)
	{
		memset(in, 0, sizeof(in));
		memset(cnt, 0, sizeof(cnt));
		dfs(i);
	}
	if(!find) printf("No\n");
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i ++)
	{
		printf("Case #%d: ", i);
	work();
	}
	return 0;
}
