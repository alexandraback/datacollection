#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int N;
int key_type[450];
vector<int> keys[450];
int key[405];
vector<int> V[450];

int status[405];
vector<int> ans;

int vis[450];
int temp_status[450], remaining;
int temp_key[450], parent[450];

void OPEN(int room)
{
	int i;

	temp_status[room] = 1;
	remaining--;
	for(i = keys[room].size()-1; i >= 0; i--)
		temp_key[ keys[room][i] ]++;
	temp_key[ key_type[room] ]--;
}

int try_to_use(int k)
{
	int cnt, i, z, u, sz, x, now, j;
	queue<int> Q;

	cnt = 0;
	for(i = 1; i <= N; i++)
	{
		vis[i] = 0;
		parent[i] = -1;

		if(temp_status[i])
		{
			vis[i] = -1;
			continue;
		}

		if(key_type[i]==k && temp_key[ key_type[i] ])
		{
			cnt++;
			vis[i] = 1;
			parent[i] = 0;
			Q.push(i);
			z = i;
		}
	}

	if(cnt == 0)
	{
		temp_key[k] = 0;
		return 0;
	}

	if(cnt == 1)
	{
		OPEN(z);
		return 1;
	}

	if(temp_key[k] > 1)
	{
		OPEN(z);
		return 1;
	}

//	Q.push( x );
//	vis[x] = 1;

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();

		sz = keys[u].size();
		for(i = 0; i < sz; i++)
		{
			x = keys[u][i];

			if(x == k)
			{
				now = u;
				while(now)
				{
					OPEN(now);
					now = parent[now];
				}

				return 1;
			}
		}

		sz = V[u].size();
		for(j = 0; j < sz; j++)
			if(vis[V[u][j]]==0)
			{
				parent[V[u][j]] = u;
				vis[V[u][j]] = 1;
				Q.push( V[u][j] );
			}
	}

	return 0;
}

int possible(int x)
{
	int i, flag = 0;

	if(key[ key_type[x] ]==0)
		return 0;

	if(key[ key_type[x] ] > 1)
		return 1;

	for(i = 1; i <= N; i++)
		if(status[i]==0 && i!=x && key_type[i]==key_type[x])
			flag = 1;

	if(flag == 0)
		return 1;

	remaining = 0;
	for(i = 1; i <= N; i++)
	{
		if(status[i]==0)
			remaining++;

		temp_status[i] = status[i];
	}

	for(i = 1; i <= 400; i++)
		temp_key[i] = key[i];

	OPEN(x);
	while(1)
	{
		if(remaining == 0)
			return 1;

		flag = 0;
		for(i = 1; i <= 400; i++)
			if(temp_key[i] && try_to_use(i))
			{
				flag = 1;
			}
		
		if(!flag)
			return 0;
	}
}

int check()
{
	int i, j, k;

	ans.clear();
	for(i = 1; i <= N; i++)
		status[i] = 0;

	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= N; j++)
		{
			if(status[j])
				continue;

			if(possible(j))
			{
				status[j] = 1;
				ans.push_back(j);

				key[ key_type[j] ]--;
				for(k = keys[j].size() - 1; k >= 0; k--)
					key[ keys[j][k] ]++;

				break;
			}
		}

		if(j > N)
			return 0;
	}

	return 1;
}

int ks;

void input()
{
	int K, i, k, n, j;

	scanf("%d %d", &K, &N);
	if(ks==21) printf(">>%d %d\n", K, N);

	for(i = 0; i <= 400; i++)
		key[i] = 0;

	for(i = 1; i <= K; i++)
	{
		scanf("%d", &k);
		if(ks==21) printf("%d ", k);

		key[k]++;
	}
	if(ks==21) printf("\n");
	
	for(i = 1; i <= N; i++)
	{
		scanf("%d", &key_type[i]);
		if(ks==21) printf(" %d", key_type[i]);

		scanf("%d", &n);
		if(ks==21) printf(" %d",n);
		keys[i].clear();
		for(j = 0; j < n; j++)
		{
			scanf("%d", &k);
			if(ks==21) printf(" %d",k);
			keys[i].push_back(k);
		}
		if(ks==21) printf("\n");
	}
}

void build_graph()
{
	int i, j, f[250], sz, k, jj;

	for(i = 1; i <= N; i++)
	{
		V[i].clear();

		for(j = 1; j <= N; j++)
			f[j] = 0;

		sz = keys[i].size();
		for(j = sz-1; j >= 0; j--)
		{
			k = keys[i][j];

			for(jj = 1; jj <= N; jj++)
				if(jj != i && key_type[jj] == k)
					f[jj] = 1;
		}

		for(j = 1; j <= N; j++)
			if(f[j])
				V[i].push_back(j);
	}
}

int main()
{
//	freopen("D-small-attempt1.in", "r", stdin);
//	freopen("D-small-attempt1.out", "w", stdout);

	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);

	int T, i, ks;

	scanf("%d", &T);
	for(ks = 1; ks <= T; ks++)
	{
		input();
		build_graph();

		if(!check())
		{
			printf("Case #%d: IMPOSSIBLE\n", ks);
		}
		else
		{
			printf("Case #%d:", ks);
			for(i = 0; i < N; i++)
				printf(" %d", ans[i]);
			printf("\n");
		}
	}

	return 0;
}