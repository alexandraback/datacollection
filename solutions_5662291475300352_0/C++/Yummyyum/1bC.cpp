#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll T, N, D, H, M, K;
ll d[2], m[2];

int main(){
  cin >> T;
  for(int _t = 1; _t <= T; _t++){
    printf("Case #%d: ", _t);
    cin >> N;
    K = 0;
    for(int i = 0; i < N; i++){
      cin >> D >> H >> M;
      for(int j = 0; j < H; j++){
        d[K] = D;
        m[K] = M + j;
        K += 1;
      }
    }
    if(K == 1){
      cout << 0 << '\n';
    } else {
      if(m[0] > m[1]){ // fastest first, m0 < m1
        swap(m[0], m[1]);
        swap(d[0], d[1]);
      }
      // time for fast to catch up to slow = d1 - d0 + 360
      // (1/m0 - 1/m1)
      // t = d / (1/m0 - 1/m1) = d / (m1 - m0) * m0 * m1
      ll tn = (d[1] - d[0] + 360) * m[0] * m[1];
      ll td = (m[1] - m[0]) * 360;
      // cout << 1.0 * tn / td << " ";
      // time for slow to finish = (360 - d1) * m1 / 360
      ll sn = (360 - d[1]) * m[1];
      ll sd = 360;
      // cout << 1.0 * sn / sd << endl;
      if(tn * sd < sn * td){
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }
}
