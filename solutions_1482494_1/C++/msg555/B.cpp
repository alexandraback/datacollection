#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

#define INF 1000000

int A[1010];
int B[1010];

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    int s = 0, cnt = 0;
    while(s < 2 * N) {
      bool change = true;
      while(change) {
        change = false;
        for(int i = 0; i < N; i++) {
          if(B[i] <= s) {
            change = true;
            ++cnt;
            s += A[i] == INF ? 1 : 2;
            A[i] = B[i] = INF;
          }
        }
      }
      int j = -1;
      for(int i = 0; i < N; i++) {
        if(A[i] > s) continue;
        if(j == -1 || B[i] > B[j]) {
          j = i;
        }
      }
      if(j == -1) break;
      ++cnt;
      ++s;
      A[j] = INF;
    }
    cout << "Case #" << t << ": ";
    if(s == 2 * N) cout << cnt << endl;
    else cout << "Too Bad" << endl;
  }
}
