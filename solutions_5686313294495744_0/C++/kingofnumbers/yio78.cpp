#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
 
 
 
class dinic{
public:
	struct edge{
		int a,b;
		int c,f;
	};
	int n,m;
	static const int inf=2000000200;
	vector<edge> list;
	vector<vector<edge*> > adj;
	vector<int> dist;
	vector<int> B;
	int bfs;
	int source,sink;
	void init(int N,int so,int si){
		dist.resize(N+3);
		adj.resize(N+3);
		B.resize(N+3);
		source=so;
		sink=si;
		n=N;
		m=0;
		bfs=0;
	}
	void add_edge(int from,int to, int cap,bool directed){
		edge t;
		list.push_back(t);
		list[m].a=from;
		list[m].b=to;
		if(directed){	
			list[m].c=cap;
			list[m].f=0;
		} else {
			list[m].c=2*cap;
			list[m].f=cap;
		}
		m++;
		
	}
	
	void BFS(){
		B[0]=sink;
		bfs=1;
		for(int i=1;i<=n;i++){
			dist[i]=inf;
		}
		dist[sink]=0;
		int nd,nd_adj;
		for(int i=0;i<bfs;i++){
			nd=B[i];
			for(int i=0;i<adj[nd].size();i++){
				if(adj[nd][i]->a==nd){
					nd_adj=adj[nd][i]->b;
					if(dist[nd_adj]==inf &&  adj[nd][i]->f>0){
						B[bfs++]=nd_adj;
						dist[nd_adj]=dist[nd]+1;
					}
				} else {
					nd_adj=adj[nd][i]->a;
					if(dist[nd_adj]==inf && adj[nd][i]->f<adj[nd][i]->c){
						B[bfs++]=nd_adj;
						dist[nd_adj]=dist[nd]+1;
					}
				}
			}
		}
	}
	long long dfs(int node,long long flow){
		long long ret=0;
		if(node==sink){
			return flow;
		}
		for(int i=0;i<adj[node].size();i++){
			if(flow==0)break;
			if(adj[node][i]->a==node){
				int nd_adj=adj[node][i]->b;
				if(dist[node]==dist[nd_adj]+1 && adj[node][i]->f<adj[node][i]->c){
					long long f=dfs(nd_adj,min(flow,0ll+adj[node][i]->c-adj[node][i]->f));
					ret+=f;
					adj[node][i]->f+=f;
					flow-=f;
				}
			} else {
				int nd_adj=adj[node][i]->a;
				if(dist[node]==dist[nd_adj]+1 && adj[node][i]->f>0){
					long long f=dfs(nd_adj,min(flow,0ll+adj[node][i]->f));
					ret+=f;
					adj[node][i]->f-=f;
					flow-=f;
				}
			}
		}
		return ret;
	}
	long long solve(){
		for(int i=0;i<m;i++){
			adj[list[i].a].push_back(&list[i]);
			adj[list[i].b].push_back(&list[i]);
		}
		long long sol=0;
		while(true){
			BFS();
			if(dist[source]==inf)break;
			sol+=dfs(source,10000000000000000ll);
		}
		return sol;
	}
};

int T;
string list1[1111];
string list2[1111];

int n1,n2;
int s,t;
int k;
map<string,int> mp1,mp2;
int id1[1111];
int id2[1111];
int deg1[1111];
int deg2[1111];
int nod=1;
int main(){
	freopen("ddee.in","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	for(int jj=1;jj<=T;jj++){
		mp1.clear();
		mp2.clear();
		cin>>k;
		n1=n2=1;
		nod=1;
		for(int i=0;i<k;i++){
			cin>>list1[i]>>list2[i];
			if(mp1.count(list1[i])==0){
				mp1[list1[i]]=n1++;
			}
			if(mp2.count(list2[i])==0){
				mp2[list2[i]]=n2++;
			}
		}
		n1--;
		n2--;
		for(int i=1;i<=n1;i++){
			deg1[i]=0;
		}
		for(int i=1;i<=n2;i++){
			deg2[i]=0;
		}
		for(int i=0;i<k;i++){
			deg1[mp1[list1[i]]]++;
			deg2[mp2[list2[i]]]++;
		}
		s=nod++;
		t=nod++;
		for(int i=1;i<=n1;i++){
			id1[i]=nod++;

		}
		for(int i=1;i<=n2;i++){
			id2[i]=nod++;
		}
		dinic flow;
		flow.init(nod+3,s,t);
		for(int i=0;i<k;i++){
			flow.add_edge(id1[mp1[list1[i]]],id2[mp2[list2[i]]],1,true);
		}
		for(int i=1;i<=n1;i++){
			flow.add_edge(s,id1[i],deg1[i]-1,true);
		}
		for(int i=1;i<=n2;i++){
			flow.add_edge(id2[i],t,deg2[i]-1,true);
		}
		cout<<"Case #"<<jj<<": "<<flow.solve()<<endl;
	}
}