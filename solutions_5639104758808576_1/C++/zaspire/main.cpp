#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
  int T;
  cin >> T;
  for (int TT = 0; TT < T; TT++) {
    int SMax;
    string s;
    cin >> SMax >> s;
    int res = 0, sum = 0;
    for (int i = 0; i < s.size(); i++) {
      if (i > sum) {
        res += i - sum;
        sum = i;
      }
      sum += s[i] - '0';
    }
    cout << "Case #" << TT + 1 << ": " << res << endl;
  }
  return 0;
}
