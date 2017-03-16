#include <stdio.h>

int main(void)
{
	int t ,ii;
	int x ,r ,c ,temp;
	int ans;
	
	scanf("%d" ,&t);
	for (ii=1 ; ii<=t ; ii++)
	{
		scanf("%d %d %d" ,&x ,&r ,&c);
		if ((r*c)%x)
		{
			ans=0;
		}
		else
		{
			if (c>r)
			{
				temp=c;
				c=r;
				r=temp;	
			}
			if (x==1)
			{
				ans=1;
			}
			else if (x==2)
			{
				ans=1;
			}
			else if (x==3)
			{
				if (c==1)
				{
					ans=0;	
				}
				else
				{
					ans=1;
				}
			}
			else if (x==4)
			{
				if (c==1||c==2)
				{
					ans=0;	
				}
				else
				{
					ans=1;
				}				
			}
			else if (x==5)
			{
				if (c==1||c==2)
				{
					ans=0;	
				}
				else if (c==3)
				{
					if (r==5)	
					{
						ans=0;	
					}
					else
					{
						ans=1;
					}
				}
				else
				{
					ans=1;
				}						
			}
			else if (x==6)
			{
				if (c==1||c==2||c==3)
				{
					ans=0;	
				}
				else
				{
					ans=1;
				}				
			}
			else
			{
				ans=0;	
			}			
		}
		if (ans)
		{
			printf("Case #%d: GABRIEL\n" ,ii);			
		}
		else
		{
			printf("Case #%d: RICHARD\n" ,ii);	
		}
	}
	
	return 0;
}
