#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  // Read
  //ifstream ifi("input.in");  
  ifstream ifi("D-small-attempt0.in");
  int cn;
  ifi >> cn;
  vector<int> X(cn);
  vector<int> R(cn);
  vector<int> C(cn);  
  for (int i = 0; i < cn; i++) {
    ifi >> X[i];
    ifi >> R[i];
    ifi >> C[i];    
  }  
  ifi.close();
  // Solve
  vector<bool> ans(cn, false);
  for (int i = 0; i < cn; i++) {
    // Init
    bool a = false;
    int x = X[i], r = R[i], c = C[i];
    // Hole
    if (x >= 7) a = true;
    // Integer division
    if ((r * c) % x != 0) a = true;
    // Fit
    if (x > r && x > c) a = true;
    int l1, l2;
    if (x % 2 == 1) { l1 = l2 = (x + 1) / 2; }
    if (x % 2 == 0) { l1 = x / 2; l2 = l1 + 1; }
    if ((l1 <= r && l2 <= c) || (l1 <= c && l2 <= r)) {} 
    else a = true;    
    // C
    if ((l1 == 1 || l2 == 1) && x >= 3) a = true;
    if ((l1 == 2 || l2 == 2) && x >= 5) a = true;
    // Half
    if (x >= 4 && (r * c) / x == 2) a = true;
    // Final
    ans[i] = a;
  }      
  // Write  
  ofstream ofi("output.txt");
  for (int i = 0; i < cn; i++) {    
    ofi << "Case #" << i + 1 << ": ";
    if (ans[i]) {
      ofi << "RICHARD" << endl;
    } else {
      ofi << "GABRIEL" << endl;
    }
  }
  ofi.close();
  return 0;
}