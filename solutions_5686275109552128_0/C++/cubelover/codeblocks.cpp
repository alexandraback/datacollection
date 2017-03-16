#include<cstdio>
#include<algorithm>

int a[1111];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int i,j,n,min=987654321,tot;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=1;i<=1000;i++)
		{
			tot=0;
            for(j=0;j<n;j++)tot+=(a[j]+i-1)/i-1;
            min=std::min(min,i+tot);
		}
		printf("Case #%d: %d\n",tc,min);
	}
}
