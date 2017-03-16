/* Problem A
 * Round 1C 
 * CodeJam 2015
 * Google
 * Date : 10/05/2015
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<cstring>
using namespace std;

typedef long long ll;

void solve()
{
	ll r,c,w;
	scanf("%lld%lld%lld",&r,&c,&w);
	ll ans = 0;
		ans  = (ll)ceil((double)c/w);
	//	cout<<"ans :"<<ans<<endl;
		ans  *= r;
	//	cout<<"ans :"<<ans<<endl;
		ans += (w-1);
	printf(" %lld\n",ans );
}

int main(void)
{
	ll t;

	//freopen("input.txt","r",stdin);

	scanf("%lld",&t);
	for(ll i=1; i<=t ;i++)
	{
		printf("Case #%lld:",i);
		solve();
	}
	return 0;
}
/********************************* END OF PROGRAM **************************/
