#include<cstdio>
#include<cstring>
const int N = 100005;
double p[N];
int main()
{
	freopen("A-small-attempt0 (1).in","r",stdin);
	freopen("out.out","w",stdout);
	int T,ca=1,m,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)scanf("%lf",p+i);
		double tp=1.0,r,temp;
		r=m+2;
		for(i=1;i<=n;i++)
		{
			tp*=p[i];
			temp=n-i+m-i+1.0+(1.0-tp)*(m+1);
			//printf("i:%d temp:%lf \n",i,temp);
			if(r>temp)r=temp;
		}
		printf("Case #%d: %.6lf\n",ca++,r);
	}
	return 0;
}