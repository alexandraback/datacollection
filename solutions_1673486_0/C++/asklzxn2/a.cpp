#include<cstdio>
int T,Case,i,A,B;
double Ans,tmp,x;
double f[100005];
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);
	for(Case=1;Case<=T;++Case)
	{
		scanf("%d%d",&A,&B);
		f[0]=1;
		for(i=1;i<=A;++i)
		{
			scanf("%lf",&x);
			f[i]=f[i-1]*x;
		}
		Ans=B+2;
		for(i=A;i;--i)
		{
			tmp=f[i]*((A-i)*2+(B-A)+1)+(1-f[i])*((A-i)*2+(B-A)+B+2);
			if(tmp<Ans) Ans=tmp;
		}
		printf("Case #%d: %.8lf\n",Case,Ans);
	}
	return 0;
}
