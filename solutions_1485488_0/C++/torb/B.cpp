#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>
#include <set>
#include <cstdio>

using namespace std;

int main() {
  int TC; cin >> TC;
  for (int t = 1; t <= TC; t++) {
    int N; cin >> N;
    vector<int> nums(N);
    for(int i = 0; i < N; ++i) {
      cin >> nums[i];
    }
    bool found = false;
    vector<int> one, two, rest;
    for(int i = 1; i < 1<<N; ++i) {
      one.clear();
      two.clear();
      rest.clear();
      int sum = 0;
      for(int j = 0; j < N; ++j) {
        if(i & (1<<j)) {
          sum += nums[j];
          one.push_back(nums[j]);
        }
        else rest.push_back(nums[j]);
      }
      vector<vector<int> > dp(rest.size(), vector<int>(sum+1, -2));
      for(int j = 0; j < rest.size(); ++j) {
        if(rest[j] <= sum) dp[j][rest[j]] = -1;
        for(int k = 0; k < j; ++k) {
          for(int l = 0; l <= sum-rest[j]; ++l) {
            if(dp[k][l] != -2) dp[j][l+rest[j]] = k;
          }
        }
        if(dp[j][sum] != -2) {
          found = true;
          int cur = j, cursum = sum;
          while(cur >= 0) {
            two.push_back(rest[cur]);
            int tmp = dp[cur][cursum];
            cursum -= rest[cur];
            cur = tmp; 
          }
          break;
        }
      }
      if(found) {
        break;    
      }
    }


    printf("Case #%d:\n", t);
    if(!found) cout << "Impossible\n";
    else {
      for(int i = 0; i < one.size(); ++i) {
        if(i != 0) cout << " ";
        cout << one[i];
      }
      cout << endl;
      for(int i = 0; i < two.size(); ++i) {
        if(i != 0) cout << " ";
        cout << two[i];
      }
      cout << endl;
    }

  }


  return 0;
}
