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
const int INF = (int) 1000001;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

ll nu[110];
int use[1000010][102];
ll minCst[1000010][102];

int main()
{
  pL sQ;
  int tn;
  ll A, n;
  int i;
  ll ans;
  
  cin >> tn;
  for(int z=1;z<=tn;z++){
    cin >> A >> n;
    for(i=1;i<=n;i++)
      cin >> nu[i];
    sort(nu+1, nu+n+1);

    ans = INF;
    sQ = mp(0, A);
    queue<pL> Q;

    minCst[0][A] = 0;

    Q.push(sQ);
    while(!Q.empty()){
      pL now = Q.front();
      Q.pop();
      ll ind = now.x;
      ll vol = now.y;
      ll cst = minCst[ind][vol];
      ll nVol;
      pL nx;
      //printf("ind %lld vol %lld cst %lld\n",ind,vol,cst);
      if(ind==n) {
        ans = min(ans, cst);
        continue;
      }
      if(vol > nu[ind+1]){
        nVol = min(ll(vol+nu[ind+1]), ll(INF));
        nx = mp(ind+1, nVol);
        if(use[ind+1][nVol]!=z){
          use[ind+1][nVol] = z;
          minCst[ind+1][nVol] = cst;
          Q.push(nx);
        }else minCst[ind+1][nVol] = min(minCst[ind+1][nVol], cst);
      }else{
        nx = mp(ind+1, vol);
        if(use[ind+1][vol]!=z){
          use[ind+1][vol] = z;
          Q.push(nx);
          minCst[ind+1][vol] = cst+1;
        }

        if(vol!=1){
          nVol = vol;
          while(nVol <= nu[ind+1]){
            nVol = min(ll(nVol+nVol-1), ll(INF));
            cst++;
          }
          nVol = min(ll(nVol+nu[ind+1]), ll(INF));
          nx = mp(ind+1, nVol);


          if(use[ind+1][nVol]!=z){
            use[ind+1][nVol] = z;
            Q.push(nx);
            minCst[ind+1][nVol] = cst;
          }else minCst[ind+1][nVol] = min(minCst[ind+1][nVol], cst);

        }
      }
    }
    printf("Case #%d: %lld\n",z,ans);

  }
  return 0;
}
