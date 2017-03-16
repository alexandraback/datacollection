#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
typedef long long LL;
LL a[20][5];
int main(void)
{
	int i,j,u,v,p,n,pi,qi,top,ans;
	LL s;
	freopen("C-small-1-attempt1.in","r",stdin);
	freopen("C-small-1-attempt1.out","w",stdout);
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%d",&n);
		top=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&u,&v,&p);
			for(j=1;j<=v;j++)
			{
				top++;
				a[top][0]=u;
				a[top][1]=p+j-1;
			}
		}
		if((top<2)||((top==2)&&(a[1][1]==a[2][1])))
		{
			printf("Case #%d: 0\n",qi);
		}
		else
		{
			if(a[1][1]>a[2][1])
			{
				p=a[1][0];
				a[1][0]=a[2][0];
				a[2][0]=p;
				p=a[1][1];
				a[1][1]=a[2][1];
				a[2][1]=p;
			}
			if(a[1][0]>=a[2][0])
			{
				s=360-(a[1][0]-a[2][0]);
			}
			else
			{
				s=360+a[2][0]-a[1][0];
			}
			if((a[2][1]-a[1][1])*a[2][0]+a[1][1]*s>360*(a[2][1]-a[1][1]))
			{
				ans=0;
			}
			else
			{
				ans=1;
			}
			printf("Case #%d: %d\n",qi,ans);
		}
	}
	return 0;
}