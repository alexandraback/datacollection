#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using std::min;
void putnc(int n,const char *c)
{
	while(n-->0) printf("%s",c);
	return;
}
int main()
{
	int T;scanf("%d",&T);
	for(int lT = 1;lT <= T;lT++)
	{		
		printf("Case #%d:\n",lT);
		int M, R, C, Space;
		scanf("%d %d %d",&R,&C,&M);
		Space = R*C - M;
//		printf("R = %d, C = %d, Space = %d\n",R,C,Space);
		if(min(R,C) == 1)
		{
			// Cases for R or C = 1
			if(R == 1)
			{
				printf("c"); putnc(R*C - M - 1,"."); putnc(M,"*"); printf("\n");
				continue;
			}
			else if(C == 1)
			{
				printf("c\n");
				putnc(R*C - M - 1,".\n");
				putnc(M,"*\n");
				continue;
			}
		}
		else if(Space == 1)
		{
			for(int lx = 1;lx <= R;lx++)
			{
				for(int ly = 1;ly <= C;ly++)
				{
					if(lx + ly == 2) printf("c");
					else printf("*");
				}
				printf("\n");
			}
			continue;
		}
		else if(Space == 2)
		{
			printf("Impossible\n");
			continue;
		}
		else if(min(R,C) == 2)
		{
			if(Space%2 == 0)
			{
				// c...**** 
				// ....****
				if(R == 2)
				{
					printf("c");
					putnc(Space/2 - 1,".");
					putnc(C - Space/2,"*");
					printf("\n");
					putnc(Space/2,".");
					putnc(C - Space/2,"*");
					printf("\n");
					continue;
				}
				else if(C == 2)
				{
					printf("c.\n");
					putnc(Space/2 - 1,"..\n");
					putnc(R - Space/2,"**\n");
					continue;
				}
			}
			else
			{
				printf("Impossible\n");
				continue;
			}
		}
		else
		{
			if(Space <= 8)
			{
				if(Space%2 == 1)
				{
					printf("Impossible\n");
					continue;
				}
				else
				{
					if(Space == 4)
					{
						printf("c."); putnc(C - 2,"*");	printf("\n");
						printf(".."); putnc(C - 2,"*");	printf("\n");
						for(int lx = 3;lx <= R;lx++)
						{
							putnc(C,"*");
							printf("\n");
						}
						continue;
					}
					else if(Space == 6)
					{
						printf("c.."); putnc(C - 3,"*"); printf("\n");
						printf("..."); putnc(C - 3,"*"); printf("\n");
						for(int lx = 3;lx <= R;lx++){
							putnc(C,"*"); printf("\n");
						}
						continue;
					}
					else if(Space == 8)
					{
						printf("c.."); putnc(C - 3,"*"); printf("\n");
						printf("..."); putnc(C - 3,"*"); printf("\n");
						printf("..");  putnc(C - 2,"*"); printf("\n");
						for(int lx = 4;lx <= R;lx++){
							putnc(C,"*"); printf("\n");
						}
						continue;
					}
				}
			}
			else
			{
				// Space >= 9 
				// R,C >=3
				if(Space <= 2*C)
				{
					if(Space%2 == 0)
					{
						printf("c");putnc(Space/2 - 1,".");putnc(C - Space/2,"*");printf("\n");
						putnc(Space/2,".");putnc(C - Space/2,"*");printf("\n");
						for(int lx = 3;lx <= R;lx++){
							putnc(C,"*"); printf("\n");
						}
						continue;
					}
					else
					{
						printf("c");putnc((Space-3)/2 - 1,".");putnc(C - (Space-3)/2,"*");printf("\n");
						putnc((Space-3)/2,".");putnc(C - (Space-3)/2,"*");printf("\n");
						printf("...");putnc(C - 3,"*");printf("\n");
						for(int lx = 4;lx <= R;lx++){
							putnc(C,"*"); printf("\n");
						}
						continue;
					}
				}
				else
				{
					if(Space%C != 1)
					{
						for(int lx = 1;lx <= R;lx++)
						{
							for(int ly = 1;ly <= C;ly++)
							{
								if(lx+ly == 2) printf("c");
								else if((lx-1)*C + ly <= Space) printf(".");
								else printf("*");
							}
							printf("\n");
						}
						continue;
					}
					else
					{
						int d = (Space/C == 2) ? 2 : 1;
						for(int lx = 1;lx <= R;lx++)
						{
							if(lx == 1) 
							{ 
								printf("c"); putnc(C - 1 - (Space/C == 2),".");putnc((Space/C == 2),"*") ;
							}
							else if(lx <= Space/C)
							{
								putnc(C - (Space/C - d < lx),"."); putnc((Space/C - d < lx),"*"); 
							}
							else if(lx == Space/C + 1) 
							{
								putnc(1 + d,".");putnc(C - 1 - d,"*");
							}
							else
								putnc(C,"*");
							printf("\n");
						}
						continue;
					}
				}
			}
		}
	}
	return 0;
}
