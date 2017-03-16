//
//  Q_B.cpp
//  Topcoder
//
//  Created by Charlene Jiang on 4/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int M, N;
int g[110][110];

bool remove(int r, int c, int height)
{
  bool flag = true, ans = false;
  
  // check row
  for (int i = 1; i <= M; i ++) {
    if (g[r][i] > 0 && g[r][i] > height) {
      flag = false;
      break;
    }
  }
  
  if (flag) {
    for (int i = 1; i <= M; i ++) {
      g[r][i] = 0;
    }
    ans = true;
  }
  
  // check column
  flag = true;
  for (int i = 1; i <= N; i ++) {
    if (g[i][c] > 0 && g[i][c] > height) {
      flag = false;
      break;
    }
  }
  
  if (flag) {
    for (int i = 1; i <= N; i ++) {
      g[i][c] = 0;
    }
    
    ans = true;
  }
  
  return ans;
}

bool removeHeight(int minHeight) 
{
  for (int i = 1; i <= N; i ++) {
    for (int j = 1; j <= M; j ++) {
      if (minHeight == g[i][j]) {
        if (!remove(i, j, minHeight)) return false;
      }
    }
  }
  
  return true;
}

bool isOK()
{
  bool flag = true;
  
  int minHeight = 110;
  
  while (flag) {
    minHeight = 110;
    flag = false;
    
    for (int i = 1; i <= N; i ++) {
      for (int j = 1; j <= M; j ++) {
        if (g[i][j] > 0 && minHeight > g[i][j]) {
          minHeight = g[i][j];
          flag = true;
        }
      }
    }
    
    if (flag && !removeHeight(minHeight)) return false;
  }
  
  return true;
}

int main()
{
  freopen("/Users/yingjiang/TopCoder/Codejam/b.in", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/b_large.out", "w", stdout);
  
  int T;
  cin >> T;
  
  for (int cases = 1; cases <= T; cases ++) {
    cin >> N >> M;
    for (int i = 1; i <= N; i ++) {
      for (int j = 1; j <= M; j ++) {
        cin >> g[i][j];
      }
    }
    
    if (isOK()) {
      cout << "Case #" << cases << ": YES" << endl;
    } else {
      cout << "Case #" << cases << ": NO" << endl;
    }
  }
  
  
}



