#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

typedef unsigned long long ULL;

inline ULL Rev(ULL input) {
  char buf[100];
  int counter = 0;
  while (input > 0) {
    buf[counter++] = input % 10 + '0';
    input /= 10;
  }
  ULL res = 0;
  for (int i = 0; i < counter; ++i) {
    res = res * 10 + (buf[i] - '0');
  }
  return res;
}
int main() {
  freopen("//Users//zxj//Desktop//poj_input.txt", "r", stdin);
  //freopen("//Users//zxj//Desktop//poj_output1_s.txt", "w", stdout);
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; ++i) {
    ULL N;
    scanf("%llu", &N);
    ULL counter = 0;
    ULL j = 1;
    while (j != N) {
      ULL rev = Rev(j);
      if (rev > j + 1 && rev <= N) {
        j = rev;
      } else {
        ++j;
      }
      ++counter;
    }
    printf("Case #%d: %lld\n", i + 1, counter + 1);
  }
}