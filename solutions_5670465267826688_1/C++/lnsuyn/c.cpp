#include <stdio.h>

int ch[10][10];
char s[10100];
int a[10100];
int main(void)
{
	int t ,ii;
	int n ,i ,j ,i2;
	long long k ,iii;
	int all;
	int ans;
	int temp;
	int z;
	
	ch[0][0]=0; ch[0][1]=1; ch[0][2]=2; ch[0][3]=3;
	ch[1][0]=1; ch[1][1]=4; ch[1][2]=3; ch[1][3]=6;
	ch[2][0]=2; ch[2][1]=7; ch[2][2]=4; ch[2][3]=1;
	ch[3][0]=3; ch[3][1]=2; ch[3][2]=5; ch[3][3]=4;
	for (i=0 ; i<=3 ; i++)	
	{
		for (j=4 ; j<=7 ; j++)	
		{
			ch[i][j]=(ch[i][j-4]+4)%8;
		}
	}
	for (i=4 ; i<=7 ; i++)	
	{
		for (j=0 ; j<=7 ; j++)	
		{
			ch[i][j]=(ch[i-4][j]+4)%8;
		}
	}
	scanf("%d" ,&t);
	for (ii=1 ; ii<=t ; ii++)
	{
		scanf("%d %lld" ,&n ,&k);
		scanf("%s" ,s+1);
		all=0;
		for (i=1 ; i<=n ; i++)
		{
			a[i]=s[i]-'h';
			all=ch[all][a[i]];
		}
		temp=0;
		z=0;
		for (iii=1 , i2=1 ; iii<=k&&i2<=10 ; iii++ , i2++)
		{
			for (j=1 ; j<=n ; j++)
			{
				temp=ch[temp][a[j]];
				if (temp==1)
				{
					z=1;
					break;
				}	
			}
			if (z)
			{
				break;	
			}
		}
		if (iii>k||i2>10)
		{
			ans=0;	
		}
		else
		{
			temp=0;
			z=0;
			for (j++ ; j<=n ; j++)
			{
				temp=ch[temp][a[j]];
				if (temp==2)
				{
					z=1;
					break;
				}	
			}	
			if (!z)		
			{
				for (iii++ , i2=1 ; iii<=k&&i2<=10 ; iii++ , i2++)
				{
					for (j=1 ; j<=n ; j++)
					{
						temp=ch[temp][a[j]];
						if (temp==2)
						{
							z=1;
							break;
						}	
					}
					if (z)
					{
						break;	
					}
				}		
			}	
			if (iii>k||i2>10)
			{
				ans=0;	
			}
			else
			{	
				temp=0;
				z=0;
				for (j++ ; j<=n ; j++)
				{
					temp=ch[temp][a[j]];
					if (temp==3)
					{
						z=1;
						break;
					}	
				}	
				if (!z)		
				{
					for (iii++ , i2=1 ; iii<=k&&i2<=10 ; iii++ , i2++)
					{
						for (j=1 ; j<=n ; j++)
						{
							temp=ch[temp][a[j]];
							if (temp==3)
							{
								z=1;
								break;
							}	
						}
						if (z)
						{
							break;	
						}
					}		
				}	
				if (iii>k||i2>10)
				{
					ans=0;	
				}
				else
				{		
					temp=0;
					for (j++ ; j<=n ; j++)
					{
						temp=ch[temp][a[j]];	
					}					
					if (temp)
					{
						for (iii++ , i2=1 ; iii<=k&&i2<=10 ; iii++ , i2++)
						{
							for (j=1 ; j<=n ; j++)
							{
								temp=ch[temp][a[j]];
							}
							if (!temp)
							{
								break;	
							}
						}						
					}
					if (iii>k||i2>10)
					{
						ans=0;
					}
					else
					{
						k=k-iii;
						if (all==0)
						{
							ans=1;
						}
						else if (all==4)
						{
							if (k%2==0)
							{
								ans=1;
							}
							else
							{
								ans=0;	
							}
						}
						else
						{
							if (k%4==0)
							{
								ans=1;
							}
							else
							{
								ans=0;	
							}								
						}
					}
				}							
			}
		}
		if (ans)
		{
			printf("Case #%d: YES\n" ,ii);			
		}
		else
		{
			printf("Case #%d: NO\n" ,ii);
		}
	}
	
	return 0;
}
