#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define PII pair<int,int>
typedef long long LL;
using namespace std;
int Te,n,cnt[2],a[1010][2];
string St[1010][2];
map<string,int> A[2];
struct edge
{
    int next,other,va;
}e[20010];
int head[2010],dis[2010],di[2010],vh[2010],S,T,tot,his[2010],pre[2010],inf=1e9,ans;
void add(int x,int y,int z)
{
    e[++tot].next=head[x];head[x]=tot;e[tot].other=y;e[tot].va=z;
    e[++tot].next=head[y];head[y]=tot;e[tot].other=x;e[tot].va=0;
}
void flow()
{
    int aug=inf,u=S;
    vh[0]=T;
    for(int i=S;i<=T;i++) di[i]=head[i];
    while (dis[S]<T)
    {
        bool flag=0;his[u]=aug;
        for(int i=di[u];i;i=e[i].next)
        {
            int v=e[i].other;
            if (dis[u]==dis[v]+1&&e[i].va)
            {
                pre[v]=i;di[u]=i;u=v;aug=min(aug,e[i].va);flag=1;
                if (u==T)
                {
                    ans+=aug;
                    for(;u!=S;u=e[pre[u]^1].other)
                    {
                        e[pre[u]].va-=aug;
                        e[pre[u]^1].va+=aug;
                    }
                    aug=inf;
                }
                break;
            }
        }
        if (flag) continue;
        int Min=T,j=0;
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].other;
            if (Min>dis[v]&&e[i].va)
            {
                Min=dis[v];j=i;
            }
        }
        if ((--vh[dis[u]])==0) break;
        vh[dis[u]=Min+1]++;di[u]=j;
        if (u!=S)
        {
            u=e[pre[u]^1].other;
            aug=his[u];
        }
    }
}
template<class T>
void read(T&x)
{
	char ch=getchar();int mk=1;x=0;for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if (ch=='-') mk=-1,ch=getchar();for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-48;x*=mk;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&Te);
	for(int _=1;_<=Te;_++)
	{
		printf("Case #%d: ",_);
		scanf("%d",&n);
		A[0].clear();A[1].clear();
		cnt[0]=cnt[1]=0;
		for(int i=0;i<n;i++)
		{
			cin>>St[i][0]>>St[i][1];
			for(int j=0;j<2;j++)
			{
				int t=A[j][St[i][j]];
				if (t==0) A[j][St[i][j]]=t=++cnt[j];
				a[i][j]=t;
			}
			//printf("%d %d\n",a[i][0],a[i][1]);
		}
		S=1;T=cnt[0]+cnt[1]+2;tot=1;memset(e,0,sizeof(e));
		memset(head,0,sizeof(head));
		memset(dis,0,sizeof(dis));
		memset(di,0,sizeof(di));
		memset(vh,0,sizeof(vh));
		memset(pre,0,sizeof(pre));
		memset(his,0,sizeof(his));
		for(int i=1;i<=cnt[0];i++) add(S,i+1,1);
		for(int i=1;i<=cnt[1];i++) add(i+cnt[0]+1,T,1);
		for(int i=0;i<n;i++) add(a[i][0]+1,a[i][1]+cnt[0]+1,1);
		ans=0;
		flow();
		printf("%d\n",n-(cnt[0]+cnt[1]-ans));
	}
}


