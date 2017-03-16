#include <stdio.h>
void solve(int);
int main()
{
	//freopen("A-small-attempt1.in","r",stdin);
	freopen("A-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
char x[1010];
int y[1010];
void solve(int T)
{
	int a,i;
	int count=0,sum=0;
	scanf("%d %s",&a,x);
	for(i=0;i<=a;i++) y[i]=x[i]-'0';
	for(i=0;i<=a;i++)
	{
		if(y[i]==0) continue;
		if(count>=i);
		else
		{
			sum+=(i-count);
			count=i;
		}
		count+=y[i];
	}
	printf("Case #%d: %d\n",T,sum);
}
