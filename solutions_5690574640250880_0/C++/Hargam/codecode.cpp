#include <stdio.h>
char MATR[50][50];

int minim(int a,int b)
{
	if (a<b) return a;
	return b;
}

int main()
{
	freopen("C-small-attempt2.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tests,tcount,r,c,i,j,m,e,m1,flag1;//r-������ c-������
	scanf("%d",&tests);
	for(tcount=0;tcount<tests;tcount++)
	{
		flag1=0;
		scanf("%d",&r);
		scanf("%d",&c);
		scanf("%d",&m);
		e=r*c-m;
		if(e==1)
			{
				printf("Case #%d:\n",tcount+1);
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						if(i==r-1&&j==c-1)
						{
							printf("c");
						}
						else
						{
							printf("*");
						}
					}
					printf("\n");
				}
				flag1=1;
			}
		else if(r==1||c==1)
		{
				if(r==1)
				{
					printf("Case #%d:\n",tcount+1);
					for(i=0;i<c;i++)
					{
						if(m>0)
						{
							printf("*");
							m--;
						}
						else if(i<c-1)
						{
							printf(".");
						}
						else
						{
							printf("c\n");
						}
					}
				}
				else if(c==1)
				{
					printf("Case #%d:\n",tcount+1);
					for(i=0;i<r;i++)
					{
						if(m>0)
						{
							printf("*\n");
							m--;
						}
						else if(i<r-1)
						{
							printf(".\n");
						}
						else
						{
							printf("c\n");
						}
					}
				}
		}
		else if(r==2)
		{
				if(m%2==1||e==2)
				{
					printf("Case #%d:\nImpossible\n",tcount+1);
				}
				else
				{
					printf("Case #%d:\n",tcount+1);
					m=m/2;
					m1=m;
					for(i=0;i<c;i++)
					{
						if(m>0)
						{
							printf("*");
							m--;
						}
						else if(i<c-1)
						{
							printf(".");
						}
						else
						{
							printf(".\n");
						}
					}
					for(i=0;i<c;i++)
					{
						if(m1>0)
						{
							printf("*");
							m1--;
						}
						else if(i<c-1)
						{
							printf(".");
						}
						else
						{
							printf("c\n");
						}
					}
				}
		}
		else if(c==2)
		{
				if(m%2==1||e==2)
				{
					printf("Case #%d:\nImpossible\n",tcount+1);
				}
				else
				{
					printf("Case #%d:\n",tcount+1);
					m=m/2;
					for(i=0;i<r;i++)
					{
						if(m>0)
						{
							printf("**\n");
							m--;
						}
						else if(i<r-1)
						{
							printf("..\n");
						}
						else
						{
							printf(".c\n");
						}
					}

				}
		}
		else
		{
			if(e<4||e==7||e==5)
			{
				printf("Case #%d:\nImpossible\n",tcount+1);
				flag1=1;
			}
			else if(e%2==0)
			{
				if(r%2==0)
				{
					for(i=0;i<r/2;i++)
					{
						for(j=0;j<c;j++)
						{
							if(j<2)
							{
								if(e>0)
								{
									MATR[2*i+j][0]='.';
									MATR[2*i+j][1]='.';
									e=e-2;
								}
								else
								{
									MATR[2*i+j][0]='*';
									MATR[2*i+j][1]='*';
								}
							}
							else
							{
								if(e>0)
								{
									MATR[2*i][j]='.';
									MATR[2*i+1][j]='.';
									e=e-2;
								}
								else
								{
									MATR[2*i][j]='*';
									MATR[2*i+1][j]='*';
									e=e-2;
								}
							}
						}
					}
				}
				else
				{
					for(i=0;i<(r-1)/2;i++)
					{
						for(j=0;j<c;j++)
						{
							if(j<2)
							{
								if(e>0)
								{
									MATR[2*i+j][0]='.';
									MATR[2*i+j][1]='.';
									e=e-2;
								}
								else
								{
									MATR[2*i+j][0]='*';
									MATR[2*i+j][1]='*';
								}
							}
							else
							{
								if(e>0)
								{
									MATR[2*i][j]='.';
									MATR[2*i+1][j]='.';
									e=e-2;
								}
								else
								{
									MATR[2*i][j]='*';
									MATR[2*i+1][j]='*';
									e=e-2;
								}
							}
						}
					}
					if(e==1)
					{
						MATR[r-2][c-1]='*';
						for(j=0;j<c;j++)
						{
							MATR[r-1][j]='*';
						}
						MATR[r-1][0]='.';
						MATR[r-1][1]='.';
					}
					else if(e>1)
					{
						for(j=0;j<c;j++)
						{
							if(e>0)
							{
								MATR[r-1][j]='.';
								e--;
							}
							else
							{
								MATR[r-1][j]='*';
							}
						}
					}
					else
					{
						for(j=0;j<c;j++)
						{
							MATR[r-1][j]='*';
						}
					}

				}
			}
			else
			{

				for(i=0;i<3;i++)
				{
					for(j=0;j<3;j++)
					{
						MATR[i][j]='.';
					}
				}
				e=e-9;
				for(j=3;j<c;j++)
				{
					if(e>0)
					{
						MATR[0][j]='.';
						MATR[1][j]='.';
						e=e-2;
					}
					else
					{

						MATR[0][j]='*';
						MATR[1][j]='*';
					}
				}

				for(i=3;i<r;i++)
				{
					if(e>0)
					{
						MATR[i][0]='.';
						MATR[i][1]='.';
						e=e-2;
					}
					else
					{
						MATR[i][0]='*';
						MATR[i][1]='*';
					}
				}
				for(j=5;j<c;j++)
				{
					for(i=0;i<minim(j+1,r);i++)
					{
						if(MATR[i][j-i]==0&&i<r&&(j-i)<c)
						{

							if(e>0)
							{
								MATR[i][j-i]='.';
								e--;
							}
							else
							{
								MATR[i][j-i]='*';
							}
						}
					}
				}
//				for(i=c;i<r;i++)
//				{
//					for(j=0;j<c;j++)
//					{
//						if(MATR[i+j][j]==0&&(i+j)<r&&j<c)
//						{
//							if(e>0)
//							{
//								MATR[i][j-i]='.';
//								e--;
//							}
//							else
//							{
//								MATR[i][j-i]='*';
//							}
//						}
//					}
//				}
				if(r>c)
				{
					for(i=r;i<r+c-1;i++)
					{
						for(j=i-r+1;j<c;j++)
						{
							if(MATR[i-j][j]==0&&(i-j)<r&&j<c)
							{

								if(e>0)
								{
									MATR[i-j][j]='.';
									e--;
								}
								else
								{
									MATR[i-j][j]='*';
								}
							}
						}
					}
				}
				else
				{
					for(i=c;i<r+c-1;i++)
					{
						for(j=i-c+1;j<r;j++)
						{
							if(MATR[j][i-j]==0&&(i-j)<c&&j<r)
							{
								if(e>0)
								{
									MATR[j][i-j]='.';
									e--;
								}
								else
								{
									MATR[j][i-j]='*';
								}
							}
						}
					}
				}

			}
			if(flag1==0)
			{
				printf("Case #%d:\n",tcount+1);
				MATR[0][0]='c';
				for(i=0;i<r;i++)
				{
					for(j=0;j<c;j++)
					{
						printf("%c",MATR[i][j]);
					}
					printf("\n");
				}
			}
			for(i=0;i<50;i++)
			{
				for(j=0;j<50;j++)
				{
					MATR[i][j]=0;
				}
			}
		}
	}
    return 0;
}
