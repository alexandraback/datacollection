#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int solve(int r, int t);

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int r, t;
    cin >> r >> t;
    int res = solve(r,t);
    cout << "Case #" << i+1 << ": " << res << endl;
  }
}

int solve(int r, int t){
  double current = 0;
  int i;
  for(i = 0; current <= t; i++) {
    current += 
    ((r + i * 2 + 1) * (r + i * 2 + 1) -
     (r + i * 2) * (r + i * 2));
  }
  return i - 1;
}
