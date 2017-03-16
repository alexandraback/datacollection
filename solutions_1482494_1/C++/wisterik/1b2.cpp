#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <cstring>

#define rep(i,n) for(int i = 0; i < n; i++)
#define SZ(v) ((int)(v).size())
#define pb push_back
#define all(v) (v).begin(), (v).end()

#define trace(x) cerr << #x << " = " << x << endl;

#define fst get<0>
#define snd get<1>

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int> int2;

const int INF = 1 << 29;

int n;
vector<int2> v;

int main(){

  int t;
  cin >> t;

  rep(i,t){
    cin >> n;

    v = vector<int2>(n);

    rep(j,n) cin >> fst(v[j]) >> snd(v[j]);

    sort(all(v), [](int2 x, int2 y){
        return snd(x) > snd(y);
      });

    int cnt = 0;
    int ans = 0;
    vector<int2> state(n, make_tuple(0,0));
    bool imposibble = false;
    while(cnt < 2*n){
      bool flg = false;
      rep(j,n){
        if(snd(state[j])) continue;
        
        if(cnt >= snd(v[j]) && cnt >= fst(v[j])){
          if(fst(state[j])){
            cnt += 1;
          }
          else {
            cnt += 2;
          }
          fst(state[j]) = 1;
          snd(state[j]) = 1;
          ans++;
          flg = true;
          break;
        }
      }
      if(flg) continue;
      rep(j,n){
        if(fst(state[j])) continue;
        if(cnt >= fst(v[j])){
          cnt += 1;
          fst(state[j]) = 1;
          ans++;
          flg = true;
          break;
        }
      }
      if(flg) continue;
      imposibble = true;
      break;
    }

    if(imposibble)
      cout << "Case #" << i+1 << ": " << "Too Bad" << endl;
    else 
      cout << "Case #" << i+1 << ": " << ans << endl;
  }
  return 0;

}
