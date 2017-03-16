#include <cstdio>
#include <cassert>
#include <string>
#include <algorithm>
#define scanf(args...) (scanf(args) ? : 0)
typedef long long int LL;
const int MAXN = 1e6;

char buffer1[MAXN], buffer2[MAXN];

int power(int a, int b) {
  int r = 1;
  for (int i = 0; i < b; i++)
    r *= a;
  return r;
}

bool match(LL t, std::string str) {
  for (int i = str.size() - 1; i >= 0; i--) {
    if (str[i] != '?' && t % 10 != str[i] - '0')
      return false;
    t /= 10;
  }
  return true;
}


std::string to_string(LL a, int n) {
  std::string p;
  for (int i = 0; i < n; i++) {
    p += (a % 10) + '0';
    a /= 10;
  }
  std::reverse(p.begin(), p.end());
  return p;
}

std::pair<std::string, std::string> brute_solve(std::string str1, std::string str2) {
  assert(str1.length() == str2.length());
  int n = str1.length();
  int max = power(10, n);
  int best_diff = MAXN, a = -1, b = -1;
  for (int i = 0; i < max; i++)
    for (int j = 0; j < max; j++)
      if (match(i, str1) && match(j, str2)) {
        if (std::abs(i - j) < best_diff) {
          a = i;
          b = j;
          best_diff = std::abs(i - j);
        }
      }

  return {
    to_string(a, n),
    to_string(b, n)
  };
}

std::string maximize(std::string str) {
  std::string result;
  for (char t : str)
    if (t == '?')
      result += '9';
    else
      result += t;
  return result;
}

std::string minimize(std::string str) {
  std::string result;
  for (char t : str)
    if (t == '?')
      result += '0';
    else
      result += t;
  return result;
}

bool better(std::pair<std::string, std::string> f1, std::pair<std::string, std::string> f2) {
  LL a1 = atoll(f1.first.c_str()), b1 = atoll(f1.second.c_str());
  LL a2 = atoll(f2.first.c_str()), b2 = atoll(f2.second.c_str());

  if (std::abs(a1 - b1) == std::abs(a2 - b2)) {
    if (a1 == a2)
      return b1 < b2;
    return a1 < a2;
  }
  return std::abs(a1 - b1) < std::abs(a2 - b2);
}

std::pair<std::string, std::string> generate(const std::string& t1,
                                             const std::string& t2, int i) {
  std::string r1(t1.begin(), t1.begin() + i + 1);
  std::string r2(t2.begin(), t2.begin() + i + 1);
  if (t1[i] < t2[i]) {
    r1 += maximize(std::string(t1.begin() + i + 1, t1.end()));
    r2 += minimize(std::string(t2.begin() + i + 1, t2.end()));
  } else {
    r1 += minimize(std::string(t1.begin() + i + 1, t1.end()));
    r2 += maximize(std::string(t2.begin() + i + 1, t2.end()));
  }
  return { r1, r2 };
}

std::pair<std::string, std::string> solve(std::string str1, std::string str2) {
  int n = str1.length();
  std::pair<std::string, std::string> result = generate(str1, str2, -1);
  for (int i = 0; i < n; i++) {
    std::string t1 = str1, t2 = str2;
    if (t1[i] != '?' && t2[i] != '?') {
      if (t1[i] != t2[i]) {
        auto t = generate(t1, t2, i);
        if (better(t, result))
          result = t;
        return result;
      }
    } else if (t1[i] == '?' && t2[i] != '?') {
      t1[i] = (t2[i] - '0' + 1) % 10 + '0';
      auto t = generate(t1, t2, i);
      if (better(t, result))
        result = t;

      t1[i] = (t2[i] - '0' - 1 + 10) % 10 + '0';
      t = generate(t1, t2, i);
      if (better(t, result))
        result = t;

      t1[i] = t2[i];
      t = generate(t1, t2, i);
      if (better(t, result))
        result = t;

      str1[i] = str2[i];
    } else if (t1[i] != '?' && t2[i] == '?') {
      t2[i] = (t1[i] - '0' + 1) % 10 + '0';
      auto t = generate(t1, t2, i);
      if (better(t, result))
        result = t;

      t2[i] = (t1[i] - '0' - 1 + 10) % 10 + '0';
      t = generate(t1, t2, i);
      if (better(t, result))
        result = t;

      t2[i] = t1[i];
      t = generate(t1, t2, i);
      if (better(t, result))
        result = t;

      str2[i] = str1[i];
    } else {
      for (int i1 = '0'; i1 <= '1'; i1++)
        for (int i2 = '0'; i2 <= '1'; i2++) {
          t1[i] = i1;
          t2[i] = i2;
          auto t = generate(t1, t2, i);
          if (better(t, result))
            result = t;
        }
      str1[i] = '0';
      str2[i] = '0';
    }
  }

  return result;
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 1; i <= t; i++) {
    scanf("%s%s", buffer1, buffer2);
    auto r = solve(buffer1, buffer2);
    //auto r2 = brute_solve(buffer1, buffer2);
    //assert(r == r2);
    printf("Case #%d: %s %s\n", i, r.first.c_str(), r.second.c_str());
  }
}
