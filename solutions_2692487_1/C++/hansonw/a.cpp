#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    int A, N; cin >> A >> N;
    int mote[111];
    for (int i = 0; i < N; i++) {
      cin >> mote[i];
    }
    sort(mote, mote+N);
    
    int ans = N;
    if (A > 1) { // can't absorb anything if A = 1
      for (int i = 0; i <= N; i++) { // keep the first i motes
        long long cur = A;
        int req = N-i;
        for (int j = 0; j < i; j++) {
          while (cur <= mote[j]) {
            // we have to add motes until this is doable.
            // The maximum size mote we can add at this point is cur-1
            req++;
            cur += cur - 1;
          }
          cur += mote[j];
        }
        ans = min(ans, req);
      }
    }
    
    printf("Case #%d: %d\n", tt, ans);
  }
}