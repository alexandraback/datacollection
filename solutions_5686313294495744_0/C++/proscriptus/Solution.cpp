#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
#define uint unsigned int
#define LL __int128
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
#define eps 1e-6
#define MOD 1000000007
#define PRIME 312427

using namespace std;

void solve_test() {
  int n;
  scanf("%d\n",&n);
  vector<vector<string>> d(n,vector<string>(2));
  rept(i,n) {
    getline(cin,d[i][0],' ');
    reads(d[i][1]);
  }
  int to(1<<n);
  int ans(0);
  rept(i,to) {
    int ci(i);
    vector<bool> fks(n);
    rept(j,n) {
      fks[j]=ci&1;
      ci/=2;
    }
    VI ord;
    int nnfks(0);
    rept(j,n) {
      if (!fks[j]) ord.pb(j),++nnfks;
    }
    rept(j,n) {
      if (fks[j]) ord.pb(j);
    }
    set<string> fst;
    set<string> scn;
    bool ok(true);
    rept(j,n) {
      int now(ord[j]);
      if (j<nnfks) {
        fst.insert(d[now][0]);
        scn.insert(d[now][1]);
      } else {
        if (!fst.count(d[now][0]) || !scn.count(d[now][1])) {
          ok=false;
        }
      }
    }
    if (ok) ans=max(ans,n-nnfks);
  }
  printf("%d\n",ans);
}

void solve() {
  int n;
  scanf("%d\n",&n);
  rept(t,n) {
    printf("Case #%d: ",t+1);
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