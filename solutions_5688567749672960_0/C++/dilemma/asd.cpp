#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int a[20];
int d[10000010];
int use[10000010];
int queue[10000010];
int main(void)
{
	int i,j,u,p,q,n,pi,qi,sump,front,rear;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%d",&n);
		p=1;
		while(p<=n)
		{
			p*=10;
		}
		d[1]=1;
		front=rear=1;
		queue[1]=1;
		use[1]=qi;
		while(rear>=front)
		{
			u=q=queue[front];
			front++;
			j=0;
			while(q!=0)
			{
				j++;
				a[j]=q%10;
				q/=10;
			}
			i=1;
			while(a[i]==0)
			{
				i++;
			}
			sump=0;
			while(i<=j)
			{
				sump=10*sump+a[i];
				i++;
			}
			if(use[sump]!=qi)
			{
				use[sump]=qi;
				rear++;
				queue[rear]=sump;
				d[sump]=d[u]+1;
			}
			if((u+1<=p)&&(use[u+1]!=qi))
			{
				use[u+1]=qi;
				rear++;
				queue[rear]=u+1;
				d[u+1]=d[u]+1;
			}
			if(use[n]==qi)
			{
				break;
			}
		}
		printf("Case #%d: %d\n",qi,d[n]);
	}
	return 0;
}