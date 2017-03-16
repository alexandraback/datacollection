#include <bits/stdc++.h>
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


// #define pr16

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

long long mul(long long x,long long y)
{
  if(x == 1 or y == 1)
    return x*y;
  if(x == -1 or y == -1)
    return x*y;
  if(abs(x) == abs(y))
    return 1-2*(x == y);
  long long xc = x,yc = y;
  x = abs(x);
  y = abs(y);
  return (2*(xc*yc > 0)-1)*(9-x-y)*(1-2*((y-x+3)%3 != 1));
}

long long rmul(long long x,long long y)
{
  if(x == 1 or y == 1)
    return x*y;
  if(x == -1 or y == -1)
    return x*y;
  if(abs(x) == abs(y))
    return 1-2*(x == y);
  long long xc = x,yc = y;
  x = abs(x);
  y = abs(y);

  return (2*(xc*yc > 0)-1)*(9-x-y)*(1-2*((y-x+3)%3 == 1));
}

long long expMod(long long base, long long ex)
{
  if(ex == 1) return base;
  long long temp = expMod(base,ex/2);
  temp = mul(temp,temp);
  if(ex%2) temp = mul(temp,base);
  return temp;
}


void fn()
{
  long long v = 1;
  long long l,x;
  cin>>l>>x;
  string s;
  cin>>s;
  rep(i,s.length())
    v = mul(v,s[i]-'g');
  
  if(expMod(v,x) != -1)
  {
    cout<<"NO\n";
    return;
  }
  string s2;
  long long num = min(x,10000LL);
  rep(i,num)
    s2 += s;
  long long i1 = s2.length(),i2 = 0;;
  v = 1;
  rep(i,s2.length())
  {
    v = mul(v,s2[i]-'g');
    pr(v);
    if(v == 2)
    {
      i1 = i;
      break;
    }
  }
  pr(i1);
  v = 1;
  for(long long i = s2.length()-1;i>=0;i--)
  {
    v = rmul(v,s2[i]-'g');
    if(v == 4)
    {
      i2 = i;
      break;
    }
  }
  if(i1<i2)
    cout<<"YES\n";
  else
    cout<<"NO\n";
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
