#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

int findMid(vector<int>& v) {
  sort(v.begin(), v.end());
  int size = v.size();
  if (size & 1 == 0) {
    return (v[size >> 1] + v[(size >> 1) -1]) >> 1;
  } else {
    return v[size >> 1];
  }
};

int main() {
  int T,t, N;
  vector<string> strs;
  vector<int> curs;
  string str;
  cin >> T;
  t = 0;
  while(t++<T) {
    cin >> N;
    strs.clear();
    curs.clear();
    for (int i=0; i<N; i++) {
      cin >> str;
      strs.push_back(str);
      curs.push_back(0);
    }
    vector<int> nums;
    int count;
    bool zero = false;
    int result=0;
    while(curs[0] < strs[0].size() && !zero) {
      char c = strs[0][curs[0]];
      nums.clear();
      for (int i=0; i<N; i++) {
	count = 0;
	while(curs[i] < strs[i].size() && strs[i][curs[i]] == c) {
	  count++;
	  curs[i]++;
	}
	if (count == 0) {
	  zero = true;
	  break;
	}
	nums.push_back(count);
      }
      if (zero) break;
      int mid = max(1, findMid(nums));
      for (int n : nums) {
	result += max(n-mid, mid-n);
      }
    }
    if (!zero) {
      for (int i=0; i<N; i++) {
	if (curs[i] < strs[i].size()) {
	  zero =  true;
	  break;
	}
      }
    }
    if (zero) {
      printf("Case #%d: Fegla Won\n", t);
    } else {
      printf("Case #%d: %d\n", t, result);
    }

  }
  return 0;
}
