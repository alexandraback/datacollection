#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
  // 
  //string infile = "example.in";
  string infile = "A-small-attempt2.in";
  string outfile = "out.txt";    
  ifstream in(infile);
  int T;
  in >> T;
  ofstream out(outfile);
  // 
  for (int i = 0; i < T; i++) {
      // 
      int R, C, W;
      in >> R >> C >> W;
      int r = 0;
      //
      r += R * int(C / W);
      r += W - 1;
      if (W != 1 && W != R * C && double(C) / double(W) != double(C / W)) r++;
      //
      out << "Case #" << i + 1 << ": ";
      out << r << endl;
  }
  // 
  in.close();
  out.close();
}
