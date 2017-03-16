#include <stdio.h>
void solve(int);
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}
int check[20];
void func(int k)
{
	while(k)
	{
		check[k%10] = 1;
		k/=10;
	}
}
void solve(int T)
{
	int a,i,j;
	scanf("%d",&a);
	for(i=0;i<=9;i++) check[i] = 0;
	if(a==0)
	{
		printf("Case #%d: INSOMNIA\n",T);
		return;
	}
	else
	{
		for(i=1;;i++)
		{
			func(i*a);
			for(j=0;j<=9;j++) if(check[j]==0) break;
			if(j==10)
			{
				printf("Case #%d: %d\n",T,i*a);
				return;
			}
		}
	}
}
