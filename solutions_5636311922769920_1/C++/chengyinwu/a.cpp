#include <iostream>
#include <vector>

using namespace std;

vector<uint64_t> sol(uint64_t k, uint64_t c) {
   vector<uint64_t> a; a.clear();
   if (k == 1) a.push_back(1);
   else if (c == 1) for (uint64_t i = 1; i <= k; ++i) a.push_back(i);
   else {
      vector<uint64_t> lastSol = sol(k - 1, c - 1); a = sol(k - 1, c - 1);
      for (uint64_t i = 0; i < a.size(); ++i) a[i] += ((k * lastSol[0]) + 1 - k);
   }
   return a;
}

void print(uint64_t K, uint64_t C, uint64_t S) {
   vector<uint64_t> result = sol(K, (C > K) ? K : C);
   if (result.size() > S) { cout << " IMPOSSIBLE"; return; }
   for (uint64_t i = 0; i < result.size(); ++i) cout << " " << result[i];
}

int main() {
   uint64_t T; cin >> T;
   for (uint64_t i = 1; i <= T; ++i) {
      uint64_t K, C, S; cin >> K >> C >> S;
      cout << "Case #" << i << ":";
      print(K, C, S);
      cout << endl;
   }
   return 0;
}

