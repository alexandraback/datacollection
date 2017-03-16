#include <iostream>
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,r;
	scanf("%d",&t);
	for(r=1;r<=t;r++) {
		double p[100020]={1};
		double ans[100020];
		int a,b,i;
		scanf("%d %d",&a,&b);
		for(i=1;i<=a;i++) {
			scanf("%lf",&p[i]);
			p[i]*=p[i-1];
		}
		ans[0]=b+2;
		double min=ans[0];
		for(i=1;i<=a+1;i++) ans[i]=2*(a-i+1)+p[i-1]*(b-a+1)+(1-p[i-1])*(2*b-a+2);
		for(i=1;i<=a+1;i++) {
			if(min>ans[i]) min=ans[i];
		}
		printf("Case #%d: %lf\n",r,min);
	}
    return 0;
}
