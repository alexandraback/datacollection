#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 10;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int it = 1; it <= t; ++it) {
    int n;
    printf("Case #%d: ", it);
    string s;
    cin >> s;
    vector < char > sy;
    for (int i = 0, j; i < (int)s.length(); i = j) {
      for (j = i; j < (int)s.length() && s[j] == s[i]; ++j);
      sy.push_back(s[i]);
    }
    if (sy.back() == '-') {
      printf("%d\n", (int)sy.size());
    } else {
      printf("%d\n", (int)sy.size() - 1);
    }
  }
  return 0;
}

