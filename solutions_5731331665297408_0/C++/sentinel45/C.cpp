/*
@author: Ankit Srivastava
*/

#include<bits/stdc++.h>
using namespace std;
#define MOD 					1000000007
#define pb(x) 					push_back(x)
#define mp(x,y)                 make_pair(x,y)
#define FF 						first
#define SS 						second
#define s(n) 					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define maX(a,b)				((a)>(b)?(a):(b))
#define miN(a,b)				((a)<(b)?(a):(b))
#define abS(x)					((x)<0?-(x):(x))
typedef long long ll;
typedef unsigned long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<ll> vl;
typedef vector<PII> VII;
typedef vector<TRI> VT;

/*Main code begins now*/
int n,m;
int adj[8][8];
string zip[8];
int vis[8],perm[8];
void precompute(){

}
int go(int v,int idx){
    vis[v]=1;
    if(idx==n)return -1;
    int nxt=perm[idx];
    if(vis[nxt])return idx;
    while(1){
        if(idx==n||idx==-1)return -1;
        nxt=perm[idx];
        if(adj[v][nxt]){
            int r=go(nxt,idx+1);
            idx=r;
        }else return idx;
    } 
}
void read(){
     s(n);
     s(m);
     memset(adj,0,sizeof(adj));
     for(int i=0;i<n;i++){
             cin>>zip[i];
     }
     //for(int i=0;i<n;i++) cout<<zip[i];
     for(int i=0;i<m;i++){
         int a,b;
         scanf("%d%d",&a,&b);
         --a,--b;
         adj[a][b]=1;
         adj[b][a]=1;
     }
}
int valid(){
    memset(vis,0,sizeof(vis));
    return go(perm[0],1);
}
void solve(){
     for(int i=0;i<n;i++)perm[i]=i;
     string ans="";
     do{
        if(valid()==-1){
            string cost="";
            for(int i=0;i<n;i++)cost+=zip[perm[i]];
            if(ans=="" || cost<ans)ans=cost;
        }
     }while(next_permutation(perm,perm+n));
     cout<<ans<<'\n';
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	precompute();
	int t;
	s(t);
	for(int T=1;T<=t;T++){
	    read();
	    printf("Case #%d: ",T);
        solve();
  	}
	return 0;
}




