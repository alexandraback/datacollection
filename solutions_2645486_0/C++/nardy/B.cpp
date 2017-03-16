#include <cstdio>
#include <cstring>
#include <algorithm>
#define rep(i,l,r) for(int i = l;i <= r;++ i)
#define Max(a,b) (a > b ? a : b)
#define Min(a,b) (a < b ? a : b)
using namespace std;
int e,r,n,f[50][50],v,T;

void solve()
{
    scanf("%d%d%d",&e,&r,&n);
	memset(f,-1,sizeof(f));
	f[0][e] = 0;
	rep(i,1,n){
	 scanf("%d",&v);
	 rep(j,0,e)
	 if(f[i - 1][j] >= 0){
		f[i][j] = Max(f[i][j],f[i - 1][j]);
		rep(k,0,j)
		   f[i][Min(j - k + r,e)] = Max(f[i][Min(j - k + r,e)],f[i - 1][j] + v * k);
	 }
	}
	int ans = 0;
	rep(i,0,e) ans = Max(ans,f[n][i]);
	printf("%d\n",ans);
}
int main()
{
	//freopen("in","r",stdin); freopen("out","w",stdout);
    scanf("%d",&T);
	rep(tm,1,T){
	   printf("Case #%d: ",tm);
	   solve();
	}
	return 0;
}
