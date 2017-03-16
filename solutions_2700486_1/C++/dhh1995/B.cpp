#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define rep(i,n) for (int i=0;i<n;i++)
int n,x,y,L,a[5005]; double f[5005][5005];
double work()
{
	scanf("%d%d%d",&n,&x,&y),L=(abs(x)+abs(y))/2,a[0]=1;
	for (int i=0;i<L && n>0;i++) a[i+1]=a[i]+4,n-=a[i];
	if (n<=0) return 0; if (n>=a[L]) return 1; if (!x) return 0;
	rep(i,n+5) rep(j,n+5) f[i][j]=0; f[0][0]=1;
	rep(i,n+5) rep(j,n+5){
		double p=f[i][j];
		if (i==L*2) f[i][j+1]+=p;
		else if (j==L*2) f[i+1][j]+=p;
		else f[i][j+1]+=p*.5,f[i+1][j]+=p*.5;
		}
	double ans=0; for (int i=y+1;i<=L*2 && i<=n;i++) ans+=f[i][n-i]; return ans;
}
int main()
{
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T,Case=0; scanf("%d",&T);
	while (T--) printf("Case #%d: %.9lf\n",++Case,work());
	return 0;
}
