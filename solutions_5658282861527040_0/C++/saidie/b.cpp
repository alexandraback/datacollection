#include <iostream>

using namespace std;

int main(void){
  int T;
  cin >> T;
  for(int c = 0; c < T; ++c){
    int A, B, K;
    cin >> A >> B >> K;

    int ans = 0;
    for(int a = 0; a < A; ++a)
      for(int b = 0; b < B; ++b)
        if((a&b) < K)
          ++ans;

    cout << "Case #" << c+1 << ": " << ans << endl;;
  }

  return 0;
}
