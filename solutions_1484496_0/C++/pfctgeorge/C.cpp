#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[205];
int x[25],y[25];
int sum[205];
int n;
bool flag;
bool dfs(int depth,int xx,int yy,int cx,int cy)
{
	if (xx==yy && cx>0 && cy>0)
	{
		flag=true;
		printf("%d",x[0]);
		for (int i=1;i<cx;i++) printf(" %d",x[i]);
		puts("");
		printf("%d",y[0]);
		for (int i=1;i<cy;i++) printf(" %d",y[i]);
		puts("");
	}
	if (flag) return true;
	if (depth==n+1) return false;
	if (x>y && x-y>sum[depth]) return false;
	if (x<y && y-x>sum[depth]) return false;
	x[cx]=a[depth];
	if (dfs(depth+1,xx+a[depth],yy,cx+1,cy)) return true;
	y[cy]=a[depth];
	if (dfs(depth+1,xx,yy+a[depth],cx,cy+1)) return true;
	if (dfs(depth+1,xx,yy,cx,cy)) return true;
	return false;

}
int main()
{
	freopen("C-s.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++)
	{
		flag=false;
		printf("Case #%d:\n",cas);
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sum[n]=a[n];
		for (int i=n-1;i>=1;i--) sum[i]=sum[i+1]+a[i];
		dfs(1,0,0,0,0);
	}
}
