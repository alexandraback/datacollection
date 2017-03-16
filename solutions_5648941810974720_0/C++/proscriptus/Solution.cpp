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
#define eps 1e-6
#define MOD 1000000007
#define PRIME 312427

using namespace std;

void do_it(char let, const string &s, int n, VI &dgt, VI &cnt) {
  int hm(cnt[let-'A']);
  rept(i,sz(s)) {
    cnt[s[i]-'A']-=hm;
  }
  dgt[n]+=hm;
}

void solve_test() {
  string s;
  reads(s);
  VI d(26);
  rept(i,sz(s)) d[s[i]-'A']++;
  VI ans(10);
  do_it('Z',"ZERO",0,ans,d);
  do_it('W',"TWO",2,ans,d);
  do_it('G',"EIGHT",8,ans,d);
  do_it('X',"SIX",6,ans,d);
  do_it('H',"THREE",3,ans,d);
  do_it('S',"SEVEN",7,ans,d);
  do_it('U',"FOUR",4,ans,d);
  do_it('F',"FIVE",5,ans,d);
  do_it('O',"ONE",1,ans,d);
  do_it('I',"NINE",9,ans,d);
  rept(i,10) {
    rept(j,ans[i]) printf("%d",i);
  }
  printf("\n");
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