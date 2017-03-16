#include <stdio.h>

const int mx=2010;

int n;
bool win[mx];
int a[mx],b[mx];

int main()
{
	int i;
	int t,ca=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		int ans=0,wins=0,stars=0;
		while(wins < n)
		{
			bool can = false;
			for(i=0;i<n;i++)
			{
				if( 0 > b[i] ) continue;
				if(stars >= b[i])
				{
					can = true;
					stars += a[i]>=0 ? 2 : 1;
					wins++;
					b[i] = -1;
					a[i] = -1;
					ans++;
				}
			}
			if(can) continue;
			int id=-1;
			for(i=0;i<n;i++)
			{
				if( 0 > a[i] || 0 > b[i]) continue;
				if(stars >= a[i])
				{
					if( -1 == id || b[i] > b[id])
						id = i;
				}
			}
			if(-1 == id)
				break;
			ans++;
			stars ++;
			a[id] = -1;
		}
		printf("Case #%d: ",++ca);
		if(wins<n) printf("Too Bad\n");
		else printf("%d\n",ans);
	}
	return 0;
}

