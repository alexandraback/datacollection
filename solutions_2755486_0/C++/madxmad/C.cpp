#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>

using namespace std;

#define D(x) cout << #x << " = " << x << endl;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repd(i,a,b) for(int i=b-1;i>=a;i--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair

typedef long long int lld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<lld> vlld;

vlld wall(2005);


int main(){
  freopen("C.in","r",stdin);
  freopen("C.out","w",stdout);

  int T;
  cin >> T;

  rep(ncase,1,T+1){
    int N;
    cin >> N;

    vlld d(N), n(N), w(N), e(N), s(N), dd(N), dp(N), ds(N);
    REP(i,N){
      cin >>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>dd[i]>>dp[i]>>ds[i];
      w[i] += 1000; e[i] += 1000;
    }
    vlld cnt(n.begin(),n.end());

    fill(wall.begin(),wall.end(),0);
    int ans = 0;
    REP(day,676060+1){
      REP(i,N) if(d[i] == day){
	// D(day); D(i+1);
	// D(w[i]); D(e[i]); D(s[i]);
	bool success = false;
	rep(pos,w[i],e[i]) if(wall[pos] < s[i])
	  success = true;
	if(success) ans++;
	//if(success) cout << "exitoso" << endl;
      }
      REP(i,N) if(d[i] == day){
	rep(pos,w[i],e[i])
	  wall[pos] = max(wall[pos],s[i]);
      }

      REP(i,N) if(d[i] == day){
	cnt[i]--;
	if(!cnt[i]) continue;
	d[i] += dd[i]; w[i] += dp[i]; e[i] += dp[i]; s[i] += ds[i];
      }
    }
      
  cout << "Case #" << ncase << ": " << ans << endl;
    
  }
  return 0;
}
