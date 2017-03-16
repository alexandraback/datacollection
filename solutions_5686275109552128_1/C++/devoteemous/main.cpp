#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  // Read
  // ifstream ifi("input.txt");  
  ifstream ifi("B-large.in");
  int cn;
  ifi >> cn;
  vector<int> din(cn);
  vector<vector<int>> cake(cn, vector<int>());
  for (int i = 0; i < cn; i++) {
    ifi >> din[i];
    cake[i].resize(din[i]);
    for (int j = 0; j < din[i]; j++) ifi >> cake[i][j];    
  }  
  ifi.close();
  // Solve
  vector<int> ans(cn);
  for (int i = 0; i < cn; i++) {
    int cake_max = 0;    
    for (int j = 0; j < din[i]; j++) if (cake[i][j] > cake_max) cake_max = cake[i][j];    
    int opt = cake_max;
    int test = 1;
    while (test < cake_max) {      
      int ext_min = 0;
      for (int j = 0; j < din[i]; j++) {
        int chunk = cake[i][j] / test;
        if (cake[i][j] % test == 0) chunk--;
        ext_min += chunk;
      }
      int test_time = test + ext_min;
      if (test_time < opt) opt = test_time;
      test++;
    }
    ans[i] = opt;
  }
  // Write  
  ofstream ofi("output.txt");
  for (int i = 0; i < cn; i++) {    
    ofi << "Case #" << i + 1 << ": " << ans[i] << endl;
  }
  ofi.close();
  return 0;
}