
#include <cstdio>


int cases;

 int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	scanf("%d",&cases);
	for(int i=0;i<cases;++i)
	{
		long long r,t;
		scanf("%I64d%I64d",&r,&t);
		long long ans=0;
		while((t-1)/2>=r)
		{
			++ans;
			t-=2*r+1;
			r+=2;
		}
		printf("Case #%d: %I64d\n",i+1,ans);
	}
}