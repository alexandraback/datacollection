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


typedef vector<long long> VI;
typedef vector<VI> VVI;

bool FindMatch(long long i, const VVI &w, VI &mr, VI &mc, VI &seen) {
  for (long long j = 0; j < w[i].size(); j++) {
    if (w[i][j] && !seen[j]) {
      seen[j] = true;
      if (mc[j] < 0 || FindMatch(mc[j], w, mr, mc, seen)) {
        mr[i] = j;
        mc[j] = i;
        return true;
      }
    }
  }
  return false;
}

long long BipartiteMatching(const VVI &w, VI &mr, VI &mc) {
  mr = VI(w.size(), -1);
  mc = VI(w[0].size(), -1);
  
  long long ct = 0;
  for (long long i = 0; i < w.size(); i++) {
    VI seen(w[0].size());
    if (FindMatch(i, w, mr, mc, seen)) ct++;
  }
  return ct;
}

void fn()
{
	map<pair<string,int> , long long > dic;
	long long n;
	cin>>n;
	long long id = 0;
	vii tmp;
	rep(i,n)
	{
		string s1,s2;
		cin>>s1>>s2;
		if(dic.count(mp(s1,1)) == 0)
		{
			dic[mp(s1,1)] = id;
			id++;
		}
		if(dic.count(mp(s2,2)) == 0)
		{
			dic[mp(s2,2)] = id;
			id++;
		}
		tmp.pb(mp(dic[mp(s1,1)],dic[mp(s2,2)]));
	}

	int ans = 100;

	rep(bm,1<<n)
	{
		set<int> s;
		rep(i,n)
		{
			if(bm & (1<<i))
				s.insert(tmp[i].Y),s.insert(tmp[i].X);
		}
		int num = __builtin_popcount(bm);
		if(s.size() == id)
			ans = min(ans,num);
	}
	cout<<n-ans<<"\n";
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
