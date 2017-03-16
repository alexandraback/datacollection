#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define PB push_back
#define MP make_pair
#define X first
#define Y second
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mi ((l+r)>>1)
#define fk puts("fuck!")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int a[103];

int main()
{
	//freopen("in","r",stdin);///
	int cas;scanf("%d",&cas);
	for(int t=1;t<=cas;t++)
	{
		int C,D,V;scanf("%d%d%d",&C,&D,&V);
		for(int i=1;i<=D;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+D+1);
		ll sum=0; int ans=0;
		for(int i=1;i<=D && a[i]<=V;i++)
		{
			while(a[i]>sum+1 && sum<V)
			{
				ans++;
				sum+=1LL*(sum+1)*C;
			}
			sum+=1LL*a[i]*C;
		}
		while(sum<V)
		{
			ans++;
			sum+=1LL*(sum+1)*C;
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}