#include <stdio.h>

char anss[60][60];
int main(void)
{
	int t ,i ,j1 ,j2;
	int r ,c ,m ,rc ,r2;
	int ans;
	
	scanf("%d" ,&t);
	for (i=1 ; i<=t ; i++)
	{
		scanf("%d %d %d" ,&r ,&c ,&m);
		rc=r*c;
		ans=1;
		if (m==rc-1)
		{
			for (j1=1 ; j1<=r ; j1++)
			{
				for (j2=1 ; j2<=c ; j2++)
				{
					anss[j1][j2]='*';
				}
			}			
			anss[1][1]='c';
		}
		else
		{
			if (r==1)
			{
				for (j2=1 ; j2<=m ; j2++)
				{
					anss[1][j2]='*';
				}		
				for (j2=j2 ; j2<c ; j2++)
				{
					anss[1][j2]='.';						
				}
				anss[1][c]='c';				
			}
			else if (c==1)
			{
				for (j1=1 ; j1<=m ; j1++)
				{
					anss[j1][1]='*';
				}		
				for (j1=j1 ; j1<r ; j1++)
				{
					anss[j1][1]='.';						
				}
				anss[r][1]='c';				
			}
			else
			{	
				if (m<=rc-4)
				{
					m=rc-m;
					if (r==2)
					{
						if (m%2)
						{
							ans=0;	
						}
						else
						{
							m/=2;
							for (j2=1 ; j2<=m ; j2++)
							{
								anss[1][j2]='.';									
								anss[2][j2]='.';
							}
							for (j2=j2 ; j2<=c ; j2++)
							{
								anss[1][j2]='*';									
								anss[2][j2]='*';								
							}
							anss[1][1]='c';							
						}
					}
					else if (c==2)
					{
						if (m%2)
						{
							ans=0;	
						}
						else
						{
							m/=2;
							for (j1=1 ; j1<=m ; j1++)
							{
								anss[j1][1]='.';									
								anss[j1][2]='.';
							}
							for (j1=j1 ; j1<=r ; j1++)
							{
								anss[j1][1]='*';									
								anss[j1][2]='*';								
							}
							anss[1][1]='c';								
						}						
					}
					else
					{
						if (m<=c*2||m==5||m==7)
						{
							if (m%2)
							{
								if (m==5||m==7)
								{
									ans=0;
								}
								else
								{
									for (j1=1 ; j1<=r ; j1++)
									{
										for (j2=1 ; j2<=c ; j2++)
										{
											anss[j1][j2]='*';
										}
									}								
									m=(m-3)/2;
									for (j2=1 ; j2<=m ; j2++)
									{
										anss[1][j2]='.';									
										anss[2][j2]='.';
									}
									anss[3][1]='.';									
									anss[3][2]='.';									
									anss[3][3]='.';									
									anss[1][1]='c';										
								}
							}
							else
							{
								for (j1=1 ; j1<=r ; j1++)
								{
									for (j2=1 ; j2<=c ; j2++)
									{
										anss[j1][j2]='*';
									}
								}								
								m/=2;
								for (j2=1 ; j2<=m ; j2++)
								{
									anss[1][j2]='.';									
									anss[2][j2]='.';
								}
								anss[1][1]='c';									
							}
						}
						else
						{								
							for (j2=1 ; j2<=c ; j2++)
							{
								anss[1][j2]='.';									
								anss[2][j2]='.';								
							}
							m-=c*2;
							if (m==1)
							{
								for (j1=3 ; j1<=r ; j1++)
								{
									for (j2=1 ; j2<=c ; j2++)
									{
										anss[j1][j2]='*';	
									}	
								}	
								anss[3][1]='.';
								anss[3][2]='.';
								anss[3][3]='.';
								anss[1][c]='*';
								anss[2][c]='*';
							}
							else if (m%c==1)
							{
								rc=m/c+2;
								for (j1=3 ; j1<=r ; j1++)
								{
									for (j2=1 ; j2<=c ; j2++)
									{
										if (m>0)
										{
											anss[j1][j2]='.';
										}
										else
										{
											anss[j1][j2]='*';	
										}
										m--;
									}	
								}		
								anss[rc][c]='*';
								anss[rc+1][2]='.';
							}
							else
							{
								for (j1=3 ; j1<=r ; j1++)
								{
									for (j2=1 ; j2<=c ; j2++)
									{
										if (m>0)
										{
											anss[j1][j2]='.';
										}
										else
										{
											anss[j1][j2]='*';	
										}
										m--;
									}	
								}
							}
							anss[1][1]='c';								
						}
					}
				}
				else
				{
					ans=0;
				}
			}
		}
		printf("Case #%d:\n" ,i);
		if (ans)
		{
			for (j1=1 ; j1<=r ; j1++)
			{
				for (j2=1 ; j2<=c ; j2++)
				{
					printf("%c" ,anss[j1][j2]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Impossible\n");
		}		
	}
	
	return 0;
}
