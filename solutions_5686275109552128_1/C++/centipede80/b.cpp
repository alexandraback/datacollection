#include <vector>
#include <string>
#include <iostream>
using namespace std;

int doit(vector<int> &v, int mx) {
  int ret = mx;
  for(int i = 0; i < v.size(); i++) {
    if(v[i] <= mx) continue;
    ret += (v[i]+mx-1)/mx-1;
  }
  return ret;
}

int main() {
  int tests;
  cin >> tests;
  for(int i = 0; i < tests; i++) {
    int people;
    cin >> people;
    vector<int> v;
    for(int j = 0; j < people; j++) {
      int pancakes;
      cin >> pancakes;
      v.push_back(pancakes);
    }
    int ret = 10000000;
    for(int j = 1; j <= 1000; j++) {
      ret = min(ret, doit(v, j));
    }
    cout << "Case #" << (i+1) << ": " << ret << endl;
  }
  return 0;
}
