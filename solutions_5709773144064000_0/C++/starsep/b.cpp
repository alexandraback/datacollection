#include <cstdio>
void solve()
{
	long double w=1e18,c,x,f,rat=2.0,t=0.0;
	scanf("%Lf%Lf%Lf",&c,&f,&x);
	//printf("%Lf %Lf %Lf\n",c,f,x);
	while(true)//for(int i=0;i<100;i++)
	{
		long double z=t+x/rat;
		if(z<w)w=z;
		else break;
		//printf("%Lf %Lf %Lf %Lf\n",t,z,w,c/rat);
		t+=c/rat;
		rat+=f;
	}
	printf("%.7Lf\n",w);
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}