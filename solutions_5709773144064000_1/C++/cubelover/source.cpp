#include<cstdio>

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		double res=0;
		int i;
		double c,f,x;
		scanf("%lf%lf%lf",&c,&f,&x);
		for(i=0;x/(2+f*i)>x/(2+f*(i+1))+c/(2+f*i);i++)res+=c/(2+f*i);
		printf("Case #%d: %.7lf\n",tc,res+x/(2+f*i));
	}
}