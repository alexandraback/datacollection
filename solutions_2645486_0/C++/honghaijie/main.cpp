#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

#define N 600

typedef long long LL;

int c1[N], d1[N],c2[N], d2[N];
int n, n1, n2;
#define EPS 1e-9

#define maxn 600
#define maxm 4000
#define inf 100000000000000
struct Edge{ int u,v,cap,x; LL cost; }E[maxm];
int e,l[maxn];
inline void init(){ e=0; memset(l,-1,sizeof(l)); }
inline void insert(int u,int v,int cap,LL cost){ //单向边
    E[e].u=u; E[e].v=v; E[e].cap=cap; E[e].cost= cost; E[e].x=l[u]; l[u]=e++;
	E[e].u=v; E[e].v=u; E[e].cap=0  ; E[e].cost=-cost; E[e].x=l[v]; l[v]=e++;
}
int q[20*maxn],s,t, inq[maxn],eid[maxn];
LL dis[maxn];
void min_cost_max_flow(int src,int sink,LL &cap,LL &cost){//0~n-1
	cost=0;
    cap=0;
	while( true ){ //不断增广
		//begin spfa
		//for(int i=0;i<maxn;i++) dis[i]=inf; //-inf  最大费
		for (int i = 0; i < sink + 10; i++) dis[i] = -inf;
		s=t=0; q[t++]=src; inq[src]=1; dis[src]=0;
		while(s<t){
			int u=q[s++]; inq[u]=0;
			for(int p=l[u];p>=0;p=E[p].x){
				if( E[p].cap<=0 ) continue;
				int v=E[p].v;
			//	if( dis[v]>dis[u]+E[p].cost ){  //<
			    if (dis[v] < dis[u] + E[p].cost) {
					dis[v]=dis[u]+E[p].cost; eid[v]=p;
					if( inq[v]==0 ){
						inq[v]=1; q[t++]=v;
					}
				}
			}
		} //end spfa
		if( dis[sink]<=-inf) return;  //<=-inf
		int c=inf;
		for(int i=sink;i!=src;i=E[eid[i]].u) c=min(c,E[eid[i]].cap);
		cost+=dis[sink]*c;  cap+=c;
		for(int i=sink;i!=src;i=E[eid[i]].u) {
			int p=eid[i];  E[p].cap-=c; E[p^1].cap+=c;
		}
	}
}

int en,r;
int c[12000];

int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
	int n,m,u,v,T;
    cin>>T;
    int ca=0;
    while (T--)
    {
        init();
        cin>>en>>r>>n;
        for (int i=1;i<=n;i++) cin>>c[i];
        insert(0,1,en,0);
        for (int i=2;i<=n;i++)
        {
            insert(0,i,r,0);
            if (en-r>0) insert(i-1,i,en-r,0);
        }

        for (int i=1;i<=n;i++)
        {
            insert(i,n+1,0x7f7f7f7f,c[i]);
        }
        LL cap;
		LL cost;
        min_cost_max_flow(0,n+1,cap,cost);
        printf("Case #%d: ",++ca);
        cout<<(int)(cost+0.5)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}

