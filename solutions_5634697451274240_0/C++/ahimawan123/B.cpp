#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main() {
  int cases;
  string s;
  cin >> cases;
  for (int n = 1; n <= cases; n++) {
    cin >> s;
    s += "+";
    int len = s.length();
    int ans = 0;
    for (int i = 1; i < len; i++) {
      if (s[i-1] != s[i]) ans++;
    }
    printf("Case #%d: %d\n", n, ans);
  }
  return 0;
}
