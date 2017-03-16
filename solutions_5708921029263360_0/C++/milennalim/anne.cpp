#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <fstream>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main() {
  ifstream myfile;
  myfile.open ("awesome.in");
  ofstream a_file ( "example.out" );
  
  int t; myfile >> t;
  
  for (int i=0; i<t; i++) {
    int j, p, s, k;
    myfile >> j >> p >> s >> k;
    
    int days;
    if (k < s) {
      days = j*p*k;
    } else {
      days = j*p*s;
    }
    
    a_file << "Case #" << i+1 << ": " << days << endl;
    
    for (int a=1; a<=min(k,s); a++) {
      for (int b=1; b<=p; b++) {
        for (int c=1; c<=j; c++) {
          a_file << c << " " << b << " " << a << endl;
        }
      }
    }
    
  }
  
  a_file.close();
}