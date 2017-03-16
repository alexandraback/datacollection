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

typedef long long LL;


int mat[4][4] = {
  {1, 2, 3, 4},
  {2, -1,4, -3},
  {3, -4, -1, 2},
  {4, 3, -2, -1}
};

int GetRes(int res, LL X) {
  if (res == 1) {
    return 1;
  }
  if (res == -1) {
    return X % 2 == 0 ? 1 : -1;
  }
    if (X % 4 == 0) {
      return 1;
    }
    if (X % 4 == 1) {
      return res;
    }
    if (X % 4 == 2) {
      return -1;
    }
    if (X % 4 == 3) {
      return -res;
    }
  return -100000;
}

int Cal(const char* buf, int N) {
  int res = 1;
  int first_of_i = -1;
  for (int i = 0; i < N; ++i) {
    int row = res > 0 ? res : -res;
    int col = 2;
    if (buf[i] == 'j') {
      col = 3;
    } else if (buf[i] == 'k') {
      col = 4;
    }
    res = (res / row) * mat[row - 1][col - 1];
    if (res == 2 && first_of_i < 0) {
      first_of_i = i;
    }
  }
  return res;
}

int main() {
 // freopen("//Users/zxj//Desktop//poj_input.txt", "r", stdin);
 // freopen("//Users/zxj//Desktop//poj_outputbig.txt", "w", stdout);
  int cases;
  char buf[110000];
  scanf("%d", &cases);
  for (int i = 0; i < cases; ++i) {
    LL N, X;
    scanf("%lld %lld", &N, &X);
    scanf("%s", buf);
    int myres = Cal(buf, (int)(N));
    LL l = X > 10LL ? 10LL : X;
    for (int j = 1; j < l; ++j) {
      for (int k = 0; k < N; ++k) {
        buf[j * N + k] = buf[k];
      }
    }
    buf[l * N] = '\0';
   //     cout << buf << endl;
   // cout << buf << endl;
    int res = 1;
    int first_of_i = -1;
    for (int i = 0; i < l * N; ++i) {
      int row = res > 0 ? res : -res;
      int col = 2;
      if (buf[i] == 'j') {
        col = 3;
      } else if (buf[i] == 'k') {
        col = 4;
      }
      res = (res / row) * mat[row - 1][col - 1];
      if (res == 2 && first_of_i < 0) {
        first_of_i = i;
      }
    }
    int bak_res = 1;
    int first_of_k = -1;
    for (int i = (int)(l * N) - 1; i >= 0; --i) {
      int col = bak_res > 0 ? bak_res : -bak_res;
      int row = 2;
      if (buf[i] == 'j') {
        row = 3;
      } else if (buf[i] == 'k') {
        row = 4;
      }
      bak_res = (bak_res / col) * mat[row - 1][col - 1];
      if (bak_res == 4 && first_of_k < 0) {
        first_of_k = i;
      }
    }
    //cout << res << "===" << first_of_i << "===" << first_of_k << endl;
    res = GetRes(myres, X);
    if (res == -1 && first_of_i >= 0 &&
        first_of_k >= 0 && first_of_i + 1 < first_of_k) {
      printf("Case #%d: YES\n", i + 1);
    } else {
      printf("Case #%d: NO\n", i + 1);
    }
  }
}
