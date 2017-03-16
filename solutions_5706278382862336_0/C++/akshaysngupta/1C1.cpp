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

ll gcd(ll a ,ll b)
{
	if(a<b)	swap(a,b);
	ll temp=a;
	while(b!=0)
	{
		temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w+",stdout);
  ll test,t,div_idx,_gcd,i,first_i=-1;
  ll p,q;
  float temp;
  string s;
  cin >> test;
  t = test;
  bool flag;

  while(test--)
  {
  	cin >> s;
  	div_idx=0;
  	while(s[div_idx]!='/')
  		div_idx++;
  	p = atoi(s.substr(0,div_idx).c_str());
  	q = atoi(s.substr(div_idx+1,s.length()-div_idx).c_str());
  	
  	temp=1;
  	flag = false;
  	i=0;
  	first_i=-1;
  	while(1)
  	{
  		temp *=2;
  		i++;
  		if((1.0*q)/p <= temp)
  		{
  			if(first_i==-1)
  				first_i = i;
  			p=p*temp-q;
  			q = q*temp;
  			_gcd = gcd(p,q);
  			p/=_gcd;
  			q/=_gcd;
  		}
  		if(p<0)
  			break;
  		if(p==0)
  		{
  			flag=true;
  			break;
  		}
  	}
  	if(flag)
  		printf("Case #%lld: %lld\n",t-test,first_i);
  	else printf("Case #%lld: impossible\n",t-test);
  }
  return 0;
}