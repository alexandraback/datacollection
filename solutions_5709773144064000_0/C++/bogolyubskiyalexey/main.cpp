

#include<iostream>
using namespace std;


void solve(int test)
{
	double C,F,X;
	scanf("%lf%lf%lf",&C,&F,&X);
	double cnt=0,v=2.0,need;
	double time=0;
	double answer=X/v;
	int count=0;
	while(time<answer)
	{
		need=X-cnt;
		answer=min(answer,time+need/v);
		if(cnt<C)
		{
			need=C-cnt;
			time+=need/v;
			cnt=C;
		}
		cnt-=C;
		v+=F;
		count++;
	}
	printf("Case #%d: %.7lf\n",test,answer);
}



int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tests;
	scanf("%d",&Tests);
	for(int i=1;i<=Tests;i++) solve(i);
	return 0;
}