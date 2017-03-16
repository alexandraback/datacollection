#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
#define LL long long
#define P 1000000007
#define N 1005

int f[N],t,n,a[N],mx;

int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	
	scanf("%d",&t);
	rep(tcase,1,t){
		printf("Case #%d: ",tcase);
		scanf("%d",&n);
		mx=0;
		rep(i,1,n) scanf("%d",a+i),mx=max(mx,a[i]);
		int ans=mx;
		rep(i,1,mx){
			int cnt=0;
			rep(j,1,n) cnt+=(a[j]-1)/i;
			cnt+=i;
			ans=min(ans,cnt);
		}
		printf("%d\n",ans);
	}
}
