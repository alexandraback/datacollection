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
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii > vii;
typedef vector<pair<int, pair<int, int> > > viii;
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
#define loop(x,a,b) for(int (x) = (a);(x)<(b);(x)++)
#define rep(x,n)   for(int (x)=0;(x)<(n);(x)++)
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define ain(a,n) int ((a)[(n)]); for(int i=0; i<(n); i++) cin>>((a)[i])  
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
  #define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl;
  #define prc(a) tr(a, it) cerr<<*(it)<<" "; cerr<<endl
  #define pra(a,n) for(int i=0; i<(n); i++) cerr<<((a)[i])<<" "; cerr<<"\n"
  #define prdd(a,r,c) for(int i=0;i<(r);i++) { for(int j = 0;j<(c);j++) cerr<<a[i][j]<<" "; cerr<<endl; } cerr<<endl; 
  #define prddd(a,x,y,z) for(int i=0;i<x;i++) {cerr<<"layer "<<i<<":\n";prdd(a[i],y,z)}

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

void fn()
{
	string s;
	cin>>s;
	int n = s.size();
	map<char,int> dic;
	rep(i,n)
		dic[s[i]-'A'+'a'] ++;
	vi ans;
	while(dic['z'])
	{
		ans.pb(0);
		dic['z']--;
		dic['e']--;
		dic['r']--;
		dic['o']--;
	}

	while(dic['x'])
	{
		ans.pb(6);
		dic['s']--;
		dic['i']--;
		dic['x']--;
	}
	while(dic['w'])
	{
		ans.pb(2);
		dic['t']--;
		dic['w']--;
		dic['o']--;
	}
	while(dic['u'])
	{
		ans.pb(4);
		dic['f']--;
		dic['o']--;
		dic['u']--;
		dic['r']--;
	}

	while(dic['g'])
	{
		ans.pb(8);
		dic['e']--;
		dic['i']--;
		dic['g']--;
		dic['h']--;
		dic['t']--;
	}
	while(dic['o'])
	{
		ans.pb(1);
		dic['o']--;
		dic['n']--;
		dic['e']--;
	}
	
	while(dic['r'])
	{
		ans.pb(3);
		dic['t']--;
		dic['h']--;
		dic['r']--;
		dic['e']--;
		dic['e']--;
	}
	while(dic['f'])
	{
		ans.pb(5);
		dic['f']--;
		dic['i']--;
		dic['v']--;
		dic['e']--;
	}
	while(dic['s'])
	{
		ans.pb(7);
		dic['s']--;
		dic['e']--;
		dic['v']--;
		dic['e']--;
		dic['n']--;
	}
	while(dic['e'])
	{
		ans.pb(9);
		dic['n']--;
		dic['i']--;
		dic['n']--;
		dic['e']--;
	}
	sort(all(ans));
	rep(i,ans.size())
		cout<<ans[i];
	cout<<"\n";
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    rep(i,t)
    {
    	cout<<"Case #"<<i+1<<": ";
    	fn();
    }

    return 0;
}
