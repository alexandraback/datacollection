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

int main(){
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);

  int T;
  cin >> T;

  rep(ncase,1,T+1){
    lld a, n;
    cin >> a >> n;

    vlld motes(n);
    REP(i,n) cin >> motes[i];
    sort(motes.begin(),motes.end());

    int ans = n;
    int cnt = 0;
    if(a != 1) REP(i,n){
      while(a <= motes[i]){
	cnt++;
	a += a-1;
      }
      a += motes[i];
      int t = cnt + n - i - 1;
      ans = min(ans,t);
    }
  
    cout << "Case #" << ncase << ": " << ans << endl;
  }
  return 0;
}
