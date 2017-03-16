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
#include <iomanip>   
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


ll overlap(string str)
{
	ll off = 0;
	ll over = str.size();
	while(over--)
	{
		off++;
		bool ok = true;
		repi(i,0,over)
		{
			if(str[i+off] != str[i])
			{
				ok = false;
				break;
			}
		}
		if(ok)
			break;
	}
	return over;
}


int main()
{
	ll test;
	sl(test);
	repii(tt,1,test)
	{
		printf("Case #%lld: ", tt);
		ll k,l,s;
		cin>>k>>l>>s;
		map<char,long double> key;
		string keyboard, target;
		cin>>keyboard;
		cin>>target;		
		repi(i,0,k)
		{
			key[keyboard[i]] += 1.0/k;
		}
		long double prob = 1;
		bool z = false;
		repi(i,0,l)
		{
			prob *= key[target[i]];
			if(key[target[i]] == 0.0)
			{
				//cout<<"did not find "<<target[i]<<endl;
				z = true;
			}
		}
		ll ol = overlap(target);
		ll maxx = (s - ol)/(l - ol);
		if(z) maxx = 0;
		ll pos = s-l+1;
		long double ex = prob*pos;
		long double ans = maxx - ex;
		cout << std::setprecision(7) << ans <<endl;
	}
	return 0;
}