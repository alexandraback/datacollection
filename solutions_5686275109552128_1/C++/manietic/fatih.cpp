#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int single[1100];



int main()
{
	
	//~ freopen("B-large.in","r",stdin);
	//~ freopen("c.out","w",stdout);
	
	
	single[0] = single[1] = 0;
	
	for(int i = 2; i <= 1005; i++) single[i] = single[i/2] + single[(i+1)/2] + 1;
	
	int T; scanf("%d",&T);
	
	for(int t = 1; t <= T; t++)
	{
		int D; scanf("%d",&D);
		
		int a[D+1];
		
		for(int i = 1; i <= D; i++) scanf("%d",&a[i]);
		
		int ans = 1e9;
		
		
		for(int i = 1; i <= 1000; i++)
		{
			int temp = i;
			
			for(int j = 1; j <= D; j++)
			temp += single[(a[j] - 1) / i + 1];
			
			ans = min(ans,temp);
		}
		
		printf("Case #%d: %d\n",t,ans);
		
	}
	
	return 0;
	
	
}
