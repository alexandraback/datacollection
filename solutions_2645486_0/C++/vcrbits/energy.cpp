#include<cstdio>
int ans;
int v[20];
void recur(int x,int n,int e,int r,int cur,int sum)
{
	int i;
	if (x==n+1)
	{
		if (ans < sum)
			ans = sum;
		return;
	}
	for (i=0;i<=cur;i++)
	{
		if (cur-i+r >= e)
			recur(x+1,n,e,r,e,sum+v[x]*i);
		else
			recur(x+1,n,e,r,cur-i+r,sum+v[x]*i);
	}
	return;
}
int main()
{
	int t,ca=0,n,e,r,i;
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		ans = 0;
		scanf("%d%d%d",&e,&r,&n);
		for (i=1;i<=n;i++)
			scanf("%d",&v[i]);
		recur(1,n,e,r,e,0);
		printf("Case #%d: %d\n",ca,ans);
	}
	return 0;
}

