
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<stack>
#include<string>
#include<cctype>
#include<list>
#include<set>
#include<deque>
#include<queue>
#include<bitset>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>
#include<cassert>
 
#define      pii               std::pair<int,int>
#define      mp(a,b)           std::make_pair(a,b)
#define      X                 first
#define      Y                 second
#define 	pb(x)       	   push_back(x)
typedef long long ll;

ll MOD = 1000000007;
 
using namespace std; 

ll gcd(ll a , ll b )
{
	if(a<b)return gcd(b,a);
	if(b==0)return a;
	else return gcd(b,a%b);
}

void solve()
{
	ll a , b ;
	scanf("%lld/%lld",&a,&b);
	ll h = gcd(a,b);
	a=a/h;
	b=b/h;
	if((b&(b-1)))
	{
		printf("impossible\n");
		return ;
	}
	int x = log2(a);

	a=1<<x;
	assert(b%a==0);
	assert((b&(b-1))==0);
	assert((a&(a-1))==0);
	b=b/a;
	//printf(" :%d %lld %lld:",x,a,b);
	printf("%lld\n",(ll)log2(b) );
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}