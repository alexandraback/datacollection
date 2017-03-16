#include <bits/stdc++.h>
using namespace std;


int p[1007];
 

int main()
{
	int T,j,d;
	
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	
	scanf("%d",&T);
	
	for(j=1;j<=T;j++)
	{
		priority_queue<int> q;
		
		scanf("%d",&d);
		for(int i=0;i<d;i++)
		{
			scanf("%d",&p[i]);
		}
		
		sort(p,p+d);
		int ans= p[d-1];
		
		for(int mx = 1;mx<ans;mx++)
		{
			int z=0;
			for(int i=0;i<d;i++)
			{
				z+=(p[i]+mx-1)/mx-1;
			}
			ans=min(ans,mx+z);
		}
		
				
		printf("Case #%d: %d\n",j,ans);
	}
	
	


	return 0;
}
