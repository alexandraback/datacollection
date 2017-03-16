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

const LL MAX = 5e5;

string s;
vector<LL> val, dp;

LL mat[5][5] = 
  {{0, 0, 0, 0, 0},
   {0, 1, 2, 3, 4},
   {0, 2, -1, 4, -3},
   {0, 3, -4, -1, 2},
   {0, 4, 3, -2, -1}
  };

LL get_mul(LL a, LL b) {
  LL ans = mat[abs(a)][abs(b)];
  if ((a > 0 && b > 0) || (a < 0 && b < 0)) {
    return ans;
  }
  return -1 * ans;
}

LL get_power(LL a, LL b) {
  if (b == 1) {
    return a;
  }
  LL ans = get_power(a, b / 2);
  if (b % 2) {
    ans = get_mul(get_mul(ans, ans), a);
  }
  else {
    ans = get_mul(ans, ans);
  }
  return ans;
}

int main () {
  std::ios::sync_with_stdio(false);
  LL t;
  cin >> t;
  for (LL i = 1; i <= t; i++) {
    LL l, x;
    string ans;
    bool done = false;
    val.clear();
    dp.clear();
    cin >> l >> x >> s;
    dp.resize(min(l * x, MAX));
    for (LL i = 0; i < x && !done; i++) {
      for (LL j = 0; j < l && !done; j++) {
	switch(s[j]) {
	case 'i': val.push_back(2); break;
	case 'j': val.push_back(3); break;
	case 'k': val.push_back(4); break;
	}
	done = (i * l + j >= MAX);
      }
    }
    LL prev = 1;
    for (LL i = 0; i < min(l * x, MAX); i++) {
      dp[i] = get_mul(prev, val[i]);
      prev = dp[i];
    }
    if (get_power(dp[l - 1], x) != -1) {
      ans = "NO";
    }
    else {
      LL i, j;
      for (i = 0; i < min(l * x, MAX); i++) {
	if (dp[i] == 2) {
	  break;
	}
      }
      for (j = i + 1; j < min(l * x, MAX); j++) {
	if (dp[j] == 4) {
	  break;
	}
      }
      ans = (j < min(l * x, MAX) ? "YES" : "NO");
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}
