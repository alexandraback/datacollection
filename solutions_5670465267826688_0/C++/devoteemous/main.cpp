#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int quat(int a1s, int a2s) {  // i(2) j(3) k(4)
  int a1 = abs(a1s);
  int a2 = abs(a2s);
  int s1 = a1s / a1;
  int s2 = a2s / a2;
  int s = s1 * s2;
  //
  if (a1 == 1) return s * a2;
  if (a2 == 1) return s * a1;
  if (a1 == a2) {
    if (a1 == 1) return s;
    return -s;
  }  
  if (a1 == 2 && a2 == 3) return s * 4;
  if (a1 == 2 && a2 == 4) return s * -3;
  if (a1 == 3 && a2 == 4) return s * 2;
  if (a1 == 3 && a2 == 2) return s * -4;
  if (a1 == 4 && a2 == 2) return s * 3;
  if (a1 == 4 && a2 == 3) return s * -2;  
}

int main(int argc, char** argv) {
  // Check
  {
    vector<int> vec = {-4, -3, -2, -1, 1, 2, 3, 4};
    for (const auto& i : vec)
      for (const auto& j : vec)
        cout << i << " x " << j << " = " << quat(i, j) << endl;
  }
  // Read
  //ifstream ifi("input.txt");    
  ifstream ifi("C-small-attempt1.in");
  int cn;
  ifi >> cn;
  vector<int> L(cn);
  vector<int> X(cn);
  vector<vector<int>> str(cn, vector<int>());
  for (int i = 0; i < cn; i++) {
    ifi >> L[i];
    ifi >> X[i];    
    str[i].resize(L[i]);
    string line;
    getline(ifi, line);
    getline(ifi, line);
    for (int j = 0; j < L[i]; j++) {          
      char ch = line[j];
      if (ch == 'i') {
        str[i][j] = 2;
      } else if (ch == 'j') {
        str[i][j] = 3;
      } else {
        str[i][j] = 4;
      }
    }
  }  
  ifi.close();
  // Solve
  vector<bool> ans(cn, false);
  for (int i = 0; i < cn; i++) {
    if (L[i] == 1) continue;
    if (L[i] * X[i] < 3) continue;
    if (L[i] == 3 && X[i] == 1) {
      if (str[i][0] == 2 && str[i][1] == 3 && str[i][2] == 4) ans[i] = true;
      continue;        
    }
    // 
    int let = 1;
    int next = 2;
    for (int j = 0; j < X[i]; j++) {
      int old_let = let;
      for (int k = 0; k < L[i]; k++) {
        let = quat(let, str[i][k]);
        if (let == next) {
          let = 1;
          next++;
        }
      }
      //if (old_let == let) break;
    }
    if (next == 5 && let == 1) ans[i] = true;
  }      
  // Write  
  ofstream ofi("output.txt");
  for (int i = 0; i < cn; i++) {    
    ofi << "Case #" << i + 1 << ": ";
    if (ans[i]) {
      ofi << "YES" << endl;
    } else {
      ofi << "NO" << endl;
    }
  }
  ofi.close();
  return 0;
}