//
//  Q_C.cpp
//  Topcoder
//
//  Created by Charlene Jiang on 4/13/13.
//  Copyright (c) 2013 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans[13] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002};

int main()
{
  freopen("/Users/yingjiang/TopCoder/Codejam/c.in", "r", stdin);
  freopen("/Users/yingjiang/TopCoder/Codejam/c.out", "w", stdout);
  
  int T, A, B;
  cin >> T;
  
  
  for (int cases = 1; cases <= T; cases ++) {
    cin >> A >> B;
    
    bool flag = false;
    int count = 0;
    
    for (int i = 0; i < 13; i ++) {
      int tmp = ans[i] * ans[i];
      if (!flag && tmp >= A) {
        flag = true;
      }
      
      if (flag && tmp <= B) {
        count ++;
      }
      
      if (tmp > B) break;
    }
    
    
    cout << "Case #" << cases << ": " << count << endl;
  }
}