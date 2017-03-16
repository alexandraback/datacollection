#include<cstdio>
#include<iostream>
using namespace std;
int mx[5000];
double comp(int l,int diff,int x,int y)
{
	double ans;
	//printf("%d %d ",diff,y);
	int i,j,p2=1;
	for(i=0;i<=y;i++)
		p2*=2;
	while(y<diff)
	{
		ans=ans+1.0/p2;
		p2*=2;
		y++;
	}
	return ans;
}
int main()
{
	int t,T,i,j,x,y,n,inc,h;
	double ans;
	cin>>T;
	mx[0]=0;
	mx[1]=1;
	inc=5;
	for(i=2;i<=5000;i++)
	{
		mx[i]=mx[i-1]+inc;
		inc=inc+4;
	}
	for(t=1;t<=T;t++)
	{
		cin>>n>>x>>y;
		if(x<0)
			x=-x;
		int l=(x+y)/2+1;
		//cout<<"l="<<l<<endl;
		if(l>=5000)
			ans=0;
		else if(n>=mx[l])
			ans=1;
		else if(n<=mx[l-1])
			ans=0;
		else
		{
			int k=mx[l]-mx[l-1];
			int diff=n-mx[l-1];
			//printf("diff = %d",diff);
			if(y>=diff)
				ans=0;
			else if(x==0)
				ans=0;
			else if(diff<=2*l-2)
			{
				ans=comp(l,diff,x,y);
				//printf("case1 ");
			}
			else
			{
				//printf("case2 ");
				int extra=diff-2*(l-1);
				if(y<diff-2*(l-1))
					ans=1;
				else
					ans=comp(l,diff-2*(diff-2*(l-1)),x,y-extra+1);
			}
		}
		printf("Case #%d: %lf\n",t,ans);
	}
	return 0;
}
