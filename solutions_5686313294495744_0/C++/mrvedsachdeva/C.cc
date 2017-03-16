#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;

const int N = 4e3 + 5;
map<string, int> s, f;
string a[N];
string b[N];
int main(){
  ios::sync_with_stdio(false); cin.tie(0);
  int t;
  cin >> t;
  for(int cs = 1; cs <= t; cs++){
    int n;
    cin >> n;
    f.clear(), s.clear();
    for(int i = 0; i < n; i++){
      cin >> a[i] >> b[i];

    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
      f.clear(), s.clear();
      int cnt = 0;
      for(int j = 0; j < n; j++){
        if(not (i & (1 << j))){
          f[a[j]] ++;
          s[b[j]] ++;
        }
      }
      for(int j = 0; j < n; j++){
        if((i & (1 << j)) and f[a[j]] > 0 and s[b[j]] > 0){
          cnt++;
        }
      }
      if(cnt == __builtin_popcount(i)){
        ans = max(ans, cnt);
      }
    }
    cout <<"Case #" << cs <<": " << ans << endl;
  }
  return 0;
}
