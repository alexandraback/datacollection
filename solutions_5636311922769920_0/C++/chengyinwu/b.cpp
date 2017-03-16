#include <iostream>
#include <vector>

using namespace std;

int main() {
   uint64_t T; cin >> T;
   for (uint64_t i = 1; i <= T; ++i) {
      uint64_t K, C, S; cin >> K >> C >> S;
      cout << "Case #" << i << ":";
      for (uint64_t i = 1; i <= K; ++i) cout << " " << i;
      cout << endl;
   }
   return 0;
}

