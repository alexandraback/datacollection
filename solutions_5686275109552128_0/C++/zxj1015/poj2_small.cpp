//
//  main.cpp
//  pojcode
//
//  Created by zxj on 15/02/21.
//  Copyright (c) 2015骞?Shanghai Jiao Tong University. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;


int main() {
	//freopen("C:\\Users\\zxj\\Desktop\\POJ\\input.txt","r" ,stdin);
	//	freopen("C:\\Users\\zxj\\Desktop\\POJ\\output.txt","w" ,stdout);

  int cases;
  scanf("%d", &cases);
  int data[1010];
  for (int i = 0; i < cases; ++i) {
    int N;
    scanf("%d", &N);
    int max_t = 0;
    for (int j = 0; j < N; ++j) {
      scanf("%d", &data[j]);
      if (data[j] > max_t) {
        max_t = data[j];
      }
    }
    if (max_t <= 3) {
      printf("Case #%d: %d\n", i + 1, max_t);
      continue;
    }
    int min_value = 20000;
    for (int j = 1; j <= max_t; ++j) {
      int cur_time = j;
      for (int k = 0; k < N; ++k) {
        int temp = (data[k] % j == 0) ? (data[k] / j - 1) : (data[k] / j);
        temp = temp > 0 ? temp : 0;
        cur_time += temp;
      }
      if (cur_time < min_value) {
        min_value = cur_time;
      }
    }
    printf("Case #%d: %d\n", i + 1, min_value);
  }
}