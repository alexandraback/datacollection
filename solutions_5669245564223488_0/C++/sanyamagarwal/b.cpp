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
#define mod 1000000007


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

#define vs vector<string>
#define mcb map<char,bool>
#define info pair< pair<char,vs >, mcb >

map<info,ll> memo;

ll rec(char last, vs cars, mcb used)
{
	info cur = mp(mp(last,cars),used);
	if(memo.count( cur )) return memo[cur];
	ll ret = 0;
	ll sz = cars.size();
	if(sz == 0) return 1;

	repi(i,0,sz)
	{
		vs newcars(cars);
		mcb newused(used);
		string car = newcars[i];
		bool psble = true;
		char prev = last;
		repi(j,0,car.size())
		{
			if(car[j]!= prev)
			{
				if(newused[car[j]])
				{
					psble = false;
					break;
				}
				else
					newused[car[j]] = true;
			}
			prev = car[j];
		}
		newcars.erase(newcars.begin() + i);
		if(psble)
		{
			ret += rec(prev, newcars, newused);
		}
	}
	return memo[cur] = ret;
}
bool isValid(string k)
{
	map<char,bool> ch;
	char prev ='$';
	repi(i,0,k.size())
	{
		if(k[i] != prev)
		{
			if(ch[k[i]]) return false;
			else ch[k[i]] = true;
		}
		prev = k[i];
	}
	return true;
}
int main()
{
	
	ll test;
	sl(test);
	repii(tt,1,test)
	{
		printf("Case #%lld: ", tt);
		ll n;
		sl(n);
		vector<string> car(n);
		repi(i,0,n) {
			string temp;
			cin >> temp;
			string good = "";
			char prev = '$';
			ll sz = temp.size();
			repi(j,0,sz)
			{
				if(prev != temp[j])
					good += temp[j];
				prev = temp[j];
			}
			car[i] = good;
		}
		map<char,bool> used;
		//string train;
		memo.clear();
		bool valid = true;
		repi(i,0,car.size())
		{
			if(!isValid(car[i]))
			{
				valid = false;
				break;
			}
		}
		if(!valid)
		{
			printf("0\n");
			continue;
		}
		ll ans = rec('$',car,used);
		printf("%lld\n",ans );
	}
	return 0;
}