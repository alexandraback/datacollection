#include<bits/stdc++.h>
using namespace std;
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);

#define endl '\n'
#define D(x) cout << #x << " = " << (x) << endl;
#define rep(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define repd(i,a,b) for(int (i)=(b)-1;(i)>=(a);(i)--)
#define REP(i,n) rep(i,0,n)
#define REPD(i,n) repd(i,0,n)
#define pb push_back
#define mp make_pair
#define countbits(x) __builtin_popcount(x)
#define countbitslld(x) __builtin_popcountll(x)

typedef long long int lld;
typedef vector<int> vi;
typedef vector<lld> vlld;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

int main(){ IO;
  int t;
  cin >> t;

  rep(ncase,1,t+1){
    cout << "Case #" << ncase << ": ";

    int k, l, s;
    cin >> k >> l >> s;

    string keyboard, target;
    cin >> keyboard >> target;

    int len = 1;
    REP(i,s) len *= k;

    int mx = 0, sum = 0;
    REP(mask,len){
      int t = mask;

      string w;
      REP(kk,s){
        int d = t % k;
        t /= k;
        w += keyboard[d];
      }

      int cnt = 0;
      REP(i,w.size()){
        if(i + target.size() > w.size()) break;
        string wi = w.substr(i, target.size());
        if(target == wi){
          cnt++;
        }
      }
      mx = max(mx, cnt);
      sum += cnt;
    }

    double ans = sum; ans /= len;
    ans = mx - ans;
    cout << fixed << setprecision(7) << ans << endl;
  }

  return 0;
}
