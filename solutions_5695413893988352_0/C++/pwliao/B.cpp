#include <cstdio>
#include <cmath>
#include <cstring>
char c[20],j[20];
int len;
int main()
{
	int T;
	scanf("%d",&T);
	for(int cases=1;cases<=T;cases++)
	{
		scanf("%s%s",c,j);
		len=strlen(c);
		int i;
		for(i=0;i<len;i++)
		{
			if(c[i]!='?'&&j[i]!='?')
			{
				if(i==0) break;
				if(c[i-1]=='?'&&j[i-1]=='?')
				{
					if(10+c[i]-j[i]<abs(c[i]-j[i]))
						c[i-1]='1',j[i-1]='0';
					else if(10+j[i]-c[i]<abs(c[i]-j[i]))
						c[i-1]='0',j[i-1]='1';
				}
				else if(c[i-1]='?')
				{
					if(10+c[i]-j[i]<abs(c[i]-j[i]))
						c[i-1]=j[i-1]+1;
					else if(10+j[i]-c[i]<abs(c[i]-j[i]))
						c[i-1]='0',j[i-1]='1';
				}
			}
		}
		for(i=0;i<len;i++)
		{
			if(c[i]=='?'&&j[i]=='?')
				c[i]=j[i]='0';
			else if(c[i]=='?')
				c[i]=j[i];
			else if(j[i]=='?')
				j[i]=c[i];
			else if(c[i]!=j[i])
				break;
		}
		bool big=false;
		if(c[i]>j[i]) big=true;
		else big=false;
		for(;i<len;i++)
		{
			if(big)
			{
				if(c[i]=='?') c[i]='0';
				if(j[i]=='?') j[i]='9';
			}
			else
			{
				if(c[i]=='?') c[i]='9';
				if(j[i]=='?') j[i]='0';
			}
		}
		printf("Case #%d: %s %s\n", cases, c, j);
	}
}
