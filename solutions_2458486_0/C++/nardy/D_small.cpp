#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
using namespace std;
const int Mod = 1000000007;
map<int,int> hash;
int keys[450],hav[50][50],req[50],way[50],fac[50],k,n,T,x,cnt = 0;
bool v[50],use[403];
bool dfs(int cur,int sum)
{
	if(sum == n) return true;
    v[cur] = true;
	rep(i,1,hav[cur][0]) ++ keys[hav[cur][i]];
	int val = 0;
	rep(i,1,cnt) val = ((long long)val * 41 % Mod + keys[fac[i]]) % Mod;
	val = (val * 41 % Mod + cur) % Mod;
	if(hash[val] != 0){
	   v[cur] = false; rep(i,1,hav[cur][0]) -- keys[hav[cur][i]];
	   return false;
	}
	hash[val] = 1;
	rep(i,1,n)
	if(!v[i] && keys[req[i]]){
	   -- keys[req[i]]; way[sum + 1] = i; 
	   if(dfs(i,sum + 1)) return true;
       ++ keys[req[i]];
	}
	rep(i,1,hav[cur][0]) -- keys[hav[cur][i]];
	v[cur] = false;
	return false;
}
void solve()
{
	hash.clear(); cnt = 0;
    scanf("%d%d",&k,&n);
	memset(keys,0,sizeof(keys)); memset(v,0,sizeof(v));
	rep(i,1,k){
	   scanf("%d",&x); ++ keys[x];
	}
	rep(i,1,n){
	   scanf("%d%d",&req[i],&hav[i][0]); use[req[i]] = true;
	   rep(j,1,hav[i][0]) scanf("%d",&hav[i][j]);
	}
	rep(j,1,400) if(use[j]) fac[++ cnt] = j;
	if(dfs(0,0)) rep(i,1,n) printf("%d ",way[i]);
	else printf("IMPOSSIBLE");
	puts("");
}
int main()
{
	//freopen("input","r",stdin); freopen("output","w",stdout);
    scanf("%d",&T);
	rep(t,1,T){
	   printf("Case #%d: ",t);
	   solve();
	}
}
