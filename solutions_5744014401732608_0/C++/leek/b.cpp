#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int T;
ll pow2(ll bs, ll pw) {
  if(pw ==0) return 1;
  ll hf = pow2(bs, pw/2);
  if(pw%2 ==1) return hf * hf * bs;
  else return hf * hf;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    ll B, M;
    cin >> B >> M;
    printf("Case #%d: ",tc);
    if (M > pow2(2, B-2)) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    } else {
      cout << "POSSIBLE" << endl;
    }
    vector<bool> con;
    for(int i=0; i<=B; i++) con.push_back(false);
    
    ll tem = M;
    for(int i=B-1; i >=1; i--) {
      ll j = i - 2;
      if(j < 0) j = 0;
      ll cnd = pow2(2,j);
      if(cnd <= tem) {
        con[i] = true;
        tem -= cnd;
      }
    }
    for(int i=1; i<B; i++) {
      for(int j=1; j<B; j++) {
        if(i < j) cout << 1;
        else cout << 0;
      }
      if(con[i]) cout << 1;
      else cout << 0;
      cout << endl;
    }

    for(int i=0;i<B;i++) cout <<0;
    printf("\n");
  }

  return 0;
}