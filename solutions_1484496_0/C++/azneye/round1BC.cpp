/* 
 * 
 * File:   round1BC.cpp
 * Author: Andy Huang
 * Created on May 5, 2012, 11:28 AM
 */

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <fstream>
#include <set>
#include <map>
#include <sstream>
#include <deque>

using namespace std;

int val[25];
short moi[2000100];
vector<short> sets[1100000];

void solve() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2000100; i++)
    moi[i] = -1;
  for (int i = 0; i < 1100000; i++)
    sets[i].clear();
  for (int i = 0; i < n; i++)
    scanf("%d", &val[i]);
  int mask = 1;
  int index = 0;
  int l = 1 << n;
  while (mask < l) {
    int sum = 0;
    for (int i = 0; i < n; i++)
      if (1 << i & mask) {
        sum += val[i];
        sets[index].push_back(i);
      }
    if (moi[sum] == -1) {
      moi[sum] = index++;
    }
    else {
      int id = moi[sum];
      for (unsigned int i = 0; i < sets[id].size(); i++)
        printf("%d ", val[sets[id][i]]);
      puts("");
      for (unsigned int i = 0; i < sets[index].size(); i++)
        printf("%d ", val[sets[index][i]]);
      puts("");
      return;
    }
    mask++;
  }
  puts("Impossible");
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    printf("Case #%d:\n", i);
    solve();
  }
  return 0;
}

