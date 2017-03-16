#include <cstdio>
#define INFI 999999999
double ct[1000000],p[1000000];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t,cn=0;
	int now,len,i,j;
	double ans;
	scanf("%d",&t); 
	while(t--)
	{cn++;
		ans = INFI;
		scanf("%d%d",&now,&len);
		ct[0] = 1;
		for(i=1;i<=now;i++)
		{
			scanf("%lf",&p[i]);
			ct[i] = ct[i-1]*p[i];	
		}	
		for(j=0;j<=now;j++)
			ans <?= 2*j+len-now+1 + (1-ct[now-j])*(len+1);
		ans <?= len+2;
		printf("Case #%d: %.6f\n",cn,ans);
	}	
}
