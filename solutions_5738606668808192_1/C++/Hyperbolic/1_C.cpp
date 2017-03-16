#include <stdio.h>
void solve(int);
int main()
{
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++) solve(i);
}
int a,b,digit[110];
void func(int s, int t)
{
	if(b==0) return;
	if(s==a)
	{
		if(t==0)
		{
			for(int i=1;i<=a;i++) printf("%d",digit[i]);
			for(int i=2;i<=10;i++) printf(" %d",i+1);
			printf("\n");
			b--;
		}
		return;
	}
	digit[s] = 1;
	if(s%2==1) func(s+1,t+1);
	else func(s+1,t-1);
	digit[s] = 0;
	func(s+1,t);
}
void solve(int T)
{
	scanf("%d %d",&a,&b);
	digit[1] = 1, digit[a] = 1;
	printf("Case #%d:\n",T);
	func(2,0);
}
