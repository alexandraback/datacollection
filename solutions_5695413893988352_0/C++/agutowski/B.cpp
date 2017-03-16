#include <iostream>
using namespace std;
using LL = long long;
const int N = 20;
int n;
LL pow[N];
string a, b;
int min_val(char c) { return (c == '?' ? 0 : c-'0'); }
int max_val(char c) { return (c == '?' ? 9 : c-'0'); }
using Res = pair<LL, pair<string, string>>;
Res cache_abs[N], cache_min[N], cache_max[N];
bool cached_abs[N], cached_min[N], cached_max[N];
Res add(int a, int b, Res x) {
  int len = x.second.first.length();
  LL val = pow[len] * (a - b) + x.first;
  string first = char(a+'0') + x.second.first;
  string second = char(b+'0') + x.second.second;
  return {val, {first, second}};
}
Res min_abs(const Res &a, const Res &b) {
  LL aa = abs(a.first), ab = abs(b.first);
  if (aa < ab) return a;
  if (aa > ab) return b;
  return (a.second < b.second ? a : b);
}
Res min_diff(int);
Res max_diff(int);
Res abs_diff(int i) {
  if (i == n) return {0, {"", ""}};
  if (!cached_abs[i]) {
    if (a[i] == '?' && b[i] == '?') {
      Res r = add(0, 0, abs_diff(i+1));
      r = min_abs(r, add(0, 1, max_diff(i+1)));
      r = min_abs(r, add(1, 0, min_diff(i+1)));
      cache_abs[i] = r;
    } else if (a[i] == '?') {
      int dig = b[i]-'0';
      Res r = add(dig, dig, abs_diff(i+1));
      if (dig > 0) r = min_abs(r, add(dig-1, dig, max_diff(i+1)));
      if (dig < 9) r = min_abs(r, add(dig+1, dig, min_diff(i+1)));
      cache_abs[i] = r;
    } else if (b[i] == '?') {
      int dig = a[i]-'0';
      Res r = add(dig, dig, abs_diff(i+1));
      if (dig > 0) r = min_abs(r, add(dig, dig-1, min_diff(i+1)));
      if (dig < 9) r = min_abs(r, add(dig, dig+1, max_diff(i+1)));
      cache_abs[i] = r;
    } else if (a[i] == b[i])
      cache_abs[i] = add(a[i]-'0', b[i]-'0', abs_diff(i+1));
    else if (a[i] > b[i])
      cache_abs[i] = add(a[i]-'0', b[i]-'0', min_diff(i+1));
    else
      cache_abs[i] = add(a[i]-'0', b[i]-'0', max_diff(i+1));
    cached_abs[i] = true;
  }
  return cache_abs[i];
}
Res min_diff(int i) {
  if (i == n) return {0, {"", ""}};
  if (!cached_min[i]) {
    cache_min[i] = add(min_val(a[i]), max_val(b[i]), min_diff(i+1));
    cached_min[i] = true;
  }
  return cache_min[i];
}
Res max_diff(int i) {
  if (i == n) return {0, {"", ""}};
  if (!cached_max[i]) {
    cache_max[i] = add(max_val(a[i]), min_val(b[i]), max_diff(i+1));
    cached_max[i] = true;
  }
  return cache_max[i];
}

int main() {
  ios_base::sync_with_stdio(0);
  pow[0] = 1;
  for (int i=1; i<N; i++) pow[i] = 10 * pow[i-1];
  int T;
  cin >> T;
  for (int t=1; t<=T; t++) {
    cout << "Case #" << t << ": ";
    cin >> a >> b;
    n = a.length();
    for (int i=0; i<n; i++) cached_abs[i] = cached_min[i] = cached_max[i] = 0;
    Res r = abs_diff(0);
    cout << r.second.first << " " << r.second.second << "\n";
  }
  return 0;
}
