#include<stdio.h>
int main()
{
	int a,b;
	int n[500],x,y,x1,y1,p,q;
	char arr[500];
	scanf("%d",&a);
	for(b=1;b<=a;b++)
	{
		p=1;
		q=0;
		x1=0;y1=0;
		scanf("%d %d",&x,&y);
		while(1)
		{
			if(q==500)
			{
				q=0;
				p=1;
				x1=0;
				y1=0;
			}
			n[b] = rand(100000)%4;
			if(n[b]==0)
			{
				y1+=p;
				arr[q] = 'N';
				arr[q+1] = '\0';
			}
			if(n[b]==1)
			{
				y1-=p;
				arr[q] = 'S';
				arr[q+1] = '\0';
			}
			if(n[b]==2)
			{
				x1+=p;
				arr[q] = 'E';
				arr[q+1] = '\0';
			}
			if(n[b]==3)
			{
				x1-=p;
				arr[q] = 'W';
				arr[q+1] = '\0';
			}
			if(x1==x && y1==y)
			{
				printf("Case #%d: %s\n",b,arr);
				break;
			}
			q++;
			p++;
		}
	}
	return 0;
}
