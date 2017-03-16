#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

#define ll long long
#define maxn 100

bool isVowel(char c) {
  char s[] = "aeiou";
  return (strchr(s, c) != NULL);
}

void docase(int icase) {
  char s[maxn + 1];
  int n;

  scanf("%s %d", s, &n);

  int len = strlen(s);
  int nvalue = 0;

  for (int i = 0; i <= len - n; i++) {
    for (int j = len - i; j >= n; j--) {
      bool isOk = false;
      int nc = 0;

      for (int k = 0; k < j; k++)
        if (isVowel(s[i + k])) nc = 0;
        else if (++nc >= n) isOk = true;

      nvalue += isOk;
    }
  }

  printf("Case #%d: %d\n", icase, nvalue);
}

int main() {
  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; i++)
    docase(i + 1);

  return 0;
}
