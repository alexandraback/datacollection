#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#ifdef WIN32
	#define LLD "%I64d"
#else
	#define LLD "%lld"
#endif

const int maxn=505;
const int maxx=1<<20;

ll a[maxn];
pair <ll,ll> sums[maxx];

int main()
{
	int NT=0;
	scanf("%d",&NT);
	for (int T=1;T<=NT;T++)
	{
		int n;
		ll ans1=0;
		ll ans2=0;
		scanf("%d",&n);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		ll nm=1<<n;
// 		assert(nm==maxx);
		for (ll mask=1;mask<nm;mask++)
		{
			ll sum=0;
			for (int i=0;i<n;i++) if (mask&(1<<i)) sum+=a[i];
			sums[mask-1].first=sum;
			sums[mask-1].second=mask;
		}
// 		cout << ans1 << endl;
		sort(sums,sums+nm);
		for (ll i=1;i<nm;i++)
		{
			if (sums[i].first==sums[i-1].first)
			{
				ll mask1=sums[i].second;
				ll mask2=sums[i-1].second;
				ll t=mask1&mask2;
// 				for (int j=0;j<n;j++) if (mask1&(1<<j)) printf("%d ",a[j]);
// 				printf("\n");
// 				for (int j=0;j<n;j++) if (mask2&(1<<j)) printf("%d ",a[j]);
// 				printf("\n");
// 				cout << sums[i].first << ' ' << sums[i-1].first << endl;
// 				cout << mask1 << ' ' << mask2 << ' ' << t << endl;
				ans1=mask1^t;
				ans2=mask2^t;
				break;
			}
		}
		printf("Case #%d:\n",T);
		if (ans1==0) printf("Impossible\n");
		else
		{
// 			cout << ans1 << ' ' << ans2 << endl;
			for (int i=0;i<n;i++) if (ans1&(1<<i)) printf("%d ",a[i]);
			printf("\n");
			for (int i=0;i<n;i++) if (ans2&(1<<i)) printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}