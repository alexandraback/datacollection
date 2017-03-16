#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cmath>
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

void Part(ULL input, ULL& n1, ULL& n2, int& counter) {
  ULL temp = input;
  counter = 0;
  while (temp > 0) {
    temp /= 10;
    ++counter;
  }
  temp = 1;
  for (int i = 0; i < (counter + 1) / 2; ++i) {
    temp *= 10;
  }
  n2 = input % temp;
  n1 = input / temp;
}

ULL Count(ULL input) {
  if (input <= 10) {
    return input;
  } else {
    ULL n1 = 0;
    ULL n2 = 0;
    int bit = 0;
    Part(input, n1, n2, bit);
    if (n2 < 1) {
      return Count(input - 1) + 1;
    }
    ULL rev = Rev(n1);
    ULL count1 = n2 - 1 + rev + 1;
    if (rev != 1) {
      count1 += 1;
    }
    ULL res = 9;
    for (int i = 0; i < bit - 2; ++i) {
      res = res * 10 + 9;
    }
    return Count(res) + count1;
  }
}

int main() {
  freopen("//Users//zxj//Desktop//poj_input.txt", "r", stdin);
  //freopen("//Users//zxj//Desktop//poj_output1_s.txt", "w", stdout);
  int cases;
  scanf("%d", &cases);
 // cout << dp[99] << endl;
  for (int i = 0; i < cases; ++i) {
    ULL N;
    scanf("%llu", &N);
    printf("Case #%d: %lld\n", i + 1, Count(N));
  }
}