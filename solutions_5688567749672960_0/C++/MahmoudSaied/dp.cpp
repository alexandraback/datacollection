#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fore(i,n) for(int i = 0; i< n ; i++ )
#define lop(i,n) for(int i = 1 ; i<=n ; i++ )
#define ops(i,n) for(int  i = n-1 ; i>=0 ; i-- )
#define	forall( it,g )	for(typeof(g.begin()) it=g.begin();it!=g.end();it++ )
#define PI  3.141592653589793
#define mod  1000000007
#define inf 10000000000
#define INF -100000000000
#define modulo 1073741824
#define MH 1234533333333337
#define MM 1793723455573331
//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef vector <int > vi;
typedef vector <vector <int> > vv;
typedef vector <pair <int,int > >vp;
typedef vector <vector <pair <int ,int > > > vvp;
typedef vector <pair <int ,pair <int ,int > > > vpp;
typedef pair<int,int> pp;
typedef  long long ll;
int target;
int dp[1000010];
int rev(int n){
  vi v ;
  while(n){
    v.pb(n%10);
    n/=10;
  }
  int x = 0;
  fore(i , v.size()){
    x*=10;
    x+=v[i];
  }
  return x;
}
int ways(int n){
  if(n == target)return 0 ;
  if(n>target)return 100000000;
  if(dp[n]!=-1)return dp[n];
  int y = rev(n),x = 100000000;
  if(y>n)
    x = ways(y);
  return dp[n] = 1 + min(x,ways(n+1));
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  freopen("A-small-attempt1.in","r",stdin);
  freopen("out.txt","w",stdout);
  ll n ;
  int test ,x = 0;
  cin >> test;
  while(test--){
      x++;
    cin >> n ;
    target = n ;
    memset(dp,-1,sizeof dp);
    cout << "Case #" << x << ": "<<ways(0) <<endl;
  }
  return 0;
}

