/* 
 * 
 * File:   round1CA.cpp
 * Author: Andy Huang
 * Created on May 6, 2012, 12:53 AM
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

const int INF = 100000000;
int graph[1050][1050];
int len[1050];
bool moi[1050];
bool start[1050];
int n;

bool dfs(int cur) {
  moi[cur] = true;
  for (int i = 0; i < len[cur]; i++) {
    if (moi[graph[cur][i]] || dfs(graph[cur][i]))
      return true;
  }
  return false;
}

void solve() {
  scanf("%d", &n);
  memset(moi, false, sizeof (moi));
  for (int i = 0; i < n; i++)
    start[i] = true;
  for (int i = 0; i < n; i++) {
    int m;
    scanf("%d", &m);
    int index = 0;
    while (m--) {
      scanf("%d", &graph[i][index]);
      graph[i][index]--;
      start[graph[i][index]] = false;
      index++;
    }
    len[i] = index;
  }
  for (int i = 0; i < n; i++) {
    if (start[i]) {
      memset(moi, false, sizeof(moi));
      if (dfs(i)){
        puts("Yes");
        return;
      }
    }
  }
  puts("No");
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int tests;
  scanf("%d", &tests);
  for (int i = 1; i <= tests; i++) {
    printf("Case #%d: ", i);
    solve();
  }
  return 0;
}

