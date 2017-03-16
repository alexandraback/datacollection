#include<bits/stdc++.h>
using namespace std;

#define scl(x) scanf("%lld",&x)
#define sc(x)  scanf("%d",&x)
#define ll long long
#define lop(i,n) for(int i=0;i<n;++i)
typedef pair<int,int> ii;
typedef pair<ll,ll> pll;

const int maxN=2100,maxE=6200;

int n,src,snk,cap[maxE];
int head[maxN],headcpy[maxN],nxt[maxE],to[maxE],edgeCnt;

void init(){
	memset(head,-1,sizeof head);
	edgeCnt=0;
}
void addedge(int u,int v,int c){
	nxt[edgeCnt]=head[u];
	head[u]=edgeCnt;
	cap[edgeCnt]=c;
	to[edgeCnt++]=v;
}

void addbiedge(int u,int v,int c){
	addedge(u,v,c);
	addedge(v,u,0);
}
int Rank[maxN];

int ddfs(int cur=src,int flow=1){
	if(cur==snk)
		return flow;
	for(int &i=headcpy[cur];i!=-1;i=nxt[i]){
		int t=to[i];
		if(!cap[i]||Rank[t]!=Rank[cur]+1)
			continue;
		int f=ddfs(t,min(flow,cap[i]));
		cap[i]-=f;
		cap[i^1]+=f;
		if(f)
			return f;
	}
	return 0;
}
int Q[maxN];
bool dbfs(){
	memset(Rank,-1,sizeof Rank);
	int Qi=0;
	Q[Qi++]=src;
	Rank[src]=0;
	for(int i=0;i<Qi;++i){
		int cur=Q[i];
		int r=Rank[cur];
		for(int j=head[cur];j!=-1;j=nxt[j]){
			int t=to[j];
			if(!cap[j]||Rank[t]!=-1)
				continue;
			Rank[t]=r+1;
			Q[Qi++]=t;
			if(t==snk)
				return 1;
		}
	}
	return 0;
}

int dinic(){
	int ret=0,f;
	while(dbfs()){
		memcpy(headcpy,head,sizeof head);
		while(f=ddfs()){
			ret+=f;
		}
	}
	return ret;
}

map<string,int> mp;
struct node{
	int f,s,idx;
};
bool cmp1(node a,node b){
	return a.f<b.f;
}
bool cmp2(node a,node b){
	return a.s<b.s;
}
int t,arr[1010],N,wid,cf,cov[2500];//remove n,src,snk later
vector<node> vec;

int main(){
#ifndef ONLINE_JUDGE
	freopen("i.txt","r",stdin);
	freopen("o.txt","w",stdout);
#endif
	cin>>t;
	lop(C,t){
		memset(cov,0,sizeof cov);
		wid=0;
		n=0;
		mp.clear();
		vec.clear();
		init();
		sc(N);
		lop(i,N){
			string a,b;
			cin>>a>>b;
			if(!mp.count(a))mp[a]=wid++;
			if(!mp.count(b))mp[b]=wid++;
			node nn;nn.f=mp[a];nn.s=mp[b];nn.idx=i;
			vec.push_back(nn);
		}
		sort(vec.begin(),vec.end(),cmp1);
		lop(i,N){
			arr[vec[i].idx]=n;
			while(i+1<N&&vec[i+1].f==vec[i].f){
				++i;
				arr[vec[i].idx]=n;
			}
			++n;
		}
		cf=n;
		sort(vec.begin(),vec.end(),cmp2);
		lop(i,N){
			addbiedge(arr[vec[i].idx],n,1);
			while(i+1<N&&vec[i].s==vec[i+1].s){
				++i;
				addbiedge(arr[vec[i].idx],n,1);
			}
			++n;
		}
		src=n++;
		snk=n++;
		lop(i,cf){
			addbiedge(src,i,1);
		}
		for(int i=cf;i<n-2;++i){
			addbiedge(i,snk,1);
		}
		int out=dinic();
		for(int i=0;i<cf;++i){
			for(int j=head[i];j!=-1;j=nxt[j]){
				if(to[j]==src)continue;
				if(!cap[j]){
					cov[i]=1;
					cov[to[j]]=1;
				}
			}
		}
		lop(i,n-2){
			out+=!cov[i];
		}
		printf("Case #%d: %d\n",C+1,N-out);
	}
};
