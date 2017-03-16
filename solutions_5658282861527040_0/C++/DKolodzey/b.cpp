#include <iostream>
using namespace std;

int main(){
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int A, B, K;
    cin >> A >> B >> K;
    int ans = 0;
    for (int i = 0; i < A; ++i)
      for (int j = 0; j < B; ++j)
        if ((j & i) < K)
          ++ans;
    cout << "case #" << test << ": " << ans << endl;
  }
  return 0;
}