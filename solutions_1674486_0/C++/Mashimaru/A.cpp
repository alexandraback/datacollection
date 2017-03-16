#include <cstdio>
#include <cstring>
using namespace std;

struct edge
{
	int to, nextID;
} E[1000005];

int test, n, ne, LE[1005], q[1005];
bool ok, fr[1005];

void add(int u, int v)
{
	E[++ne].to = v;
	E[ne].nextID = LE[u];
	LE[u] = ne;
}

void bfs(int i)
{
	memset(fr, true, sizeof(fr));
	int first = 0, last = 0;
	q[first] = i;
	fr[i] = false;
	while (first <= last)
	{
		int u = q[first++];
		for (int ID = LE[u]; ID != -1; ID = E[ID].nextID)
		{
			int v = E[ID].to;
			if (!fr[v])
			{
				ok = true;
				return;
			}
			else
			{
				fr[v] = false;
				q[++last] = v;
			}
		}	
	}
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &test);
	for (int num = 1; num <= test; num++)
	{
		ne = 0;
		memset(LE, -1, sizeof(LE));
		memset(fr, true, sizeof(fr));
		ok = false;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int t;
			for (scanf("%d", &t); t--; )
			{
				int j;
				scanf("%d", &j);
				add(i, j);
			}
		}
		for (int i = 1; i <= n; i++) bfs(i);
		printf("Case #%d: ", num);
		printf(ok ? "Yes\n" : "No\n");
	}
	return 0;
}
