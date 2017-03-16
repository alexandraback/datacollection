#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define NINF -0x3f3f3f3f

using namespace std;

typedef pair<int,int> ii;

int f[1005];
int arr[15];
	
void solve ()
{
	int V;
	scanf("%d",&V);
	
	for (int i = 0; i < V; i += 1)
	{
		scanf("%d",&f[i]);
		--f[i];
		
		arr[i] = i;
	}
	
	int ans = 0;
	
	do
	{
		int prev = arr[0];
		for (int i = 0; i < V; ++i)
		{
			int cur = arr[i];
			int nxt = f[cur];
			
			if (nxt == arr[0])
			{
				ans = max(ans,i+1);
				break;
			}
			
			int lf = prev;
			int rh = arr[(i+1)%V];
			
			if (nxt != lf && nxt != rh)
				break;
				
			if (nxt == lf)
				ans = max(ans,i+1);
				
			prev = cur;
		}
	}
	while (next_permutation(arr,arr+V));
	
	printf("%d\n",ans);
}

int main (int argc, char const* argv[])
{
	int T;
	scanf("%d",&T);
	
	for (int t = 1; t <= T; ++t)
	{
		printf("Case #%d: ",t);
		solve();
	}
	
	return 0;
}
