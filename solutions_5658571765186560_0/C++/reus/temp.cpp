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

void fn()
{
  int x,r,c;
  cin>>x>>r>>c;
  if((r*c)%x != 0)
  {
    cout<<"RICHARD\n";
    return ;
  }

  if(x > max(r,c))
  {
    cout<<"RICHARD\n";
    return ;
  } 

  if(x == 1 or x == 2 or (x == 3 and min(r,c) >= 2) or (x == 4 and r * c >= 12 ))
    cout<<"GABRIEL\n";
  else
    cout<<"RICHARD\n";

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
