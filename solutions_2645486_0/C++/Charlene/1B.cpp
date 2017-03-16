//
//  Codejam.cpp
//  Topcoder
//
//  Created by Charlene Jiang on 4/27/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef long long LL;
#define FOR(i,b,e) for(int (i)=(int)b;(i)<(int)(e);++(i))
#define FORIT(it,c) for(typedef((c).begin()) it=(c).begin();it!=(c).end();++it)
#define INF 987654321

class Solution {
public:
  int ans, E, R, N;
  
  void DFS(int curr, int gain, int energy, vector<int> &values) {
    if (energy > E) energy = E;
    
    if (curr >= N) {
      //cout << ans << ' ' << gain << endl;
      ans = max(ans, gain);
      return;
    }
    
    DFS(curr + 1, gain, energy, values);
    
    for (int i = 1; i <= energy; i ++) {
      DFS(curr + 1, gain + values[curr] * i, energy - i + R, values);
    }
  }
  
  int solve(int e, int r, vector<int> & values) {
    ans = 0;
    E = e, R = r, N = values.size();
    
    DFS(0, 0, E, values);
    
    return ans;
  }
};


int main()
{
  freopen("/Users/yingjiang/Downloads/B-small-attempt0.in.txt", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/BBBB.out", "w", stdout);
  
  Solution solution = Solution();
  
  long long T, E, R, N, tmp;
  cin >> T;
  
  vector<int> values;
  
  for (int i = 1; i <= T; i ++) {
    cin >> E >> R >> N;
    
    values.clear();
    for (int j = 0; j < N; j ++) {
      cin >> tmp;
      values.push_back(tmp);
    }
    cout << "Case " << i << ": " << solution.solve(E, R, values) << endl;
  }
  
  return 0;
  
}
