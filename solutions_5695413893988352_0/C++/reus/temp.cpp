#include <cstdio>
#include <iostream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<long long,long long> pii;
typedef vector<pii > vii;
typedef vector<pair<long long, pair<long long, long long> > > viii;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<vii> vvii;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define MEM(a,b) memset(a,(b),sizeof(a))
#define tr(c,it) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define all(a) a.begin(),a.end()
#define loop(x,a,b) for(long long (x) = (a);(x)<(b);(x)++)
#define rep(x,n)   for(long long (x)=0;(x)<(n);(x)++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) long long ((a)[(n)]); for(long long i=0; i<(n); i++) cin>>((a)[i])  
#define md 1000000007
#define MAXN 200005

#define pr16

#ifdef pr16
  #define pr(x)                 cerr << #x << ": " << x << endl;
  #define pr2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
  #define pr3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
  #define pr4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
  #define pr5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
  #define pr6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
  #define prdd(a,r,c) for(long long i=0;i<(r);i++) { for(long long j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl;
  #define prc(a) tr(a, it) cerr<<*(it)<<" "; cerr<<endl
  #define pra(a,n) for(long long i=0; i<(n); i++) cerr<<((a)[i])<<" "; cerr<<"\n"
  #define prdd(a,r,c) for(long long i=0;i<(r);i++) { for(long long j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl; 
  #define prddd(a,x,y,z) for(long long i=0;i<x;i++) {cerr<<"layer "<<i<<":\n";prdd(a[i],y,z)}

#else
  #define pr(x)
  #define pr2(x, y)
  #define pr3(x, y, z)
  #define pr4(a, b, c, d)
  #define pr5(a, b, c, d, e)
  #define pr6(a, b, c, d, e, f)
  #define tr(c,it)
  #define prc(a)
  #define pra(a,n)
  #define prdd(a, r, c)
  #define prddd(a,x,y,z)
#endif

long long dif(string s1,string s2)
{
	long long n = s1.size();
	ll ans = 0;
	rep(i,n)
	{
		ans *= 10;
		ans += s1[i]-s2[i];
	}
	return ans;
}

void fn()
{
	string s1,s2;
	cin>>s1>>s2;
	long long n = s1.size();

	ll ans = 1e18;
	string n1,n2;

	long long flag = 0;
	rep(i,n)
		if(s1[i] != '?' and s2[i] != '?' and s1[i] != s2[i])
			flag = 1;
	string c1 = s1,c2 = s2;
	if(flag == 0)
	{
		rep(i,n)
			if(s1[i] == '?' and s2[i] == '?')
				s1[i] = s2[i] = '0';
			else if(s1[i] == '?')
				s1[i] = s2[i];
			else s2[i] = s1[i];
		cout<<s1<<" "<<s2<<"\n";
		return;
	}
	rep(digit,n)
	{
		s1 = c1;
		s2 = c2;
		flag = 0;
		rep(i,digit)
		{
			if(s1[i] != s2[i] and s1[i] != '?' and s2[i] != '?')
			{
				flag = 1;
				break;
			}
			else if(s1[i] == '?' and s2[i] == '?')
				s1[i] = s2[i] = '0';
			else if(s1[i] == '?')
				s1[i] = s2[i];
			else
				s2[i] = s1[i];
		}
		if(flag == 1)
			continue;
		if(s1[digit] == '0' or s2[digit] == '9')
			continue;
		if(s1[digit] != '?' and s2[digit] != '?' and s1[digit] <= s2[digit])
			continue;
		if(s1[digit] == '?' and s2[digit] == '?')
		{
			s1[digit] = '1';
			s2[digit] = '0';
		}
		if(s1[digit] == '?')
			s1[digit] = s2[digit] + 1;
		if(s2[digit] == '?')
			s2[digit] = s1[digit] - 1;
		loop(i,digit+1,n)
		{
			if(s1[i] == '?')
				s1[i] = '0';
			if(s2[i] == '?')
				s2[i] = '9';
		}
		ll tmp = dif(s1,s2);
		if(tmp < ans or (tmp == ans and s1 < n1) or (tmp == ans and s1 == n1 and s2 < n2))
		{
			ans = tmp;
			n1 = s1;
			n2 = s2;
		}
		s1 = c1;
		s2 = c2;
	}
	rep(digit,n)
	{
		s1 = c1,s2 = c2;
		flag = 0;
	
		rep(i,digit)
		{
			if(s1[i] != s2[i] and s1[i] != '?' and s2[i] != '?')
			{
				flag = 1;
				break;
			}
			else if(s1[i] == '?' and s2[i] == '?')
				s1[i] = s2[i] = '0';
			else if(s1[i] == '?')
				s1[i] = s2[i];
			else
				s2[i] = s1[i];
		}

		if(flag == 1)
			continue;
		// pr2(s1,s2);
		if(s1[digit] == '9' or s2[digit] == '0')
			continue;
		// pr(n);
		if(s1[digit] != '?' and s2[digit] != '?' and s1[digit] >= s2[digit])
			continue;

		if(s1[digit] == '?' and s2[digit] == '?')
		{
			s1[digit] = '0';
			s2[digit] = '1';
		}
		if(s1[digit] == '?')
			s1[digit] = s2[digit] - 1;
		if(s2[digit] == '?')
			s2[digit] = s1[digit] + 1;

		loop(i,digit+1,n)
		{
			if(s1[i] == '?')
				s1[i] = '9';
			if(s2[i] == '?')
				s2[i] = '0';
		}
		ll tmp = dif(s2,s1);
		if(tmp < ans or (tmp == ans and s1 < n1) or (tmp == ans and s1 == n1 and s2 < n2))
		{
			ans = tmp;
			n1 = s1;
			n2 = s2;
		}
		s1 = c1;
		s2 = c2;
	}

	vi v;
	rep(iii,10000)
	{
		ll bm = iii;
		vi v;
		rep(j,4)
		{
			v.pb(bm %10);
			bm /= 10;
		}
		ll id = 0;
		rep(i,n)
			if(s1[i] == '?')
			{
				s1[i] = '0'+v[id];
				id++;
			}

		rep(i,n)
			if(s2[i] == '?')
			{
				s2[i] = '0'+v[id];
				id++;
			}

		ll tmp;
		if(s1 > s2)
			tmp = dif(s1,s2);
		else
			tmp = dif(s2,s1);
		if(tmp < ans or (tmp == ans and s1 < n1) or (tmp == ans and s1 == n1 and s2 < n2))
		{
			pr4(c1,c2,n1,n2);
			return;
		}
		s1 = c1,s2 = c2;
	}


	cout<<n1<<" "<<n2<<"\n";
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long t;
    cin>>t;
    rep(i,t)
    {
    	cout<<"Case #"<<i+1<<": ";
    	fn();
    }

    return 0;
}
