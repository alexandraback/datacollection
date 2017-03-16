#include <stdio.h>
#include <string.h>
void solve(int);
int main()
{
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}
char x[110];
void solve(int T)
{
	int i,count=0,type=1,a;
	scanf("%s",x+1);
	a = strlen(x+1);
	for(i=a;i>=1;i--)
	{
		if(type == 1)
		{
			if(x[i]=='-')
			{
				type = 0;
				count++;
			}
		}
		else if(type == 0)
		{
			if(x[i]=='+')
			{
				type = 1;
				count++;
			}
		}
	}
	printf("Case #%d: %d\n",T,count);
}
