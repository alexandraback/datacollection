

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define NV 1005
#define NM 1000000
#define CLR(arr,v) memset(arr,v,sizeof(arr))

int h[NV],num[NM],nex[NM],vis[NM],pos;
bool vist[NV];
int Q[NV],head,total;

void clear()
{
	pos = 0;
	CLR(h,-1);
}

void add(int u,int v)
{
	num[pos] = v;
	nex[pos] = h[u];
	h[u] = pos++;
}

int main()
{
	//freopen("1.txt","r",stdin);
	//freopen("2.txt","w",stdout);
	int T,k = 1;
	scanf("%d",&T);
	while(T--)
	{
		clear();
		int n,t,e;
		scanf("%d",&n);
		for(int i = 1;i <= n;++i)
		{
			scanf("%d",&t);
			for(int j = 0;j < t;++j)
			{
				scanf("%d",&e);
				add(e,i);
			}
		}
		bool flag = false;
		int p;
		for(int i = 1;i <= n && !flag;++i)
		{
			CLR(vist,0);
			vist[i] = true;
			head = total = -1;
			Q[++total] = i;
			while(head < total && !flag)
			{
				p = Q[++head];
				for(int cur = h[p];cur != -1;cur = nex[cur])
				{
					if(!vist[ num[cur] ])
					{
						Q[++total] = num[cur];
						vist[ num[cur] ] = true;
					}
					else
					{
						flag = true;
						break;
					}
				}
			}
		}
		printf("Case #%d: ",k++);
		printf(flag ?"Yes\n":"No\n");
	}
}