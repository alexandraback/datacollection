#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-7

string s1, s2;
int total = 0;
int k, l, s;
int maxBanana;
double expectedBananaGiven;

int checkWord(string st) {
  int ret = 0;
  for (int i = 0; i <= st.length() - s2.length(); i++) {
    bool can = true;
    for (int j = i; j <= i+s2.length()-1; j++) {
      if (st[j] != s2[j-i]) {
        can = false;
        break;
      }
    }
    if (can) ret++;
  }
  return ret;
}

void bruteforce(string st, double now) {
  if (st.length() == s) {
    int count = checkWord(st);
    maxBanana = max(maxBanana, count);
    expectedBananaGiven += (double)count * now;
    return;
  }
  for (int i = 0; i < s1.length(); i++) {
    bruteforce(st + s1[i], now * (1.0/(double)k));
  }
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tc = 1; tc <= T; tc++) {
    expectedBananaGiven = 0.0;
    maxBanana = 0;
    scanf("%d %d %d", &k, &l, &s);
    cin >> s1;
    cin >> s2;
    bruteforce("", 1);
    printf("Case #%d: %.7lf\n", tc, (double)maxBanana - expectedBananaGiven);
  }
  return 0;
}
