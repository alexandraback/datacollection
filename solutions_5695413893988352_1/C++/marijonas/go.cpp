#include <cstdio>
#include <string>
#include <iostream>

using namespace std;


long long bestdiff = -1;
string bestc, bestj;

long long convert(const char* a) {
  long long x = 0;
  while (*a) {
    x = x * 10 + (*a - '0');
    a++;
  }
  return x;
}

void check(string coders, string jammers) {
  long long diff = abs(convert(coders.c_str()) - convert(jammers.c_str()));
  if (bestdiff == -1 || diff < bestdiff ||
      (diff == bestdiff && (coders < bestc || (coders == bestc && jammers < bestj)))) {
    bestdiff = diff;
    bestc = coders;
    bestj = jammers;
  }
}

// mode: 0 - prefix is same
// 1 - min a, max b
// 2 - max a, min b

void go(string a, string b, int i, int mode) {
  if (i == a.length()) {
    check(a, b);
    return;
  }
  if (mode > 0) {
    if (a[i] == '?') a[i] = (mode == 1) ? '0' : '9';
    if (b[i] == '?') b[i] = (mode == 1) ? '9' : '0';
    go(a, b, i+1, mode);
    return;
  }
  if (a[i] == '?' && b[i] == '?') {
    a[i] = '0'; b[i] = '0';
    go(a, b, i+1, 0);
    a[i] = '1'; b[i] = '0';
    go(a, b, i+1, 1);
    a[i] = '0'; b[i] = '1';
    go(a, b, i+1, 2);
  }
  else if (a[i] != '?' && b[i] != '?') {
    if (a[i] < b[i])
      go(a, b, i+1, 2);
    else if (a[i] > b[i])
      go(a, b, i+1, 1);
    else
      go(a, b, i+1, 0);
  }
  else if (a[i] == '?') {
    a[i] = b[i];
    go(a, b, i+1, 0);
    if (b[i] < '9') {
      a[i] = b[i] + 1;
      go(a, b, i+1, 1);
    }
    if (b[i] > '0') {
      a[i] = b[i] - 1;
      go(a, b, i+1, 2);
    }
  } else {
    b[i] = a[i];
    go(a, b, i+1, 0);
    if (a[i] < '9') {
      b[i] = a[i] + 1;
      go(a, b, i+1, 2);
    }
    if (a[i] > '0') {
      b[i] = a[i] - 1;
      go(a, b, i+1, 1);
    }
  }
}

void solve(string &coders, string &jammers) {
  bestdiff = -1;

  go(coders, jammers, 0, 0);

  coders = bestc;
  jammers = bestj;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    string c, j;
    cin >> c >> j;
    solve(c, j);
    printf("Case #%d: %s %s\n", i, c.c_str(), j.c_str());
  }
  return 0;
}