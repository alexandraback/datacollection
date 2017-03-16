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
#include <cmath>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> II;
typedef long long LL;
#define FOR(i,b,e) for(int (i)=(int)b;(i)<(int)(e);++(i))
#define FORIT(it,c) for(typedef((c).begin()) it=(c).begin();it!=(c).end();++it)
#define INF 987654321

struct Node {
  Node ();
  Node (int i, int v):index(i),val(v){}
  int index, val;
  
  bool operator < (const Node &a) const {
    return this->val >= a.val;
  }
};

class Solution {
public:
  long long ans;
  
  long long min(long long a, long long b) {
    return a <= b ? a : b;
  }
  
  long long solve(long long A, vector<long long> &m) {
    ans = m.size();
    
    sort(m.begin(), m.end());
    
    long long startMote = A, count = 0;
    
    while (startMote <= m[0]) {
      count ++;
      startMote += startMote - 1;

      if (count >= ans) break;
    }
    
    startMote += m[0];
    
    for (int i = 1; i < m.size(); i ++) {
      if (count >= ans) break;
      if (startMote > m[i]) {
        startMote += m[i];
        ans = min(ans, count + m.size() - i - 1);
      } else {
        ans = min(ans, count + m.size() - i);
        startMote += startMote - 1;
        count ++;
        i --;
      }
    }
    
    if (count == 0) ans = 0;
    
    return ans;
  }
};


int main()
{
  freopen("/Users/yingjiang/Downloads/A-small-attempt1.in.txt", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/2A.out.txt", "w", stdout);
  
  Solution solution = Solution();
  
  long long T, A, N, tmp;
  cin >> T;
  
  vector<long long> motes;
  
  for (int i = 1; i <= T; i ++) {
    cin >> A >> N;
    
    motes.clear();
    for (int j = 0; j < N; j ++) {
      cin >> tmp;
      motes.push_back(tmp);
    }
//    solution.solve(A, motes);
    cout << "Case #" << i << ": " << solution.solve(A, motes) << endl;
  }
  
  return 0;
  
}
