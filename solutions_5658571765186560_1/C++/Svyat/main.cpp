#include <bits/stdc++.h>
using namespace std;

int T;
int x, r, c;

void load() {
  cin >> x >> r >> c;
}

void solveSmall(int tc) {
  if (r > c) swap(r, c);
  string res = "Svyat";
  if (r * c % x != 0) res = "GABRIEL";
  else if (x == 1) {
    res = "RICHARD";
  } else if (x == 2) {
    if (r * c % x == 0)
      res = "RICHARD";
    else res = "GABRIEL";
  } else if (x == 3) {
    if (r == 1 && c == 3)
      res = "GABRIEL";
    else res = "RICHARD";
  } else {
    if (r >= 3) res = "RICHARD";
    else res = "GABRIEL";
  }
  if (res[0] == 'G') res = "RICHARD";
  else if (res[0] == 'R') res = "GABRIEL";
  else assert(false);
  cout << "Case #" << tc << ": " << res << '\n';
}

void solve(int tc) {
  if (r > c) swap(r, c);
  string res = "Svyat";
  if (r * c % x != 0) res = "GABRIEL";
  else if (x == 1) {
    res = "RICHARD";
  } else if (x == 2) {
    res = "RICHARD";
  } else if (x == 3) {
    if (r < 2)
      res = "GABRIEL";
    else res = "RICHARD";
  } else if (x == 4){
    if (r >= 3) res = "RICHARD";
    else res = "GABRIEL";
  } else if (x == 5) {
    if (r > 2) res = "RICHARD";
    else res = "GABRIEL";
  } else if (x == 6) {
    if (r > 3) res = "RICHARD";
    else res = "GABRIEL";
  } else {
    res = "GABRIEL";
  }
  if (res[0] == 'G') res = "RICHARD";
  else if (res[0] == 'R') res = "GABRIEL";
  else assert(false);
  cout << "Case #" << tc << ": " << res << '\n';
}

void clear() {
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  ios_base::sync_with_stdio(false);
  cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    load();
    solve(tc);
    clear();
  }
  return 0;
}
