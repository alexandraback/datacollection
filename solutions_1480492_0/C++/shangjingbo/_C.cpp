#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn		=	55;
const int limit		=	100;
const double eps	=	1e-10;

char side[maxn][5];
int S[maxn],P[maxn],n;
vector<double> event;

const int maxnode	=	(2*maxn*maxn*maxn+100)*2;

vector<int> adj[maxnode];
int stack[maxnode],low[maxnode],color[maxnode],NB,dep,cnt,N;
bool vis[maxnode];

inline void add(int a,int b)
{
	//printf("%d-->%d\n",a,b);
	adj[a].push_back(b);
}

inline void dfs(int u)
{
	vis[u]=true;
	stack[dep++]=u;
	low[u]=++cnt;
	int Min=low[u];
	for (int p=0;p<adj[u].size();++p){
		if (!vis[adj[u][p]]) dfs(adj[u][p]);
		Min=min(low[adj[u][p]],Min);
	}
	
	if (Min==low[u]){
		++NB;
		int v;
		do{
			v=stack[--dep];
			color[v]=NB;
			low[v]=1000000000;
		}while (v!=u);
	}else low[u]=Min;
}

inline bool check(int limit)
{
	N=event.size()*n;
	
	for (int i=0;i<2*N;++i) adj[i].clear();
	
	bool last[maxn],intersect[maxn];
	memset(last,false,sizeof(last));
	for (int i=0;i<=limit;++i){
		for (int j=0;j<n;++j){
			if (i==0){
				if (side[j][0]=='L') add(j*event.size()+i+N,j*event.size()+i);
				if (side[j][0]=='R') add(j*event.size()+i,j*event.size()+i+N);
			}else{
				intersect[j]=false;
				for (int k=0;k<n;++k)
				if (j!=k){
					double pj1=P[j]+S[j]*event[i];
					double pk1=P[k]+S[k]*event[i];
					if (fabs(pj1-pk1)>=5) continue;
					intersect[j]=true;
					add(j*event.size()+i,k*event.size()+i+N);
					add(j*event.size()+i+N,k*event.size()+i);
				}
				if (last[j] && intersect[j]){
					add(j*event.size()+i-1,j*event.size()+i);
					add(j*event.size()+i-1+N,j*event.size()+i+N);
					add(j*event.size()+i,j*event.size()+i-1);
					add(j*event.size()+i+N,j*event.size()+i-1+N);
				}
				last[j]=intersect[j];
			}
		}
		//printf("--------------\n");
	}
	
	dep=cnt=NB=0;
	memset(vis,false,sizeof(vis));
	for (int i=0;i<2*N;++i)
	if (!vis[i]) dfs(i);
	
	for (int i=0;i<N;++i)
	if (color[i]==color[i+N]) return false;
	return true;
}

int main()
{
	freopen("in3.txt","r",stdin);
	freopen("xx.out","w",stdout);
	
	int T,test=1;
	for (scanf("%d",&T);test<=T;++test){
		scanf("%d",&n);
		for (int i=0;i<n;++i){
			scanf("%s%d%d",&side[i],&S[i],&P[i]);
		}
		event.clear();
		for (int i=0;i<n;++i){
			for (int j=0;j<n;++j)if (S[j]!=S[i]){
				double dp=P[i]-P[j];
				double dv=S[j]-S[i];
				double dt1=(dp+5)/dv;
				double dt2=(dp-5)/dv;
				if (dt1>=0) event.push_back(dt1);
				if (dt2>=0) event.push_back(dt2);
			}
		}
		event.push_back(0);
		sort(event.begin(),event.end());
		event.erase( unique(event.begin(),event.end()) , event.end() );
		
		if (check(event.size()-1)){
			printf("Case #%d: Possible\n",test);
			continue;
		}
		
		for (int i=0;i<event.size();++i){
			printf("%lf ",event[i]);
		}
		puts("");
		
		int l=0,r=event.size();
		while (l+1<r){
			int mid=(l+r)/2;
			if (check(mid)) l=mid;
			else r=mid;
		}
		printf("Case #%d: %.10f\n",test,event[l]);
	}
	return 0;
}

