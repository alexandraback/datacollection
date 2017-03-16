#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int tt,tc;
    scanf("%d",&tt);
    for (tc=1;tc<=tt;tc++)
	{
		int d,p[1000];
		scanf("%d",&d);
		for (int i=0;i<d;i++)
			scanf("%d",&p[i]);
		int be=1,ed=1000;
		while (be<=ed)
		{
			int mid=(be+ed)/2;
			//printf("%d %d %d\n",be,mid,ed);
			int minn=2000000;
			for (int i=1;i<=mid;i++)
			{
				int cnt=0;
				for (int j=0;j<d;j++)
				{
					cnt+=(p[j]-1)/i;
				}
				if (cnt+i<minn)
					minn=cnt+i;
			}
			if (minn<=mid)
				ed=mid-1;
			else
				be=mid+1;

		}


		printf("Case #%d: %d\n",tc,be);
	}
    return 0;
}
