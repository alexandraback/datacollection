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

struct state {
  int put0;
  int put1;
  int back_st;
  string cr1,cr2;
};

pair<string, string> get_ans(string &a, string &b, vector<vector<state>> &prev, int st) {
  string resa(a);
  string resb(b);
  int n(sz(a));
  for (int i=n; i>0; --i) {
    int prv(prev[i][st].back_st);
    if (a[i-1]=='?') resa[i-1]='0'+prev[i][st].put0;
    if (b[i-1]=='?') resb[i-1]='0'+prev[i][st].put1;
    st=prv;
  }
  return mp(resa,resb);
}

bool corr(string &a, int b) {
  string nr;
  rept(i,sz(a)) {
    nr+='0'+b%10;
    b/=10;
  }
  if (b!=0) return false;
  reverse(all(nr));
  rept(i,sz(a)) {
    if (a[i]!='?' && a[i]!=nr[i]) return false;
  }
  return true;
}

void solve_brute(string &a, string &b) {
  int diff(INF);
  int r0,r1;
  rept(i,1000) {
    rept(j,1000) {
      if (corr(a,i) && corr(b,j)) {
        if (diff>abs(i-j)) {
          diff=abs(i-j);
          r0=i;
          r1=j;
        }
      }
    }
  }
  printf("brute %d %d\n",r0,r1);
}

bool lower(string &a, string &b, string &c, string &d) {
  return a<c || a==c && b<d;
}

void solve_test() {
  string s,t;
  getline(cin,s,' ');
  getline(cin,t);
  // solve_brute(s,t);
  int n(sz(s));
  vector<vector<LL>> dyn(n+1,vector<LL>(3));
  vector<vector<state>> prev(n+1,vector<state>(3));
  vector<vector<bool>> dyn_have(n+1,vector<bool>(3));
  dyn_have[0][0]=dyn_have[0][1]=dyn_have[0][2]=true;
  rept(i,n) {
    rept(j,3) {
      ULL now(dyn[i][j]*10);
      if (!dyn_have[i][j]) continue;
      rept(d0,10) {
        rept(d1,10) {
          int k1(s[i]-'0');
          int k2(t[i]-'0');
          if (s[i]=='?') k1=d0;
          if (t[i]=='?') k2=d1;
          int diff(k1-k2);
          string ncr1(prev[i][j].cr1+(char)('0'+k1));
          string ncr2(prev[i][j].cr2+(char)('0'+k2));
          LL nnow(now+diff);
          if (nnow!=0 && nnow>0 && (dyn_have[i+1][0]==false || (dyn[i+1][0]>nnow) || (dyn[i+1][0]==nnow && lower(ncr1,ncr2,prev[i+1][0].cr1,prev[i+1][0].cr2)))) {
            dyn_have[i+1][0]=true;
            dyn[i+1][0]=nnow;
            prev[i+1][0]={d0,d1,j,prev[i][j].cr1+(char)('0'+k1),prev[i][j].cr2+(char)('0'+k2)};
          }
          if (nnow!=0 && nnow<0 && (dyn_have[i+1][2]==false || (dyn[i+1][2]<nnow) || (dyn[i+1][2]==nnow && lower(ncr1,ncr2,prev[i+1][2].cr1,prev[i+1][2].cr2)))) {
            dyn_have[i+1][2]=true;
            dyn[i+1][2]=nnow;
            prev[i+1][2]={d0,d1,j,prev[i][j].cr1+(char)('0'+k1),prev[i][j].cr2+(char)('0'+k2)};
          }
          if (nnow==0 && (dyn_have[i+1][1]==false || lower(ncr1,ncr2,prev[i+1][1].cr1,prev[i+1][1].cr2))) {
            dyn_have[i+1][1]=true;
            dyn[i+1][1]=nnow;
            prev[i+1][1]={d0,d1,j,prev[i][j].cr1+(char)('0'+k1),prev[i][j].cr2+(char)('0'+k2)};
          }
        }
      }
    }
  }
  int st;
  // cout<<(long long)dyn[n][0]<<" "<<(long long)dyn[n][1]<<" "<<(long long)dyn[n][2]<<endl;
  // cout<<(long long)dyn_have[n][0]<<" "<<(long long)dyn_have[n][1]<<" "<<(long long)dyn_have[n][2]<<endl;
  if (dyn_have[n][1]) st=1;
  else if (!dyn_have[n][0]) st=2;
  else if (!dyn_have[n][2]) st=0;
  else if (dyn[n][0]<-dyn[n][2]) st=0;
  else if (dyn[n][0]>-dyn[n][2]) st=2;
  else st=4;
  if (st!=4) {
    auto r(get_ans(s,t,prev,st));
    cout<<r.X<<" "<<r.Y<<endl;
  } else {
    auto o(get_ans(s,t,prev,0));
    auto w(get_ans(s,t,prev,2));
    if (w.X<o.X || w.X==o.X && w.Y<o.Y) o=w;
    cout<<o.X<<" "<<o.Y<<endl;
  }
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