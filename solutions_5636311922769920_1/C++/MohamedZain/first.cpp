#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define PI 3.1415926535897932384626433832
#define MOD 1000000007

/*
*
* Zaiiiiiin
*
*/

using namespace std;

typedef pair<int,int> ii;

ll k, c, s, T, t = 0;
vector<ll> sol;

int main(){
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> T;
  while(T--){
    sol.clear();
    cin >> k >> c >> s;
    ll st, cnt = 1;
    cout << "Case #" << ++t << ":";
    if(c * s < k){
      puts(" IMPOSSIBLE");
      continue;
    }
    while(cnt <= k){
      st = cnt;
      for(int i=0; i<c-1; i++){
        cnt += (cnt < k);
        st = (st-1) * k + cnt;
      }
      cnt++;
      sol.push_back(st);
    }
    for(auto x: sol) cout << " " << x;
    puts("");
  }
  return 0;
}
