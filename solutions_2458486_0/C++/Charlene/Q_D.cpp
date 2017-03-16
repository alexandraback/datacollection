//
//  Q_D.cpp
//  Topcoder
//
//  Created by Charlene Jiang on 4/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int K, N;
vector<int> startKeys, keyTypes, keyCount;
vector<vector<int> > lockedKeys;


bool caled[1 << 20];
bool isok[1 << 20];
vector<int> ans[1 << 20];

void input()
{
  cin >> K >> N;
  
  startKeys.resize(K);
  keyTypes.resize(N);
  keyCount.resize(N);
  lockedKeys.resize(N);
  
  for (int i = 0; i < K; i ++) {
    cin >> startKeys[i];
  }
  
  for (int i = 0; i < N; i ++) {    
    cin >> keyTypes[i] >> keyCount[i];
    
    lockedKeys[i].resize(keyCount[i]);
    for (int j = 0; j < keyCount[i]; j ++) {
      cin >> lockedKeys[i][j];
    }
  }
}

bool dfs(int state)
{
  if (caled[state]) return isok[state];
  caled[state] = true;
  ans[state].clear();
  
  if (state == (1 << N) - 1) return isok[state] = true;
  
  map<int, int> remainKeys;
  
  for (int i = 0; i < startKeys.size(); i ++) 
    remainKeys[startKeys[i]] ++;
  
  for (int i = 0; i < N; i ++) {
    if (state & (1 << i)) {
      remainKeys[keyTypes[i]] --;
      for (int j = 0; j < lockedKeys[i].size(); j ++)
        remainKeys[lockedKeys[i][j]] ++;
    }
  }
  
  for (int i = 0; i < N; i ++) {
    if ((state & (1 << i)) == 0) {
      int newstate = state + (1 << i);
      if (remainKeys[keyTypes[i]] > 0)
      {
        if (dfs(newstate))
        {
          ans[state] = ans[newstate];
          ans[state].push_back(i);
          return isok[state] = true;
        }
      }
    }
  }
  
  return false;
}


bool deal()
{
  memset(caled, false, sizeof(caled));
  memset(isok, false, sizeof(isok));
  
  return dfs(0);
}

int main1()
{
  freopen("/Users/yingjiang/TopCoder/Codejam/d.in", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/d.out", "w", stdout);
  
  int T, isPossible;
  cin >> T;
  
  for (int cases = 1; cases <= T; cases ++) {
    isPossible = 0;
    
    input();
    
    bool ret = deal();
    
    if (!ret) {
      cout << "Case #" << cases << ": IMPOSSIBLE" << endl;
    } else {
      cout << "Case #" << cases << ": ";
      
      for (int i = N - 1; i > 0; i --) {
        cout << ans[0][i] + 1 << ' ';
      }
      cout << ans[0][0] + 1 << endl;
    }
  }
}