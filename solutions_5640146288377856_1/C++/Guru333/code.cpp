#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
  ifstream in("input");
  ofstream out("answer");
  int T;
  in >> T;
  int R,C,W;
  for(int t = 1; t <= T; t++){
    out << "Case #" << t << ": ";
    in >> R >> C >> W;
    int k = C/W;
    if( C%W == 0){ out << (k-1+W + (k)*(R-1)) << endl;}
    	else{ out << (k+W + (k+1)*(R-1)) << endl;}
    } 


  return 0;
}