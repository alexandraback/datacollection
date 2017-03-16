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
const int MOD = 1e9 + 7;
const int INF = 1e9;

string arr[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    printf("Case #%d: ", ti);
    string s;
    cin >> s;
    int f[26] = {}, ans[10] = {};
    for (int i = 0; i < (int)s.length(); ++i) {
      f[s[i] - 'A']++;
    }
    ans[6] = f['X' - 'A'];
    ans[0] = f['Z' - 'A'];
    ans[2] = f['W' - 'A'];
    ans[8] = f['G' - 'A'];
    ans[7] = f['S' - 'A'] - ans[6];
    ans[5] = f['V' - 'A'] - ans[7];
    ans[9] = (f['I' - 'A'] - ans[6] - ans[5] - ans[8]);
    ans[4] = (f['F' - 'A'] - ans[5]);
    ans[3] = (f['R' - 'A'] - ans[4] - ans[0]);
    ans[1] = (f['N' - 'A'] - 2 * ans[9] - ans[7]);
    int g[26] = {};
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < (int)arr[i].length(); ++j) {
        g[arr[i][j] - 'A'] += ans[i];
      }
    }
    for (int i = 0; i < 26; ++i) {
      if (f[i] != g[i]) {
        throw;
      }
    }
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < ans[i]; ++j) {
        printf("%d", i);
      }
    }
    printf("\n");
  }
  return 0;
}
