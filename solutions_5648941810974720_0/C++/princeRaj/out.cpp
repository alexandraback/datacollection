#include <cstdio>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <bitset>
#include <list>
#include <set>
#include <map>

using namespace std;

const int N = 100010;

char s[N];
int cnt[26];
int x[10] = {8, 0, 2, 6, 7, 5, 4, 1, 9, 3};

int main() {
  freopen("input.in", "r", stdin);
  freopen("output.out", "w", stdout);
  int test;
  scanf("%d", &test);
  for (int t = 1; t <= test; t++) {
    scanf("%s", s);
    int los = strlen(s);
    for (int i = 0; i < los; i++) {
      cnt[s[i] - 'A']++;
    }
    map <int, string> m;
    m[0] = "ZERO";
    m[1] = "ONE";
    m[2] = "TWO";
    m[3] = "THREE";
    m[4] = "FOUR";
    m[5] = "FIVE";
    m[6] = "SIX";
    m[7] = "SEVEN";
    m[8] = "EIGHT";
    m[9] = "NINE";
    vector <int> res;
    printf("Case #%d: ", t);
    for (int ii = 0; ii <= 9; ii++) {
      int i = x[ii];
      string z = m[i];
      int ctr = los;
      for (int j = 0; j < z.length(); j++) {
        ctr = min(ctr, cnt[z[j] - 'A']);
      }
      for (int k = 0; k < ctr; k++) {
        res.push_back(i);
      }
      for (int j = 0; j < z.length(); j++) {
        cnt[z[j] - 'A'] -= ctr;
      }
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < (int)res.size(); i++) {
      printf("%d", res[i]);
    }
    putchar('\n');
    memset(cnt, 0, sizeof cnt);
  }
}
