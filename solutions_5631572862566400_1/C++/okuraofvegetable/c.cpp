#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
template<class T> void chmin(T& a,const T& b){if(a>b)a=b;}
template<class T> void chmax(T& a,const T& b){if(a<b)a=b;}
vector<int> G[1010],rG[1010];
vector<int> vs;
int V;
bool used[1010];
int cmp[1010],to[1010];
void add_edge(int from,int to){
    G[from].pb(to);
    rG[to].pb(from);
    return;
}
void dfs(int s){
    used[s]=true;
    for(int i=0;i<G[s].size();i++){
        if(!used[G[s][i]])dfs(G[s][i]);
    }
    vs.pb(s);
}
void rdfs(int s,int k){
    used[s]=true;
    cmp[k]++;
    for(int i=0;i<rG[s].size();i++){
        if(!used[rG[s][i]])rdfs(rG[s][i],k);
    }
}
int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(!used[v])dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]])rdfs(vs[i],k++);
    }
    return k;
}
int rDfs(int v,int p){
	int res = 0;
	for(int i=0;i<rG[v].size();i++){
		int t = rG[v][i];
		if(t==p)continue;
		res = max(rDfs(t,v),res);	
	}
	return res+1;
}
int solve(){
	for(int i=0;i<1010;i++){
		G[i].clear();
		rG[i].clear();
	}
	vs.clear();
	memset(cmp,0,sizeof(cmp));
	scanf("%d",&V);
	for(int i=0;i<V;i++){
		scanf("%d",&to[i]);
		to[i]--;
		add_edge(i,to[i]);
	}
	scc();
	int ans = 0,ret = 0;
	for(int i=0;i<V;i++)ans = max(cmp[i],ans);
	memset(used,false,sizeof(used));
	for(int i=0;i<V;i++){
		if(used[i])continue;
		if(to[to[i]]==i){
			used[i]=true;
			used[to[i]]=true;
			ret += rDfs(i,to[i])+rDfs(to[i],i);
		}
	}
	//cout << ans << endl;
	return max(ans,ret);
}
int main(){
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++){
		printf("Case #%d: %d\n",t+1,solve());
	}
	return 0;
}
