#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
#include<ctype.h>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<algorithm>
#include<set>

#define pb push_back
#define PI acos(-1.0)
#define SZ(a) (int)a.size()
#define csprnt printf("Case %d: ", cas++);
#define EPS 1e-9
#define MAX 100010
#define ll long long
#define INF (1<<30)
#define pii pair<int, int>
#define MP make_pair
int xx[] = {1,1,0,-1,-1,-1,0,1}, yy[] = {0,1,1,1,0,-1,-1,-1}; //eight direction

using namespace std;

ll bnum[105], btp[105], tnum[105], ttp[105], n, m;
ll dp[105][105];

ll rec(int a, int b)
{
	if(a==n || b==m) return 0;
	ll &ret = dp[a][b];
	if(ret!=-1) return ret;
	ret=0;
	ret = rec(a+1, b);
	ll i, j, now, add1=0, add2;
	for(i=a;i<n;i++)
	{
		if(btp[i]==btp[a]) add1+=bnum[i];
		add2=0;
		for(j=b;j<m;j++)
		{
			if(btp[a]==ttp[j]) add2+=tnum[j];
			ret = max(ret, rec(i+1, j+1)+min(add1, add2));
		}
	}
	return ret;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
    int t, cas=1;
    scanf("%d", &t);
    while(t--)
    {
    	ll i, j;
    	scanf("%lld%lld", &n, &m);
    	for(i=0;i<n;i++)
			scanf("%lld%lld", &bnum[i], &btp[i]);
		for(i=0;i<m;i++)
			scanf("%lld%lld", &tnum[i], &ttp[i]);
		memset(dp, -1, sizeof dp);
		ll ans = rec(0, 0);
		printf("Case #%d: %lld\n", cas++, ans);
    }
    return 0;
}


