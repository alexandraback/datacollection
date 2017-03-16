#include <stdio.h>
void solve(int);
int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	freopen("B-large.in","r",stdin);
	freopen("outputB.out","w",stdout);
	int i,a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) solve(i);
}
int x[1010];
void solve(int T)
{
	int a,i,j,sum,ans=1234567;
	scanf("%d",&a);
	for(i=1;i<=a;i++) scanf("%d",&x[i]);
	for(j=1;j<=1000;j++)
	{
		//j초안에 음식을 다먹는다 가정
		sum=0;
		for(i=1;i<=a;i++)
		{
			sum+=(x[i]-1)/j;
		}
		sum+=j;
		ans=ans<sum?ans:sum;
	}
	printf("Case #%d: %d\n",T,ans);
}
