#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

//#define INF 10000000

int target(vector<int> & vec, int tgt){
  int res = tgt;
  int idx = 0;
  while (idx < vec.size() && vec[idx] > tgt) {
    int minutes = vec[idx] / tgt + (vec[idx] % tgt != 0) - 1;
    res += minutes;
    idx++;
  }
  return res;
}

int solve(vector<int> &vec){
  int max = vec[0];
  int result = max;
  
  for (int t = 1; t < max; t++) {
    int time = target(vec, t);
    if (time < result)
      result = time;
  }
  return result;
}



int main(){
  int T;
  cin >> T;
  for (int testcase=1; testcase <= T; testcase++){
    int diners;
    cin >> diners;
    vector<int> vec;
    int p;
    for (int d=0; d<diners; d++){
      cin >> p;
      vec.push_back(p);
    }
    std::sort(vec.rbegin(), vec.rend());
    int result = solve(vec);
    cout << "Case #" << testcase << ": " << result << endl;
  }
  return 0;
}
