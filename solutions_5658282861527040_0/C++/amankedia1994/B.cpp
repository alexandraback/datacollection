#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>

using namespace std;

#define sd(x) scanf("%d",&x);
#define slld(x) scanf("%lld",&x);
#define LL long long
#define LD long double
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define Fill(a, b) memset(a, b, sizeof(a))
#define INF 2000000009

typedef pair<int,int> PII;
typedef vector<int> VI;

void solve()
{
	int a,b,k,ans=0;
	sd(a);sd(b);sd(k);
	for(int i=0;i<a;i++)
	{
		for(int j=0;j<b;j++)
		{
			if((i&j)<k)ans++;
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t=1;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		solve();
	}
}

