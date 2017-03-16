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

int main() {
  int T;
  R T;
  REP(tt,1,T+1) {
    int n;
    R n;
    double d[n],h[n],m[n];
    rep(i,n) cin >> d[i] >> h[i] >> m[i];
    int ans=MAX;
    rep(i,n) {
      double time=360.0/m[i];
      int cnt=0;
      rep(j,n) {
	rep(k,h[j]) {
	  double x=(double)(m[j]+k)/360.0*time;
	  x+=d[j]/360;
	  if(x>=2 || x<1) cnt++;
	}
      }
      ans=min(ans,cnt);

      time=360.0/(m[i]+h[i]-1);
      cnt=0;
      rep(j,n) {
	rep(k,h[j]) {
	  double x=(double)(m[j]+k)/360.0*time;
	  x+=d[j]/360;
	  if(x>=2 || x<1) cnt++;
	}
      }
      ans=min(ans,cnt);
    }
    cout << "Case #" << tt << ": " << ans << endl;
  }
  return 0;
}
