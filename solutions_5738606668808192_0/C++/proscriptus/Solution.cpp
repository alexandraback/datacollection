#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define uint unsigned int
#define LL long long
#define ULL unsigned LL
#define VI vector<int>
#define X first
#define Y second
#define reads(_s) getline(cin,_s)
#define sz(_v) ((int)_v.size())
#define all(_v) (_v).begin(),(_v).end()
#define FOR(_i,a,b) for (int _i(a),_l(b); _i<=_l; ++_i)
#define rept(i,a) FOR(i,0,(int)(a)-1)
#define x1 X1
#define y1 Y1
#define sqr(a) ((a)*(a))
#define C(a) memset((a),0,sizeof (a))
#define MS(a,x) memset((a),(x),sizeof (a))
#define INF 2100000000
#define INFL INF*1ll*INF
#define PI 3.141592653589
#define eps 1e-9
#define MOD 1000000007
#define PRIME 312427

using namespace std;

int is_prime(__int128_t n) {
  for (int i=2,c=0; i*i<=n && c<5000; ++i,++c) {
    if (n%i==0) return i;
  }
  return 0;
}

void out(unsigned int x, VI &d) {
  string s;
  while (x) {
    s+=(x%2==0?'0':'1');
    x/=2;
  }
  reverse(all(s));
  cout<<s;
  rept(i,sz(d)) printf(" %d",d[i]);
  printf("\n");
}

void solve_test() {
  int n,k;
  scanf("%d%d",&n,&k);
  unsigned int pw = 1LL<<(n-1);
  for (int i=1; ; i+=2) {
    unsigned int x(pw+i);
    VI nmbs;
    FOR(j,2,10) {
      __int128_t res(0);
      __int128_t pw(1);
      unsigned int px(x);
      rept(q,n) {
        res+=(px%2)*pw;
        pw*=j;
        px/=2;
      }
      int rs(is_prime(res));
      if (rs==0) break;
      nmbs.pb(rs);
    }
    if (sz(nmbs)==9) {
      out(x,nmbs);
      --k;
      if (k==0) return;
    }
  }
}

void solve() {
  int tst;
  scanf("%d\n",&tst);
  FOR(t,1,tst) {
    printf("Case #%d:\n",t);
    solve_test();
  }
}

int main() {
#ifdef yeti
  freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#endif

#ifdef yeti
  clock_t tm = clock();
  cout<<setprecision(10);
#endif
  solve();
#ifdef yeti
  cerr<<setprecision(3)<<(clock()-tm+0.)/CLOCKS_PER_SEC<<endl;
#endif
  return 0;
}