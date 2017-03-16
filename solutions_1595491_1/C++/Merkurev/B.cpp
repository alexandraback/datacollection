#include <iostream>
using namespace std;


void main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int ntest=1;
	int t;
	scanf("%d",&t);
	for (int i=0;i<t;i++)
	{
		int n,s,p;
		int ans=0;
		scanf("%d%d%d",&n,&s,&p);
		for (int j=0;j<n;j++)
		{
			int x;
			scanf("%d",&x);
			if (p+2*max(p-1,0)<=x)
			{
				ans++;
			}
			else if (s>0 && p+2*max(p-2,0)<=x)
			{
				s--;
				ans++;
			}
		}
		printf("Case #%d: %d\n",ntest++,ans);
	}
}