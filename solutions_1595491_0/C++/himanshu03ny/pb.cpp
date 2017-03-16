#include<cstdio>
int main()
{
	int t,x,n,s,p,c,i,g=1;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d", &n,&s,&p);
		c=0;
		for(i=0;i<n;i++)
		{
			scanf("%d", &x);
			if(x%3==1)
			{
				
				if( (x/3+1>=p) || (x/3>=p) )c++;
			}
			if(x%3==0)
			{
				if(x/3+1==p && x)
				{
					if(s)
					{
						s--;
						c++;
					}
				}
				if(x/3>=p)
					c++;
			}
			if(x%3==2)
			{
				if(x/3+2==p)
				{
					if(s)
					{
						s--;
						c++;
					}
				}
				if(x/3+1>=p)c++;
			}
		}
		printf("Case #%d: %d\n",g++, c);
	}
	return 0;
}
