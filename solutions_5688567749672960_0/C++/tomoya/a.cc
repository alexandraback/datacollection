#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define lli long long int

void replace(vector<int> &memo, int pos, int num) {
  if (memo[pos] == -1) {
    memo[pos] = num;
  } else {
    memo[pos] = min(memo[pos], num);
  }
}

int main () {
  int T; cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    lli num; cin >> num;
    vector<int> memo = vector<int>(num + 1, -1);

    memo[1] = 1;
    for (int i = 1; i < num; i++) {
      int cost = memo[i];
      replace(memo, i + 1, cost + 1);

      stringstream ss;
      string str;
      ss << i;
      ss >> str;
      reverse(str.begin(), str.end());
      ss.str("");
      ss.clear();
      ss << str;
      lli val; ss >> val;
      if (val <= num) {
	replace(memo, val, cost + 1);
      }
    }

    cout << "Case #" << tc << ": " << memo[num] << endl;
  }
  return 0;
}
