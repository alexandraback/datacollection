#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int k,l,s;
string key, target;
int cc[200];
int note[10][10];
double mem[10][10];

double dp(int n, int d) {
  if (note[n][d]) return mem[n][d];
  if (n == s) {
    if (d == l) {
      return 1;
    }
    return 0;
  }
  double ans = 0;
  int p = 0;
  if (d == l) {
    for (int i = n-d+1; i < l; i++) {
      if (target[i] == target[p]) {
        p++;
      } else {
        p = 0;
      }
    }
    ans = 1;
    d = p;
  }
  for (int i = 0; i < k; i++) {
    if (key[i] == target[d]) {
      ans += dp(n+1, d+1)/k;
    } else {
      ans += dp(n+1, 0)/k;
    }
  }
  mem[n][d] = ans;
  note[n][d] = 1;
  return ans;
}

int main() {
  int tt;
  cin >> tt;
  for (int t = 1; t <= tt; t++) {
    cin >> k >> l >> s;
    cin >> key >> target;
    memset(cc, 0, sizeof cc);
    memset(note, 0, sizeof note);
    for (int i = 0; i < key.size(); i++) {
      cc[key[i]]++;
    }
    bool done = false;
    for (int i = 0; i < target.size(); i++) {
      if (!cc[target[i]]) {
        done = true;
        break;
      }
    }
    if (!done) printf("Case #%d: %.6lf\n", t, s-l+1-dp(0,0));
    else printf("Case #%d: 0.0\n", t);
  }
}