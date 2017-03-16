#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
#define N 105
int T,Case,n,m,a[N][N],r[N],c[N];
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m); memset(r,0,sizeof(r)),memset(c,0,sizeof(c));
		rep(i,n) rep(j,m)
			scanf("%d",&a[i][j]),r[i]=max(r[i],a[i][j]),c[j]=max(c[j],a[i][j]);
		int flag=1;
		rep(i,n) rep(j,m) if (a[i][j]<r[i] && a[i][j]<c[j]) flag=0;
		printf("Case #%d: ",++Case); puts(flag?"YES":"NO");
		}
	return 0;
}
