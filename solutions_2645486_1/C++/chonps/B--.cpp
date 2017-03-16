#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<map>
#include<ctime>
#include<set>
#include<queue>
#include<cmath>
#include<vector>
#include<bitset>
#include<functional>
using namespace std;
ifstream fin ("B-large.in");
ofstream fout ("B-large.out");
typedef long long LL;
typedef double ld;
const int MAX=100000+10;
const LL INF=(LL)1e17;
int E,R,N;
struct Edge{
	int s,t,next;
	LL cost,flow,c;
}e[MAX];
int begin[MAX],tot=2,S,T;
void addedge(int s,int t,LL C,LL cost){
	e[tot].s=s;
	e[tot].t=t;
	e[tot].c=C;
	e[tot].cost=cost;
	e[tot].flow=0;
	e[tot].next=begin[s];
	begin[s]=tot;
	tot++;
}
void add(int s,int t,LL C,LL cost){
	addedge(s,t,C,cost);
	addedge(t,s,0,-cost);
}
int n,m;
queue<int> q;
LL dist[MAX];
int come[MAX],hash[MAX];
int SPFA(){
	int u,v,i;
	for(i=1;i<=T;++i){
		dist[i]=-INF;
		hash[i]=0;
		come[i]=-1;
	}
	hash[S]=1;
	come[S]=0;
	dist[S]=0;
	q.push(S);
	while(!q.empty()){
		u=q.front();
		q.pop();
		hash[u]=0;
		for(i=begin[u];i;i=e[i].next){
			v=e[i].t;
			if(e[i].c-e[i].flow>0){
				if(dist[v]<dist[u]+e[i].cost){
					dist[v]=dist[u]+e[i].cost;
					come[v]=i;
					if(!hash[v]){
						hash[v]=1;
						q.push(v);
					}
				}
			}
		}
	}
	return dist[T];
}
LL MinCostMaxFlow(){
	int now,j;
	LL dis;
	LL ans=0;
	LL minflow;
	while((dis=SPFA())>0){
		minflow=INF;
		now=T;
		while(now!=S){
			j=come[now];
			minflow=min(e[j].c-e[j].flow,minflow);
			now=e[j].s;
		}
		now=T;
		while(now!=S){
			j=come[now];
			e[j].flow+=minflow;
			e[j^1].flow-=minflow;
			now=e[j].s;
		}
		ans+=dis*minflow;
	}
	return ans;
}
int val[MAX];
int Main(){
	tot=2;
	memset(begin,0,sizeof begin);
	int i;
	fin >> E >> R >> N;
	for (i=1;i<=N;++i)
		fin >> val[i];
	S=2*N+1,T=2*N+2;
	for (i=1;i<=N;++i){
		add(2*i-1,T,INF,val[i]);
		add(2*i-1,2*i,INF,0);
		add(S,2*i,R,0);
		if(i!=N)
			add(2*i,2*i+1,E,0);
	}
	add(S,1,E,0);
	fout << MinCostMaxFlow() << endl;
	return 0;
}
int main(){
	int T;
	fin >> T;
	for(int i=1;i<=T;++i){
		fout << "Case #" << i << ": ";
		Main();
	}
	return 0;
}
