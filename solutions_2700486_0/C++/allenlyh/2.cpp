#include <stdio.h>
#include <string.h>

const int maxn=30;
int n,fl,s;
int x,y;
long long c[maxn][maxn],ans,ans2;


void work()
{
	scanf("%d%d%d",&n,&x,&y);
	fl=1;s=1;
	while (n>=s)
	{
		n-=s;
		fl++;
		s=s+4;
	}
	if ((x+y)/2+1<fl) {printf("%lf\n",1.0);return;}
	if ((x+y)/2+1>fl) {printf("%lf\n",0.0);return;}
	int ma=(fl-1)*2;
	ans=0;ans2=0;
	for (int i=0;i<=ma && i<=n;i++)
	{
		if (n-i>ma) continue;
		if (n-i<y+1) continue;
		ans+=c[n][i];
	}
	for (int i=0;i<=ma && i<=n;i++)
	{
		if (n-i>ma) continue;
		ans2+=c[n][i];
	}
	double res=(double)ans/ans2;
	printf("%lf\n",res);
}

void init()
{
	c[0][0]=1;c[0][1]=0;
	for (int i=1;i<maxn;i++)
	{
		c[i][0]=c[i-1][0];
		for (int j=1;j<=i;j++)
		 c[i][j]=(c[i-1][j-1]+c[i-1][j]);
		c[i][i+1]=0;
	}
}


int main()
{
	freopen(".in","r",stdin);
	freopen("a.out","w",stdout);
	init();
	int T;
	scanf("%d",&T);
	for (int i=1;i<=T;i++) 
	{
		printf("Case #%d: ",i);
		work();
	}
	return 0;
}
