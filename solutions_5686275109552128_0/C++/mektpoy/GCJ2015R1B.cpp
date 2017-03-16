#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
#include<vector>
using namespace std;
int T, n;
int a[1010];
int main()
{
  freopen("text.in","r",stdin);
  freopen("text.out","w",stdout);
  cin >> T;
	for (int t=1; t<=T; t++)
		{
			cin >> n;
			int ans = 0;
			for (int i=1; i<=n; i++)
				scanf ("%d\n", &a[i]), ans = max (ans, a[i]);
			for (int k=1; k<=ans; k++)
				{
					int now = k;
					for (int i=1; i<=n; i++)
						{
							now += a[i]/k+(a[i]%k>0)-1;
							if (now > ans) break;
						}
					if (now < ans) ans = now;
				}
			printf ("Case #%d: %d\n", t, ans);
		}
	return 0;
}

