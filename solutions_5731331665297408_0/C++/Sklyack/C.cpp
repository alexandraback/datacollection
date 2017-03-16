#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 8;
bool G[MAXN][MAXN];
int prev[MAXN];
int nx_vert[MAXN];

char code[MAXN][10];
char ans[5*MAXN+1], tmp[5*MAXN+1];

int order[MAXN];

bool check_order(int n)
{
	int u, v;
	int nvis;
	memset(nx_vert, 0, sizeof(nx_vert));
	u = order[0];
	prev[u] = -1;
	nvis = 1;
	while(nvis < n && u != -1)
	{
		v = nx_vert[u]++;
		if(v < n && G[u][v] && v == order[nvis])
		{
			++nvis;
			prev[v] = u;
			u = v;
		}
		else if(v == n)
			u = prev[u];
	}
	return nvis == n;
}

void proc_case(int cs)
{
	int n, m, i, u, v;
	scanf("%d%d", &n, &m);
	for(u = 0; u < n; ++u)
		scanf("%s", code[u]);
	memset(G, 0, sizeof(G));
	for(i = 0; i < m; ++i)
	{
		scanf("%d%d", &u, &v);
		--u; --v;
		G[u][v] = G[v][u] = true;
	}

	ans[0] = (char)'9' + 1;
	ans[1] = 0;
	for(u = 0; u < n; ++u)
		order[u] = u;
	do
	{
		if(check_order(n))
		{
			char *pos = tmp;
			for(u = 0; u < n; ++u)
			{
				strcpy(pos, code[order[u]]);
				pos += 5;
			}
			if(strcmp(tmp, ans) < 0)
				strcpy(ans, tmp);
		}
	}while(next_permutation(order, order + n));

	printf("Case #%d: %s\n", cs, ans);
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ncases, cs;
	scanf("%d", &ncases);
	for(cs = 1; cs <= ncases; ++cs)
		proc_case(cs);
	return 0;
}
