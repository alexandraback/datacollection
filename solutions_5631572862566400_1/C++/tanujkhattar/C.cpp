//Tanuj Khattar
#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int>   II;
typedef vector< II >      VII;
typedef vector<int>     VI;
typedef vector< VI > 	VVI;
typedef long long int 	LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

//#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

//FILE *fin = freopen("in","r",stdin);
//FILE *fout = freopen("out","w",stdout);

const int N = int(1e6)+10;
VI g[N];
int vis[N],U[N],V[N],W[N],isCycle[N],S[N],st,far[N],C[N],E[N],clen;
LL depth[N],dp[N];
pair<LL,int> dq[2*N];
inline int adj(int u,int e){
	return U[e]^V[e]^u;
}
inline void dfs0(int u,int ee){
	vis[u]=1;S[++st]=ee;
	for(auto e:g[u]){
		if(e==ee)continue;
		int w = adj(u,e);
		if(vis[w] && !isCycle[w]){
			int curr = u;isCycle[u]=1;
			C[clen++]=curr;
			while(curr!=w){
				int up = adj(curr,S[st]);
				C[clen]=up;
				E[clen-1]=W[S[st]];
				clen++;st--;curr=up;
				isCycle[curr]=1;
			}
			C[clen]=u;E[clen-1]=W[e];clen++;
		}
		else if(!vis[w])
			dfs0(w,e);
	}
	if(S[st]==ee)st--;
}
LL mxd,ans2;
inline void dfs1(int u,int p){
	far[u]=u;VI child;
	for(auto e:g[u]){
		int w = adj(u,e);
		if(w==p || isCycle[w])continue;
		depth[w] = depth[u] + W[e];
		dfs1(w,u);child.PB(depth[far[w]]);
		if(depth[far[u]] < depth[far[w]])
			far[u]=far[w];
	}
	sort(ALL(child));reverse(ALL(child));
	if(SZ(child)>1)mxd = max(mxd,child[0]+child[1]-2*depth[u]);
}
LL get_diameter(int root){
	mxd = 0;depth[root]=0;
	dfs1(root,root);
	dp[root]=depth[far[root]];
	if(clen>3)dp[root]=-LL(1e8);
	return min(0ll,mxd);
}
LL get_cycle(){
	LL ret = 0, add = 0, sub = 0;
	int l = 0, h = 0;
	for(int i=1;i<clen-1;i++){
		add += E[i-1];
		while(h>l && dq[h].F < (add+dp[C[i]]))h--;
		dq[++h] = {add+dp[C[i]],C[i]};
	}
	int r = clen-1;
	for(int i=1;i<clen;i++){
		ret = max(ret,dp[C[i-1]] + dq[l+1].F - sub);
		sub += E[i-1];
		if(dq[l+1].S==C[i])l++;
		add += E[r-1];
		while(h>l && dq[h].F < (add + dp[C[r]]))h--;
		dq[++h]={add+dp[C[r]],C[r]};
		r++;if(r==clen)r=1;
	}
	return ret;
}
LL go(int root){
	LL ret = 0;clen=st=0;
	//find cycle
	dfs0(root,0);ans2 = max(ans2,clen-1ll);
	//process tree hanging at each vertex of cycle
	for(int i=0;i<clen-1;i++)
		ret = max(ret,get_diameter(C[i]));
	trace(ret);
	//check for the max length path across cycle
	ret = max(ret,get_cycle());
	trace(ret);
	reverse(C,C+clen);reverse(E,E+clen-1);
	ret = max(ret,get_cycle());
	trace(ret);
	if(!ret)ret=-1;
	//done :) 
	return ret;
}
int main()
{
	int t;si(t);
	for(int T=1;T<=t;T++)
	{
		printf("Case #%d: ",T);
		int n;si(n);
		for(int i=1;i<=n;i++)
		{
			U[i]=i;scanf("%d",V+i);W[i]=1;
			g[U[i]].PB(i);
			g[V[i]].PB(i);
		}
		LL ans = 0;ans2=0;
		for(int i=1;i<=n;i++)
			if(!vis[i])
				ans += 1 + go(i);
		lldout(max(ans,ans2));
		SET(vis,0);SET(isCycle,0);
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
}
