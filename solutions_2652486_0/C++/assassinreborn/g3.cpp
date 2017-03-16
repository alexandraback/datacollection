#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<map>
#define fill(a,v) memset(a,v,sizeof(a))
#define sn(n) scanf("%d",&n)
#define REP(i,a,b) for(i=a;i<b;i++)
#define MOD 747474747
#define MAX 10001
using namespace std;

int getc(int u)
{
int c;
if(u>=48)
	c=5;
else if(u>=32)
	c=4;
else if(u>=16)
	c=3;
else if(u>=0)
	c=2;
return c;
}
int getb(int u)
{
int b;
u=u%16;	
if(u>=12)
	b=5;
else if(u>=8)
	b=4;
else if(u>=4)
	b=3;
else if(u>=0)
	b=2;

return b;
}
int geta(int u)
{
int a;
u=u%4;
if(u>=3)
	a=5;
else if(u>=2)
	a=4;
else if(u>=1)
	a=3;
else if(u>=0)
	a=2;
return a;
}


int main()
{
int t,i,j,no,r,m,n,k,prod,a,b,c,x1,x2,x3,e,f,g;
sn(t);bool flag;bool config[64][126];
while(t--)
	{
	sn(r);sn(n);sn(m);sn(k);
	for(i=0;i<64;i++)
		for(j=0;j<126;j++)
			config[i][j]=false;
	printf("Case #1:\n");
			
		for(no=0;no<64;no++)
			{
			a=geta(no);
			b=getb(no);
			c=getc(no);
			for(x1=0;x1<2;x1++)
				{
				
				e= ((x1==1) ? 1 : a); 
				for(x2=0;x2<2;x2++)
					{
					f= ((x2==1) ? 1 : b); 
					for(x3=0;x3<2;x3++)
						{
						g= ((x3==1) ? 1 : c); 
						if(x1==1 && x2==1 && x3==1)
							config[no][0]=true;
						else
							{
							//if(no==25)
							//	printf("%d %d %d %d %d\n",e*f*g,a,b,c,getb(no));
							config[no][e*f*g]=true;
							}
						}
					}
				}
			config[no][1]=true;
			}

	for(i=0;i<r;i++)
		{
		flag=false;
		bool valid[64];
		fill(valid,true);
		for(j=0;j<k;j++)
			{
			sn(prod);
			for(no=0;no<64;no++)
				if(!config[no][prod])
					{
					valid[no]=false;
					//if(no==25)
					//	printf("%d\n",prod);
					}
			}
		for(j=0;j<64;j++)
			if(valid[j])
				{
				printf("%d%d%d\n",geta(j),getb(j),getc(j));
				flag=true;
				break;
				}
		if(!flag)
			{
			printf("221\n");
			}	
		}
	
	}

}
