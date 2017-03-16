#include <stdio.h>
#include <string.h>
#define mn(a,b) a<b ? a:b
#define mx(a,b) a>b ? a:b
#define INF 1000000000

using namespace std;

char x[20],y[20];

int main()
{
	long long chkx,chky,tmpx,tmpy;
	int i,j,lenx,leny,t,ii;
	// freopen("../test.in","r",stdin);
	// freopen("../test.out","w",stdout);
	scanf("%d",&t);
	for(ii=1;ii<=t;ii++)
	{
		printf("Case #%d: ",ii);
		scanf(" %s %s",x,y);
		lenx = strlen(x);
		leny = strlen(y);
		chkx = 0,chky = 0;
		for(i=0;i<lenx;i++)
		{
			if(chkx == chky)
			{
				if(x[i] == '?' && y[i] == '?' && i+1 < lenx && x[i+1] != '?' && y[i+1] != '?')
				{
					// printf("%d\n",i);
					tmpx = x[i+1]-'0',tmpy = y[i+1]-'0';
					if(tmpx > tmpy)
					{
						if(tmpx-tmpy >5)
							x[i] = '0',y[i] = '1';
						else x[i] = y[i] = '0';
					}
					else
					{
						if(tmpy-tmpx >5)
							x[i] = '1',y[i] = '0';
						else x[i] = y[i] = '0';
					}
				}
				else if(x[i] == '?' && y[i] != '?' && i+1 < lenx && x[i+1] != '?' && y[i+1] != '?')
				{
					// printf("%d\n",i);
					tmpx = x[i+1]-'0',tmpy = y[i+1]-'0';
					if(tmpx > tmpy)
					{
						if(tmpx-tmpy >5)
						{
							if(y[i] > '0')
								x[i] = y[i]-1;
							else
								x[i] = y[i];
						}
						else
							x[i] = y[i];
					}
					else
					{
						if(tmpy-tmpx >5)
						{
							if(y[i] < '9')
								x[i] = y[i]+1;
							else
								x[i] = y[i];
						}
						else
							x[i] = y[i];
					}
				}
				else if(y[i] == '?' && x[i] != '?' && i+1 < lenx && x[i+1] != '?' && y[i+1] != '?')
				{
					// printf("%d\n",i);
					tmpx = x[i+1]-'0',tmpy = y[i+1]-'0';
					if(tmpx > tmpy)
					{
						if(tmpx-tmpy > 5)
						{
							if(x[i] < '9')
								y[i] = x[i]+1;
							else
								y[i] = x[i];
						}
						else
							y[i] = x[i];
					}
					else
					{
						if(tmpy-tmpx >5)
						{
							if(x[i] > '0')
								y[i] = x[i]-1;
							else
								y[i] = x[i];
						}
						else
							y[i] = x[i];
					}
				}
				else if(x[i] == '?' && y[i] == '?')
					x[i] = y[i] = '0';
				else if(x[i] == '?')
					x[i] = y[i];
				else if(y[i] == '?')
					y[i] = x[i];
			}
			if(chkx > chky)
			{
				if(x[i] == '?')
					x[i] = '0';
				if(y[i] == '?')
					y[i] = '9';
			}
			if(chkx < chky)
			{
				if(x[i] == '?')
					x[i] = '9';
				if(y[i] == '?')
					y[i] = '0';
			}
			chkx = chkx*10 + x[i] - '0';
			chky = chky*10 + y[i] - '0';
		}
		printf("%s %s\n",x,y);
	}
	return 0;
}