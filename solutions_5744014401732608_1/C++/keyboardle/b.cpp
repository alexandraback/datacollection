#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

void proc(ifstream& ifile) {
  int t = 0, x = 1;
  ifile >> t;
  for(int i = 0; i < t; ++i) {
    cout << "Case #" << (x++) << ": ";
    //// TODO ////
    int B, M;
    ifile >> B >> M;
    int max = pow(2, (B-2));
    if(M > max) {
      cout << "IMPOSSIBLE";
    } else {
      cout << "POSSIBLE";
      vector<vector<int> > met(B, vector<int>(B, 0));
      for(int j = 0; j < (B-1); ++j) {
        for(int k = j+1; k < (B-1); ++k) {
          met[j][k] = 1;
        }
      }
      int count = B-2, cost = max / 2;
      while(M > 0 && count >= 0) {
        if(cost == 0) cost = 1;
        if(M >= cost) {
          M -= cost;
          met[count][B-1] = 1;
        }
        cost /= 2;
        --count;
      }
      for(int j = 0; j < B; ++j) {
        cout << endl;
        for(int k = 0; k < B; ++k) {
          cout << met[j][k];
        }
      }
    }
    //////////////
    cout << endl;
  }
}

int main(int argc, char** argv) {
  if(argc != 2) { cerr << "Wrong usage." << endl; }
  ifstream ifile(argv[1]);

  proc(ifile);

  return 0;
}
