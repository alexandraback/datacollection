#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#define WHAT_IS(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long LL;

const int MAX = 10002;

string s;
vector<int> val, dp;

int mat[5][5] = 
  {{0, 0, 0, 0, 0},
   {0, 1, 2, 3, 4},
   {0, 2, -1, 4, -3},
   {0, 3, -4, -1, 2},
   {0, 4, 3, -2, -1}
  };

int get_mul(int a, int b) {
  int ans = mat[abs(a)][abs(b)];
  if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
    return ans;
  }
  return -1 * ans;
}

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int l, x;
    string ans;
    val.clear();
    dp.clear();
    cin >> l >> x >> s;
    dp.resize(l * x);
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < l; j++) {
	switch(s[j]) {
	case 'i': val.push_back(2); break;
	case 'j': val.push_back(3); break;
	case 'k': val.push_back(4); break;
	}
      }
    }
    int prev = 1;
    for (int i = 0; i < l * x; i++) {
      dp[i] = get_mul(prev, val[i]);
      prev = dp[i];
    }
    if (dp[l * x - 1] != -1) {
      ans = "NO";
    }
    else {
      int i, j;
      for (i = 0; i < l * x; i++) {
	if (dp[i] == 2) {
	  break;
	}
      }
      for (j = i + 1; j < l * x; j++) {
	if (dp[j] == 4) {
	  break;
	}
      }
      ans = (j < l * x ? "YES" : "NO");
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}
