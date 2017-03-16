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



int main()
{
	ll test;
	sl(test);
	repii(tt,1,test)
	{
		printf("Case #%lld: ", tt);
		ll p,q; char c;
		cin>>p>>c>>q;
		ll mult = 2;
		bool first = true;
		ll anc = -1;
		bool possible = true;
		repi(i,0,40)
		{
			if(p*mult>=q) 
			{
				if(first) 
				{
					anc = i+1;
					first = false;
				}
				possible = true;
				for(int j = 0;j<40;j++)
				{
					if(q >= 1e18) 
					{
						possible = false;
						break;
					}
					if(q % mult != 0) 
					{
						q *= 2;
						p *= 2;
					}
					else
					{
						break;
					}
				}
				if(!possible) break;
				p -= q/mult;
			}
			
			mult *= 2;
		}
		if(!possible || p != 0||anc == -1)
		{
			printf("impossible\n");
			continue;
		}
		else
		{
			printf("%lld\n",anc);
		}


	}
	return 0;
}