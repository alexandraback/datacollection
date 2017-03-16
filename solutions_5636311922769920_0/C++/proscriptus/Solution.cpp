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

LL get(int startk, int k, int c, int maxcoef) {
  LL res(1);
  LL pw(1);
  rept(i,c) {
    int coef(startk+c-1-i);
    if (coef>=maxcoef) coef=0;
    res+=coef*pw;
    pw*=k;
  }
  return res;
}

void solve_test() {
  int k,c,s;
  scanf("%d%d%d",&k,&c,&s);
  if (c*s<k) {
    puts("IMPOSSIBLE");
    return;
  }

  if (k==1) {
    printf("1\n");
    return;
  }

  vector<LL> ans;
  LL offset(0);
  while (offset<k) {
    ans.pb(get(offset,k,c,k));
    offset+=c;
  }

  rept(i,sz(ans)) printf("%lld%c",ans[i],i+1==sz(ans)?'\n':' ');
}

void solve() {
  int tst;
  scanf("%d\n",&tst);
  FOR(t,1,tst) {
    printf("Case #%d: ",t);
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