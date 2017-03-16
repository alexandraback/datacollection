#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
void doit()
{
	ll r, t, left, right, ans=0;
	cin>>r>>t;

	for(left=0, right=5000000000ll; left<=right;)
	{
		ll mid = (left + right) >> 1;
		ll tmp = t/(( (r + mid) << 1 ) - 1);
		if(tmp >= mid)
		{
			ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	printf("%lld\n",ans);
}
int main(int argc, char const *argv[])
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++)
		printf("Case #%d: ", i), doit();
	return 0;
}
