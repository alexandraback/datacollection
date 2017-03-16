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
    if( R == 1){
    	//small
    	int k = C/W;
    	if( C%W == 0){ out << k-1+W << endl;}
    	else{ out << k+W << endl;}
    } 

  }
  return 0;
}