#include <bits/stdc++.h>


const int maxn = 3;

int n = 0;
std::string s1 = "", s2 = "";
std::string ts1, ts2;
int adiff;
int coders = -1, jammers = -1;
std::string coderss = "", jammerss = "";

void init () {
  ts1 = s1;
  ts2 = s2;
  adiff = std::numeric_limits<int>::max();
  coders = -1;
  jammers = -1;
  coderss = "";
  jammerss = "";
}

void check () {
  int v1 = 0, v2 = 0;
  for (int i = 0 ; i < n ; i += 1) {
    v1 = (v1 * 10) + (ts1[i] - '0');
    v2 = (v2 * 10) + (ts2[i] - '0');
  }
  int diff = std::abs(v1 - v2);
  // std::cout << "here" << " " << ts1 << " " << v1 << " " << ts2 << " " << diff << '\n';
  if (diff < adiff || (diff == adiff && v2 < jammers)) {
    adiff = diff;
    coders = v1;
    jammers = v2;
    coderss = ts1;
    jammerss = ts2;
  }
}

void iterate (const std::string& s, int p, bool second) {
  if (p >= n) {
    if (second) check();
    else iterate(s2, 0, true);
    return ;
  }

  if (s[p] != '?') iterate(s, p + 1, second);
  else {
    for (char c = '0' ; c <= '9' ; c += 1) {
      // std::cout << second << " " << p << " " << c << '\n';
      if (second) ts2[p] = c;
      else ts1[p] = c;
      iterate(s, p + 1, second);
    }
  }
}

void solution () {
  std::cin >> s1 >> s2;
  std::cin.ignore(10000, '\n');

  n = s1.size();
  init();

  iterate(s1, 0, false);

  std::cout << coderss << " " << jammerss << '\n';
}

int main () {
  // std::ios_base::sync_with_stdio(false);

  // std::freopen("x.in", "r", stdin);
  std::freopen("B-small-attempt0.in", "r", stdin);
  // std::freopen("B-large.in", "r", stdin);

  std::freopen("B.out", "w", stdout);

  int T = 0;
  std::cin >> T;
  std::cin.ignore(10000, '\n');
  for (int i = 1 ; i <= T ; i += 1) {
    std::cout << "Case #" << i << ": ";
    solution();
  }

  return 0;
}
