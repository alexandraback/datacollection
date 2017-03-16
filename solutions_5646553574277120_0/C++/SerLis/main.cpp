#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

int Zf(const string& str) {
  vector<int> result;
  result.push_back(str.size());
  int last_vatched = 1, best_posishon = 0;
  for (int iter = 1; iter < str.size(); ++iter) {
    int cur_result = 0;
    if (last_vatched > iter) {
      int analog = iter - best_posishon;
      if (last_vatched - iter != result[analog]) {
        result.push_back(std::min(result[analog], last_vatched - iter));
        continue;
      } else {
        cur_result = result[analog];
      }
    } else {
      last_vatched = iter;
    }
    while (str[last_vatched] == str[last_vatched - iter]) {
      cur_result++;
      last_vatched++;
      best_posishon = iter;
    }
    result.push_back(cur_result);
  }
  int postf = str.size();
  for (int i = 1; i < str.size(); ++i ) {
    if (result[i] == str.size() - i) {
      return i;
    }
  }
  return postf;
}

int main() {
  freopen("input", "r", stdin);
  freopen("output", "w", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) { 
    int c, d, v;
    cin >> c >> d >> v;
    vector<int> coins(d);
    for (int i = 0; i < d; ++i) { 
      cin >> coins[i];
    }
    int res = 0, paid = 1, cur_coin = 0;
    while (paid <= v) {
      if (cur_coin < d && coins[cur_coin] <= paid) {
        paid += c * coins[cur_coin];
        cur_coin++;
      } else {
        res++;
        paid += c * paid;
      }
    }

    cout << "Case #" << t << ": ";
    cout << res << "\n";
  }
}
