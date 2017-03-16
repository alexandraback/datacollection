/* 
 * 
 * File:   round1BA.cpp
 * Author: Andy Huang
 * Created on May 5, 2012, 11:25 AM
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

int pts[250];
const double eps = 1e-9;

void solve() {
  int n, sum = 0;;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%d", &pts[i]);
    sum += pts[i];
  }
  int n2 = n;
  int sum2 = sum;
  double minsc = double(sum << 1) / n;
  for (int i = 0; i < n; i++)
    if (pts[i] + eps >= minsc){
      n2--;
      sum2 -= pts[i];
    }
  minsc = double(sum + sum2) / n2;
  for (int i = 0; i < n; i++){
    double ans = double(minsc - pts[i]) / sum * 100;
    printf("%.8f ", max(0.0, ans));
  }
  puts("");
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for(int i = 1; i <= tests; i++){
    printf("Case #%d: ",i);
    solve();
  }
  return 0;
}

