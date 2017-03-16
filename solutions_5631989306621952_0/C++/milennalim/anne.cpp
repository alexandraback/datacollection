#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <array>
#include <iostream>

using namespace std;
typedef long long ll;

string blah(string s) {
  string s2 = s.substr(0,1);
  
  for (int i=1; i<s.size(); i++) {
    if (s[i]>=s2[0]) {
      s2.insert(0, s.substr(i,1));
    } else if (s[i]<s2[0]) {
      s2.append(s.substr(i,1));
    }
  }
  return s2;
}

int main() {
  ifstream fin;
  fin.open ("anne.in");
  ofstream fout;
  fout.open ("anne.out");

  int t; fin >> t;
  
  for (int i=0; i<t; i++) {
    string cur; fin >> cur;
    fout << "Case #" << i+1 << ": " << blah(cur) << endl;
  }
  
  
}