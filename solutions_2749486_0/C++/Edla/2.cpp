#include<cstdio>
using namespace std;
int main()
{
	int t,x,y,min,i,j,k,T;
	char s[1000];
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d%d",&x,&y);
		k=0;
		if(x<0)
		{
			for(i=0;i<-x;i++,k+=2)
			{
				s[k]='E';
				s[k+1]='W';
			}
		}
		else
		{
			for(i=0;i<x;i++,k+=2)
			{
				s[k]='W';
				s[k+1]='E';
			}
		}
		if(y<0)
		{
			for(j=0;j<-y;j++,k+=2)
			{
				s[k]='N';
				s[k+1]='S';
			}
		}
		else
		{
			for(j=0;j<y;j++,k+=2)
			{
				s[k]='S';
				s[k+1]='N';
			}
		}
		s[k]=0;
		printf("Case #%d: %s\n",t,s);
	}
	return 0;
}
