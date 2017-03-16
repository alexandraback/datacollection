#include <stdio.h>
#include <string.h>
#include <deque>
void solve(int);
int main()
{
	freopen("inputL.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}
char x[1010];
char y[4010];
std::deque<char> Dq;
void solve(int T)
{
	int start,end,a,i,j;
	scanf("%s",x+1);
	a = strlen(x+1);
	start = 1500;
	end = 1499;
	for(i=1;i<=a;i++)
	{
		for(j=start;j<=end;j++)
		{
			if(y[j]<x[i])
			{
				y[start-1] = x[i];
				start--;
				break;
			}
			else if(y[j]>x[i])
			{
				y[end+1] = x[i];
				end++;
				break;
			}
		}
		if(j==end+1)
		{
			y[start-1] = x[i];
			start--;
		}
	}
	printf("Case #%d: ",T);
	for(j=start;j<=end;j++) printf("%c",y[j]);
	printf("\n");
}
