#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#define FI first
#define SE second
using namespace std;
const int MAXN = 10000005;
const double INF = 100000005;
int n,m;
struct Edge{
	int u,v,w,next;
}edge[MAXN*3];
int head[MAXN],en;
int dist[MAXN];
bool vis[MAXN];
void addedge(int u,int v,int w) {
	edge[en].u=u,edge[en].v=v,edge[en].w=w;
	edge[en].next=head[u];
	head[u]=en++;
}
void init() {
    en = 0;
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
}
void spfa(int s) {
	queue<int> q;

	for(int i=0;i<MAXN;i++)	dist[i]=INF;
	dist[s]=0;
	q.push(s);
	while(!q.empty()) {
	int fr=q.front();
	//cout<<fr<<endl;
	q.pop(),vis[fr]=0;
	for(int e=head[fr];e!=-1;e=edge[e].next)
	{
	int v=edge[e].v;
	if(dist[v]>dist[fr]+edge[e].w)
	{
	dist[v]=dist[fr]+edge[e].w;
	if(!vis[v])
	{
	vis[v]=1;
	q.push(v);
	}
	}
	}
	}
	return;
}
int getRev(int a) {
    int ret = 0;
    while(a) {
        ret = ret * 10 + a % 10;
        a /= 10;
    }
    return ret;
}
int main() {
    int cas;
    scanf("%d", &cas);
    init();
    for (int i = 1; i < MAXN; ++i) {
        addedge(i, i + 1, 1);
        int rev = getRev(i);
        if (rev != i && rev < MAXN) {
            addedge(i, rev, 1);
        }
    }
    //cout<<en<<endl;
    spfa(1);

    for (int ca = 1; ca <= cas; ++ca) {
        scanf("%d", &n);
        printf("Case #%d: %d\n", ca, dist[n]+1);
    }
    return 0;
}
