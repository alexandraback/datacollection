#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	int A,B,i,j;
	double p[100000],ans1,ans2,ans[100000],pr[100000],min;
	for(i=1;i<=T;i++)
	{
		scanf("%d%d",&A,&B);
		pr[0]=1.0;
		for(j=1;j<=A;j++) {scanf("%lf",p+j);pr[j]=pr[j-1]*p[j];}
		ans1=(B-A+1)*pr[A]+(2*B-A+2)*(1-pr[A]);
		ans2=B+2;
		for(j=1;j<=A;j++) ans[j]=(B-A+2*j+1)*(pr[A-j])+(2*B-A+2*j+2)*(1-pr[A-j]);
		/*
		printf("%lf %lf ",ans1,ans2);
		for(j=1;j<=A;j++) printf("%lf ",ans[j]);
		printf("\n");
		*/
		min=ans1;
		if(ans2<min) min=ans2;
		for(j=1;j<=A;j++) if(ans[j]<min) min=ans[j];
		printf("Case #%d: %.6lf\n",i,min);
	}
	return 0;
}
