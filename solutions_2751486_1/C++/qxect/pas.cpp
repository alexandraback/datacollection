#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) (int((a).size()))
#define all(a) (a).begin(), (a).end()
#define For(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)

typedef complex<int> cI;
typedef pair<int,int> pII;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

ll chk(char now){
  if(now=='a' || now=='e' || now=='i' || now=='o' || now=='u')return 0;
  return 1;
}
char str[1000010];

ll dp[1000010];

int main()
{
  int tn;
  int n,len;
  ll ans,p;
  
  cin >> tn;
  for(int z=1;z<=tn;z++){
    printf("Case #%d: ",z);
    scanf("%s%d",str, &n);
    len = strlen(str);
    ans = 0;
    p = -1;
    for(int i=0;i<len;i++){
      if(chk(str[i]))dp[i+1] = dp[i] + chk(str[i]);
      else dp[i+1] = 0;
      if(dp[i+1] >= n){
        p = i - n + 1ll;
      }
      ans += p + 1ll;
      //printf("i %d: dp %lld p %lld ans %lld\n",i, dp[i+1], p+1, ans);
    }
    printf("%lld\n",ans);
  }

  return 0;
}
