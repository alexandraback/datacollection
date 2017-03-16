#include <bits/stdc++.h>
using namespace std;
#define all(c) (c).begin(),(c).end()
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define REP(i,m,n) for(int i=(int)(m);i<(int)(n);i++)
#define rep(i,n) REP(i,0,n)
#define iter(c) __typeof((c).begin())
#define tr(it,c) for(iter(c) it=(c).begin();it!=(c).end();it++)
#define pb(a) push_back(a)
#define pr(a) cout<<(a)<<endl
#define PR(a,b) cout<<(a)<<" "<<(b)<<endl
#define R cin>>
#define F first
#define S second
#define ll long long
bool check(int n,int m,int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
const ll MAX=1000000007,MAXL=1LL<<60,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
typedef pair<int,int> P;
int c,n,v,a[10];
int ans;
void solve(int k, int cnt, vector<bool> u) {
  if(cnt>=ans) return;
  rrep(i,v) {
    if(i+k>v) continue;
    if(u[i]) u[k+i]=1;
  }
  bool ck=true;
  rep(i,v+1) {
    if(!u[i]) ck=false;
  }
  if(ck) {
    ans=min(ans,cnt);
    return;
  }
  REP(i,k+1,v+1) {
    bool ok=true;
    rep(j,n) {
      if(a[j]==i) ok=0;
    }
    if(!ok) continue;
    solve(i,cnt+1,u);
  }
}
  
int main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    ans=MAX;
    cin >> c >> n >> v;
    rep(i,n) R a[i];
    vector<bool> u(v+1,0);
    u[0]=1;
    rep(i,n) {
      rrep(j,v) {
	if(j+a[i]>v) continue;
	if(u[j]) u[a[i]+j]=1;
      }
    }
    solve(0,0,u);
    /*
    rep(t,1<<5) {
      bool ck=true;
      rep(j,5) {
	if(!(t&(1<<j))) continue;
	rep(k,n) {
	  if(a[k]==(1<<j)) ck=false;
	}
      }
      if(!ck) continue;
      bool uu[v+1];
      rep(i,v+1) uu[i]=u[i];
      rep(i,5) {
	int x=(1<<i);
	if(!(t&x)) continue;
	rrep(j,v) {
	  if(j+x>v) continue;
	  if(uu[j]) uu[x+j]=1;
	}
      }
      rep(i,v+1) {
	if(!uu[i]) ck=false;
      }
      if(ck) ans=min(ans,__builtin_popcount(t));
    }
		*/
    cout << "Case #" << tt << ": " << ans << endl;
  }
  return 0;
}
