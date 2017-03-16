#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for (int i = (a); i < int(b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

#define fst first
#define snd second

typedef long long llint;
typedef pair<int, int> pii;

const int B = 27397, MOD = 1e9 + 7;
const int B1 = 33941, MOD1 = 1e9 + 9;

int T, len1, len2;

char s1[10], s2[10];

void solve(int t) {
  
}

bool check(int a, int b) {
  for (int i = len1 - 1; i >= 0; --i) {
    if (s1[i] != '?' && a % 10 != s1[i] - '0') return false;
    if (s2[i] != '?' && b % 10 != s2[i] - '0') return false; 
    a /= 10; b /= 10;
  }
  return a == 0 && b == 0; 
}

void print(int a, char *s) {
  for (int i = len1 - 1; i >= 0; --i) {
    if (s[i] == '?') 
      s[i] = '0' + (a % 10);
    a /= 10;
  }
  printf("%s", s);
}

void small(int t) {

  scanf("%s%s", s1, s2);
  len1 = strlen(s1);
  len2 = strlen(s2);

  int a = 0, b = 10000;

  for (int i = 0; i < 1000; ++i) {
    for (int j = 0; j < 1000; ++j) {
      if (!check(i, j)) continue;
      if (abs(i - j) < abs(a - b)) {
        a = i;
        b = j;
      }
    }
  }

  printf("Case #%d: ", t);
  print(a, s1); printf(" ");
  print(b, s2); printf("\n");

}

int main(void) {

  scanf("%d", &T);
  for (int t = 0; t < T; ++t) 
    small(t + 1);  

  return 0;

}

