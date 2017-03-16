#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <array>
#include <iostream>
#include <set>

using namespace std;
typedef long long ll;


int main() {
  ifstream fin;
  fin.open ("anne.in");
  ofstream fout;
  fout.open ("anne.out");

  int t; fin >> t;
  
  for (int i=0; i<t; i++) {
    set<int> col;
    int n; fin >> n;
    for (int j=0; j<(2*n-1)*n; j++) {
      int cur; fin >> cur;
      if (col.find(cur) != col.end()) {
        col.erase(cur);
      } else {
        col.insert(cur);
      }
    }
    
    fout << "Case #" << i+1 << ": ";
    for (auto i : col) {
      fout << i << " ";
    }
    fout << endl;
  }
  
  
}