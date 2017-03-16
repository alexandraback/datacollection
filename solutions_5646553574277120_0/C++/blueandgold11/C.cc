#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
#define fi(n) fo(i,n)
#define fj(n) fo(j,n)
#define fk(n) fo(k,n)
#define fd(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define fo(i,n) fr(i,0,n)
#define fr(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define all(x) (x).begin(),(x).end()
#define sqr(x) ((x)*(x))
#define srt(x) sort(all(x))

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = 1000*1000*1000+7;
const double EPS = 1e-9;
const double PI = acos(-1.0);
template<class T> int chmin(T &t, T f) { return (t>f) ? (t=f,1) : 0; }
template<class T> int chmax(T &t, T f) { return (t<f) ? (t=f,1) : 0; }

inline int getint() {
  int a;
  return scanf("%d",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

inline double getdouble() {
  double a;
  return scanf("%lf",&a) ? a : (fprintf(stderr,"trying to read\n"),-1);
}

void myCode() {
  int tt = getint();
  fo(ttt,tt) {
    int c, d, v;
    cin >> c >> d >> v;
    vi coins(d);
    fi(d)
      coins[i] = getint();
    int best = INF;
    
    fi(1<<v) {
      int cnt = __builtin_popcount(i);
      if (cnt > best)
        continue;

      bool ok = true;
      fj(d) if (!(i&(1<<(coins[j]-1)))) {
        ok = false;
      }
      if (!ok)
        continue;

      vi pos(v+1);
      pos[0] = 1;
      fj(v) if (i&(1<<j)) {
        fd(k,sz(pos)-(j+1))
          if (pos[k] && !pos[k+(j+1)])
            pos[k+(j+1)] = 1;
      }

      ok = true;
      fj(v)
        if (!pos[j+1])
          ok = false;
      if (ok)
        chmin(best,cnt);
    }

    printf("Case #%d: %d\n",ttt+1,best-d);
  }
}

int main () {
  srand(time(NULL));
  myCode();
  return 0;
}
