
#include <stdio.h>

const int maxn = 100010;
double p[maxn];
int A,B;

double min(double a,double b)
{
	return a<b?a:b;
}

void solve()
{
     double ans = 1 + B + 1;
	 int i;
	 double cor=1;
	 for(i=A-1;i>=0;i--)
	 {
          cor *= p[A-1-i];
		  double tmp = cor*(i + B-(A-i) + 1) + (1-cor) * (i + B-(A-i) + 1 + B + 1);
		  ans = min(tmp,ans);
	 }
	 printf("%.6lf\n",ans);
}

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A.txt","w",stdout);
	int ct,caset = 1;
	scanf("%d",&ct);
	while(ct--)
	{
		printf("Case #%d: ",caset++);
        scanf("%d%d",&A,&B);
		int i;
		for(i=0;i<A;i++) scanf("%lf",&p[i]);
		solve();
	}
	return 0;
}