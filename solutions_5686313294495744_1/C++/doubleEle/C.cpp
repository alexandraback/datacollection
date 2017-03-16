#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

const int INF=10000000;

struct Edge
{
	int to,nxt,limit;
}edge[10000];

struct node
{
	//char s[30];
	string s;
	int id;
	bool operator < (const node &o) const
	{
		/*int len0=strlen(s),len1=strlen(o.s);
		if (len0!=len1) return len0<len1;
		for (int i=0; i<len0; i++)
		  if (s[i]!=o.s[i])
		    return s[i]<o.s[i];
		return s[0]<o.s[0];*/
		return s<o.s;
	}
}a[1005],b[1005];

int q[2005],p[2005],tot,num,n,T,S,t,vis[2005],forb[2005],fir[2005];

void addedge(int x,int y,int z)
{
	edge[tot]=(Edge) {y,fir[x],z}; fir[x]=tot++;
	edge[tot]=(Edge) {x,fir[y],0}; fir[y]=tot++;
}

bool bfs()
{
    memset(vis,0,sizeof(vis));
    memset(forb,0,sizeof(forb));
    vis[S]=1; q[1]=S;
    int head=1,tail=1;
    while (head<=tail)
    {
        int x=q[head];
        for (int i=fir[x]; i!=-1; i=edge[i].nxt)
          if ((vis[edge[i].to]==0)&&(edge[i].limit>0))
          {
              q[++tail]=edge[i].to;
              vis[edge[i].to]=vis[x]+1;
          }
        head++;
    }
    if (vis[T]==0) return 0;
              else return 1;
}

int dinic(int x,int flow)
{
    if ((x==T)||(flow==0)) return flow;
    int ret=0,f;
    for (int i=fir[x]; i!=-1; i=edge[i].nxt)
      if ((vis[edge[i].to]==vis[x]+1)&&(forb[edge[i].to]==0))
      {
          f=dinic(edge[i].to,min(flow-ret,edge[i].limit));
          edge[i].limit-=f;
          edge[i^1].limit+=f;
          ret+=f;
          if (ret==flow) break;;
      }
    if (ret==0) forb[x]=1;
    return ret;
}

int main()
{
//	freopen("C-large.in","r",stdin);
//	freopen("C-large.out","w",stdout);
	ios::sync_with_stdio(false);
	cin >> t;
	for (int id=1; id<=t; id++)
	{
		cin >> n;
		S=0; T=n*2+1;
		memset(fir,-1,sizeof(fir)); tot=num=0;
		for (int i=1; i<=n; i++)
		{
//			cin >> n;
			cin >> a[i].s;
			cin >> b[i].s;
//			scanf("%s",a[i].s);
//			scanf("%s",b[i].s);
			a[i].id=b[i].id=i;
		}
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		//for (int i=1; i<=n; i++) cout << i << ' ' << b[i].id << ' ' << b[i].s << endl;
		p[a[1].id]=++num; addedge(S,num,1);
		for (int i=2; i<=n; i++)
		{
			if (a[i].s!=a[i-1].s) 
			{
				num++;
				addedge(S,num,1);
			}
			p[a[i].id]=num;
		}
		q[b[1].id]=++num; addedge(num,T,1);
		for (int i=2; i<=n; i++)
		{
			if (b[i].s!=b[i-1].s) 
			{
				num++;
				addedge(num,T,1);
			}
			q[b[i].id]=num;
		}
		for (int i=1; i<=n; i++) addedge(p[i],q[i],1);
//		cout << 'a' << endl;
		n-=num;
		while (bfs()) n+=dinic(S,INF);
		cout << "Case #" << id << ": " << n << endl;
		//printf("Case #%d: %d\n",id,n);
	}
	return 0;
}
