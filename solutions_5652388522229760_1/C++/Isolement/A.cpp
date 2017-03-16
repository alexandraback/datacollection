#include<cstdio>
int n,ans,a,x,o,s=1023;
int main()
{
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	for(int casei=1;casei<=n;casei++)
	{
		scanf("%d",&o);x=0;ans=0;
		if(o==0)
		{
			printf("Case #%d: INSOMNIA\n",casei);
			continue;
		}
		while(s!=x)
		{
			ans+=o;a=ans;
			while(a!=0)
			{
				x|=1<<a%10;
				a/=10;
			}
		}
		printf("Case #%d: %d\n",casei,ans);
	}
}
