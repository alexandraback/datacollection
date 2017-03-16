#include<bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

int main() {
  int T;
  cin >> T;
  for(int k = 1; k <= T; k++) {
    int D;
    cin >> D;
    vector< int > P(D);
    for(int i = 0; i < D; i++) {
      cin >> P[i];
    }

    int ret = INF;
    for(int i = 1; i <= 1000; i++) { // 最小値をこうする
      int cnt = 0;
      for(int j = 0; j < D; j++) {
        int digit = P[j];
        while(digit > i) {
          digit -= i;
          cnt++;
        }
      }
      ret = min(ret, cnt + i);
    }

    cout << "Case #" << k << ": " << ret << endl;
  }
}
