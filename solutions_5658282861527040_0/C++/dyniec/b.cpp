#include<cstdio>
int main()
{
	int t;
	scanf("%d",&t);
	for(int l=1;l<=t;l++)
	{
		int odp=0;
		int a,b,k;
		scanf("%d %d %d",&a,&b,&k);
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
			{
				if((i&j)<k)odp++;
			}
		printf("Case #%d: %d\n",l,odp);
	}
	return 0;
}
