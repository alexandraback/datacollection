#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#define rep(i,j,k) for(int i=(int)j;i<=(int)k;i++)
#define per(i,j,k) for(int i=(int)j;i>=(int)k;i--)
using namespace std;
typedef long long LL;
typedef double db;
const int N=1005;
int a[N];int n;
int b[N];
bool vis[N];
int dfs(int x){
	int ret=0;
	rep(i,1,n)if(a[i]==x)ret=max(ret,dfs(i));
	return ret+1;
}
void Main(int Cas){
	scanf("%d",&n);rep(i,1,n)scanf("%d",&a[i]);
	int ans=0;
	rep(i,1,n){
		int x=i;
		memset(vis,0,sizeof vis);
		vis[x]=1;
		int m=0;
		b[m=1]=x;
		while(1){
			x=a[x];
			if(vis[x]){
				if(x==b[1]){
					if(m>ans)ans=m;
				}
				break;
			}
			vis[x]=1;
			b[++m]=x;
		}
	}
	int DD=0;
	rep(i,1,n)if(a[a[i]]==i)if(a[i]>i){
		int r1=0;
		int r2=0;
		rep(j,1,n)if(a[j]==i&&j!=a[i])r1=max(r1,dfs(j));
		rep(j,1,n)if(a[j]==a[i]&&j!=i)r2=max(r2,dfs(j));
		DD+=2+r1+r2;
	}
	if(DD>ans)ans=DD;
	printf("Case #%d: %d\n",Cas,ans);
}
int main(){
	int T;scanf("%d",&T);
	rep(Cas,1,T)Main(Cas);
	return 0;
}


