#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <set>


using namespace std;

#define PI acos(-1.)
#define EPS 1e-7
#define LL long long
#define U unsigned int
#define LU long unsigned
#define LLU long long unsigned


int solve(int ind, vector<int> &coins) {
  if (ind == 0) {
    if (coins[ind] != 1) {
      return 1;
    } else {
      return 0;
    }
  }

  int res = 0;
  res += solve(ind - 1, coins);
  int prev;
  if (ind == 1) prev = 1;
  else prev = coins[ind - 1];
  while(prev*2 < coins[ind]) {
    prev*=2;
    ++res;
  }
  return res;
}

int main() {
  // Declare members
  int num_case;
  cin >> num_case;

  int C, D, V;
  vector<int> coins;

  for (int nc = 1; nc <= num_case; ++nc) {
    // Init members
    cin >> C >> D >> V;
    coins.clear();
    coins.resize(D);

    for (int i = 0; i < D; ++i) {
      cin >> coins[i];
    }

    int res = solve(coins.size() - 1, coins);
    int prev = coins[coins.size() - 1];
    while (2*prev <= V) {
      prev*=2;
      ++res;
    }

    // Print output for case j
    cout << "Case #" << nc << ": " << res << endl;
  }


  return 0;
}
