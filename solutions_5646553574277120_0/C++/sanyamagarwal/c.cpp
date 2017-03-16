//includes
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

//typedefs
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

//defines-general
#define to(a) __typeof(a)
#define all(vec)  vec.begin(),vec.end()
#define fill(a,val)  memset(a,val,sizeof(a))

//defines-iteration
#define repi(i,a,b) for(__typeof(b) i = a;i<b;i++)
#define repii(i,a,b) for(__typeof(b) i = a;i<=b;i++)
#define repr(i,b,a) for(__typeof(b) i = b;i>a;i--)
#define repri(i,b,a) for(__typeof(b) i = b;i>=a;i--)
#define tr(vec,it)  for(__typeof(vec.begin())  it = vec.begin();it!=vec.end();++it)



//defines-pair
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

// my own
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld%lld",&a,&b)
#define slll(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define sllll(a,b,c,d) scanf("%lld%lld%lld%lld",&a,&b,&c,&d)

set<ll> convolute(set<ll> given, ll d)
{
	set<ll> ret;
	tr(given,it)
	{
		ret.insert(*it);
		ret.insert(*it+d);
	}
	return ret;
}


set<ll> compute_all(ll arr[], ll d)
{
	set<ll> k;
	k.insert(0);
	repi(i,0,d)
	{
		k = convolute(k, arr[i]);
	}
	return k;
}

int main()
{
	ll test;
	sl(test);
	repii(tt,1,test)
	{
		printf("Case #%lld: ", tt);
		ll c,d,v;
		cin>>c>>d>>v;
		ll arr[100];
		repi(i,0,d)
		{
			cin>>arr[i];
		}
		set<ll> xx = compute_all(arr,d);
		ll ans = 0;
		repi(i,1,v+1)
		{
			if(xx.count(i) == 0)
			{
				xx = convolute(xx, i);
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}