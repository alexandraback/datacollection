 //if you want,you can

#include<stdio.h>


int main()
{
	freopen("b.out","w",stdout);
	int t;
	scanf("%d",&t);
	int n,s,p;
	for(int i=0;i<t;i++)
	{
		scanf("%d %d %d",&n,&s,&p);
		int count=0;
		int a=3*p-2;
		int b=3*p-4;
		for(int j=0;j<n;j++)
		{
			int temp;
			scanf("%d",&temp);
			if(temp>=a)
			{
				count++;
			}
			else if(temp>=b && s && p-2>=0)
			{
				s--;
				count++;
			}
		}
		printf("Case #%d: ",i+1);
		printf("%d\n",count);
	}
}
