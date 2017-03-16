#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

#include <string>
using namespace std;

bool isCant(int num, string s) {
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] != '?') {
      if (num % 10 != s[i] - '0') return true;
    }
    num /= 10;
  }
  return num != 0;
}

int main()
{
  int n;
  
  cin >> n;

  for (int kase = 1; kase <= n; kase++) {
    string coders;
    string jammers;
    cin >> coders >> jammers;

    int minimum = INT_MAX;
    int cnum = 0, jnum = 0;
    for (int i = 0; i < 1000; i++) {
      if (isCant(i, coders)) continue;
      for (int j = 0; j < 1000; j++) {
        if (isCant(j, jammers)) continue;

        if (abs(i - j) < minimum) {
          minimum = abs(i - j);
          cnum = i;
          jnum = j;
        }
      }
    }

    printf("Case #%d: %0*d %0*d\n", kase, coders.length(), cnum, jammers.length(), jnum);
  }

  return 0;
}
