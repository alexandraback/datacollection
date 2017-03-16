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

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> pL;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

ll nu[110];
int rd[110];
int main()
{
  int tn;
  ll A, n;
  int i,j;
  ll x,y;
  ll t;
  ll ans;


  cin >> tn;
  for(int z=1;z<=tn;z++){
    cin >> A >> n;
    for(i=0;i<n;i++)
      cin >> nu[i];
    sort(nu,nu+n);
    ans = INF;
    for(i=0;i<(1<<n);i++){
      t = i;
      for(j=0;j<n;j++){
        rd[j] = t%2;
        t/=2;
      }
      x = 0, y = A;
      for(j=0;j<n;j++){
        if(nu[j]<y) y += nu[j];
        else{
          if(rd[j]==0){
            if(nu[j]!=1){
              while(y <= nu[j]){
                x++;
                y += y-1;
                if(y==1){
                  x = y = INF;
                }
              }
              y += nu[j];
            }else{
              x = INF;
            }
          }else{
            x++;
          }
        }
      }
      
      ans = min(ans, x);
    }
    printf("Case #%d: %lld\n",z, ans);
  }
  return 0;
}
