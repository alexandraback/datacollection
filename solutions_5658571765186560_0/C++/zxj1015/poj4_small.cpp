//
//  main.cpp
//  pojcode
//
//  Created by zxj on 15/02/21.
//  Copyright (c) 2015年 Shanghai Jiao Tong University. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;

int Process(int x, int r, int c) {
  if (x == 1) {
    return 2;
  }
  if (x == 2) {
    if (r % 2 == 0 || c % 2 == 0) {
      return 2;
    }
    return 1;
  }
  if (x == 3) {
    if (r == 1) {
      return 1;
    }
    if (r == 2) {
      if (c == 3) {
        return 2;
      }
      return 1;
    }
    if (r == 3) {
      switch(c) {
        case 1:
          return 1;
        default:
          return 2;
      }
    }
    if (r == 4) {
      if (c == 3) {
        return 2;
      }
      return 1;
    }
  }
  if (x == 4) {
    if (r <= 2) {
      return 1;
    }
    if (r == 3) {
      return Process(x, c, r);
    }
    if (r == 4) {
      if (c <= 2) {
        return 1;
      }
      return 2;
    }
  }
  return -1;
}


int main() {
 // freopen("//Users/zxj//Desktop//poj_input.txt", "r", stdin);
 // freopen("//Users/zxj//Desktop//poj_outputbig.txt", "w", stdout);
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; ++i) {
    int X, R, C;
    scanf("%d %d %d", &X, &R, &C);
    int flag = Process(X, R, C);
    printf("Case #%d: %s\n", i + 1, flag == 1 ? "RICHARD" : "GABRIEL");
  }
}
