#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME "/Users/kybconnor/Download/"
#define UsingFile 0
const LL MOD = 1000000007;
const double PI = acos(-1.);
#define N 2010
int G[N][N],n;
bool vis[N];
int match[N];
bool dfs(int x){
	for(int i=1;i<=n;i++){
		if(!G[x][i])continue;
		if(!vis[i]){
			vis[i]=1;
			int &tp=match[i];
			if(tp==-1||dfs(tp)){
				match[i]=x;
				match[x]=i;
				return 1;
				}
			}
		}
	return 0;
	}
int greedy_match(){
	int ans=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		if(!G[i][j])continue;
		if(match[i]!=-1)continue;
		if(match[j]==-1){
			match[i]=j;
			match[j]=i;
			ans++;
			break;
			}
		} 
	return ans;
	}
int Hungrary(){
	memset(match,-1,sizeof(match));
	int res=greedy_match();
	for(int i=1;i<=n;i++){
		if(match[i]!=-1)continue;
		memset(vis,0,sizeof(vis));
		vis[i]=1;
		if(dfs(i))res++;
		}
	return res;
	}
int main(){
    if(UsingFile)freopen(NAME".in","r",stdin);
    if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    cin>>_T;
    for(int CA=1;CA<=_T;CA++){
    	int m;
    	cin>>m;
    	map<string,int>P,Q;
    	memset(G,0,sizeof G);
    	n=0;
    	for(i=0;i<m;i++){
    		string p,q;
    		cin>>p>>q;
    		if(P.find(p)==P.ED)
    			P[p]=++n;
    		if(Q.find(q)==Q.ED)
    			Q[q]=++n;
    		G[P[p]][Q[q]]=1;
    	}
    	int tmp=Hungrary();
    	int ret=n-tmp;
    	printf("Case #%d: %d\n",CA,m-ret);
    }
    return 0;
}