#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<map>
using namespace std;
#define s second
#define f first
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int,int>
#define VI vector<int>
int a,b,c,d,e,z,n,x,y,dlu;
main()
{
scanf("%d",&z);
for(int uu=1;uu<=z;uu++)
	{
	printf("Case #%d: ",uu);
	scanf("%d%d",&y,&x);
	dlu=1;
	while(x!=0)
		{
		if(x>0)
			{
			/*if(x>=dlu)
				{
				x-=dlu;
				dlu++;
				printf("S");
				continue;
				}			
			*/
			x+=dlu;
			printf("S");
			dlu++;
			x-=dlu;
			printf("N");
			dlu++;
			}
		if(x<0)
			{
			/*if(-x>=dlu)
				{
				x+=dlu;
				dlu++;
				printf("N");
				continue;
				}
			*/
			x-=dlu;
			printf("N");
			dlu++;
			x+=dlu;
			printf("S");
			dlu++;
			}
		}
	while(y!=0)
		{
		
		if(y>0)
			{
			/*if(y>=dlu)
				{
				y-=dlu;
				dlu++;
				printf("W");
				continue;
				}
			*/
			y+=dlu;
			printf("W");
			dlu++;
			y-=dlu;
			printf("E");
			dlu++;
			}

		if(y<0)
			{
			/*if(-y>=dlu)
				{
				y+=dlu;
				dlu++;
				printf("E");
				continue;
				}
			*/
			y-=dlu;
			printf("E");
			dlu++;
			y+=dlu;
			printf("W");
			dlu++;
			}
		}
	putchar(10);
	
	}
}
