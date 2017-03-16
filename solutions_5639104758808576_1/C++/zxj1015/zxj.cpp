//
//  main.cpp
//  pojcode
//
//  Created by zxj on 15/02/21.
//  Copyright (c) 2015Äê Shanghai Jiao Tong University. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;


int main() {
  //freopen("//Users/zxj//Desktop//poj_input.txt", "r", stdin);
  int cases;
  scanf("%d", &cases);
  char buf[2000];
  for (int i = 0; i < cases; ++i) {
    int N;
    scanf("%d %s", &N, buf);
    int counter = 0;
    int res = 0;
    for (int j = 0; j <= N; ++j) {
      if (counter < j) {
        res += j - counter;
        counter = j;
      }
      counter += buf[j] - '0';
    }
    printf("Case #%d: %d\n", i + 1, res);
  }
}
