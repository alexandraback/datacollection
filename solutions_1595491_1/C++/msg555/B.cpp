#include <iostream>

using namespace std;

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int N, S, p; cin >> N >> S >> p;
    int hs = 3 * (p - 1) + 1;
    int ls = 3 * p - 4;
    if(p <= 1) ls = hs = p;

    int res = 0;
    for(int i = 0; i < N; i++) {
      int x; cin >> x;
      if(x >= hs) res++;
      else if(x >= ls && S-- > 0) res++;      
    }
    cout << "Case #" << t << ": " << res << endl;
  }
}
