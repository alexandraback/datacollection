#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <deque>

using namespace std;

string solve(int x, int y) {
  string r;
  if(x > 0) {
    for(int i = 0; i < x; i++) {
      r += "WE";
    }
  } else {
    for(int i = 0; i < -x; i++) {
      r += "EW";
    }
  }
  if(y > 0) {
    for(int i = 0; i < y; i++) {
      r += "SN";
    }
  } else {
    for(int i = 0; i < -y; i++) {
      r += "NS";
    }
  }
  return r;
}

int main(){
  int num_cases;
  cin >> num_cases;
  for(int i = 0; i < num_cases; i++){
    int x, y;
    cin >> x >> y;
    string r = solve(x, y);
    cout << "Case #" << i+1 << ": " << r << endl;
  }
}
