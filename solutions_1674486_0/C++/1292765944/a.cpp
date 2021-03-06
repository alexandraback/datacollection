#include<iostream>
#include<cstdio>
#include<string.h>
#include<string>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 100000000
#define min(a,b) ((a)>(b))?(b):(a)

using namespace std ;
int n,k,dist[1110],gap[1110],edgeHead[1100],map[1010][1010];//双向边
struct{
    int v, cap, next, re;
}edge[1110];
int beg,dis;

void addEdge(int u,int v,int ca){
    edge[k].v=v;
    edge[k].cap=ca;
    edge[k].next=edgeHead[u];
    edge[k].re=k + 1;               //这个用来记录此边的反边
    edgeHead[u]=k ++;
    edge[k].v=u;
    edge[k].cap=0;
    edge[k].next=edgeHead[v];
    edge[k].re=k - 1;
    edgeHead[v]=k ++;
}

int dfs (int p , int limit)
{
    if(p==dis)return limit;

    for(int i=edgeHead[p];i!=0;i=edge[i].next){
        int v = edge[i].v;
        if(dist[p]==(dist[v]+1) && edge[i].cap>0){
            int t=dfs(v,min(limit , edge[i].cap));
            if(t<0)return t;//没有增广路了
            if(t>0)//更新流
            {
                edge[i].cap-=t;
                edge[edge[i].re].cap+=t;
                return t;
            }
        }
    }

    int tmp=n+1 ;
    for(int i=edgeHead[p];i!=0;i=edge[i].next){
        int v = edge[i].v;
        if(edge[i].cap>0)
            tmp=min(tmp,dist[v]+1);
    }

    if(--gap[dist[p]]==0 || dist[beg]>n)return -1;//出现断层或回流已满
    ++gap[dist[p]=tmp];
    return 0;
}

int SAP()
{
    gap[0]=n+1;
    int f = 0 , t=0;
    while (~(t=dfs(beg,INF))) f+=t;
    return f;
}
int main(){
    int t,T,i,j,u,v;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("b.out","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%d",&n);
		memset(map,0,sizeof(map));
		for(i=1;i<=n;i++){
			int sum;
			scanf("%d",&sum);
			map[i][0]=sum;
			for(j=1;j<=sum;j++){
				scanf("%d",&v);
				map[i][j]=v;
			}
		}

		bool flag=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++){
				if(i==j)
					continue;
				memset(edgeHead,0,sizeof(edgeHead));
				k=1;
				for(u=1;u<=n;u++)
					for(v=1;v<=map[u][0];v++)
						addEdge(u,map[u][v],1);
				memset(dist,0,sizeof(dist));
				memset (gap , 0 , sizeof(gap));
				beg=i,dis=j;
				int ans=SAP();
				if(ans>=2)
					flag=1;
			}
		if(flag)
			printf("Yes\n");
		else
			printf("No\n");
	}
}
