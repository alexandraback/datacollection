#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define sz(c) (int)c.size()
#define ln(c) (int)c.length()
#define all(c) (c).begin(), (c).end()
#define tr(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

using namespace std;
typedef long long lld;
const int MAXN = 2000009;
typedef pair<int,int> pii;

int t, n;
int dp[MAXN];

int get_inverse(int x)
{
	int y = 0;
	
	while(x)
		y = (y*10) + (x%10), x/=10;
	
	return y;
}

int main ()
{	
	freopen("A-small.in", "r", stdin);
	freopen("A-small.out", "w", stdout);
	
	scanf("%d" ,&t);
	
	for (int tt=1; tt<=t; tt++)
	{
		scanf("%d" ,&n);
		
		for (int i=1; i<=n; i++)
			dp[i] = i;
			
		for (int i=1; i<=n; i++)
		{
			int x = get_inverse(i);
			
			dp[i] = min(dp[i-1]+1, dp[i]);
			//printf("%d " ,i);
			if (x<=n)
				dp[x] = min(dp[x], dp[i]+1);
		}
		
		printf("Case #%d: %d\n" ,tt ,dp[n]);
	}
}
