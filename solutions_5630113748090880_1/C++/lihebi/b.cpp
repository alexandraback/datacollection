#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <cassert>
#include <map>

// #include <gtest/gtest.h>

/**
 *


 1
3
1 2 3
2 3 5
3 5 6
2 3 4
1 2 3

Case #1: 3 4 6
 */
using namespace std;
int main(int argc, char* argv[]) {

  int t;
  cin >> t;
  std::set<int> s;
  for (int i=0;i<t;i++) {
    int N;
    cin >> N;
    int tmp;
    s.clear();
    for (int j=0;j<2*N-1;j++) {
      for (int k=0;k<N;k++) {
        cin >> tmp;
        if (s.count(tmp) == 1) s.erase(tmp);
        else s.insert(tmp);
      }
    }
    cout << "Case #" << i+1 << ": ";
    assert(s.size() == N);
    std::vector<int> v(s.begin(), s.end());
    std::sort(v.begin(), v.end());
    for (int a : v) {
      cout <<a << " ";
    }
    cout   << "\n";
  }
  
  // ::testing::InitGoogleTest(&argc, argv);
  // return RUN_ALL_TESTS();
}
