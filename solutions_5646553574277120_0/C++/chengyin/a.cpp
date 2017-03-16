#include <iostream>
#include <vector>

using namespace std;

int64_t solve(int64_t C, vector<int64_t> coins, int64_t V) {
   int64_t index = 0, newCoins = 0, sum = 0, target;
   if (coins[0] > 1) {
      coins.push_back(0);
      for (int i = coins.size() - 1; i > 0; --i)
         coins[i] = coins[i - 1];
      coins[0] = 1; ++newCoins;
   }
   //cout << "======" << endl;
   //for (int i = 0; i < coins.size(); ++i) cout << coins[i] << " "; cout << endl;
   while (index < coins.size()) {
      sum += (coins[index] * C); target = V;
      if ((1 + index) < coins.size() && target >= coins[1 + index]) target = coins[1 + index] - 1;
      //cout << "sum = " << sum << ", target = " << target << endl;
      ++index;
      if (sum < target) {
         coins.push_back(0);
         for (int i = coins.size() - 1; i > index; --i)
            coins[i] = coins[i - 1];
         coins[index] = 1 + sum; ++newCoins;
         // debug
         //cout << "======" << endl;
         //for (int i = 0; i < coins.size(); ++i) cout << coins[i] << " "; cout << endl;
      }
   }
   return newCoins;
}

int main() {
   int T; cin >> T;
   for (int i = 1; i <= T; ++i) {
      int64_t C, D, V; cin >> C >> D >> V;
      vector<int64_t> coins(D);
      for (int j = 0; j < D; ++j) cin >> coins[j];
      cout << "Case #" << i << ": " << solve(C, coins, V) << endl;
   }
   return 0;
}

