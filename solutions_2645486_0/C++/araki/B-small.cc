#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int solve(int e, int r, vector<int> v, int n);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int e, r, n;
    cin >> e >> r >> n;
    vector<int> v(n);
    for(int j = 0; j < n; j++) cin >> v[j];
    int res = solve(e,r,v,n);
    cout << "Case #" << i+1 << ": " << res << endl;
  }
}

int solve1(int current, int e, int r, vector<int>& v, int idx, int n) {
  if(idx == n - 1) return current * v[idx];
  else {
    int max = 0;
    for(int i = 0; i <= current; i++) {
      int nexten = min(current - i + r, e);
      int cand = solve1(nexten, e, r, v, idx+1, n);
      int get = i * v[idx];
      if(max < cand + get) max = cand + get;
    }
    return max;
  }
}

int solve(int e, int r, vector<int> v, int n){
  return solve1(e, e, r, v, 0, n); 
}
