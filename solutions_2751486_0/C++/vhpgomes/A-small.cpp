#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

const char* input  = "A-small-attempt1.in";
const char* output = "A-small-attempt1.out";


int main(int argc, char** argv) {
  
  ifstream I(input);
  ofstream O(output);

  int T; I >> T;
  for (int t = 0; t < T; ++t) {

    string name; I >> name;
    int n; I >> n;
    int L = name.length();
    /*
    vector<int> D;
    D.resize(L);

    int c = 0;
    for (int i = 0; i < L; ++i) {
      if (name[i] != 'a' && name[i] != 'e' && name[i] != 'i' && name[i] != 'o' && name[i] != 'u')
        ++c;
      else
        c = 0;

      D[i] = c;
    }*/

    int total = 0;
    for (int i = 0; i < L; ++i) {
      for (int j = i; j < L; ++j) {
        int c = 0;
        for (int k = i; k <= j; ++k) {
          if (name[k] != 'a' && name[k] != 'e' && name[k] != 'i' && name[k] != 'o' && name[k] != 'u')
            ++c;
          else
            c = 0;

          if (c >= n) {
            ++total;
            break;
          }
        }
      }
    }


    O << "Case #" << (t + 1) << ": " << total << endl;
    cout << "Case #" << (t + 1) << ": " << total << endl;
  }


  I.close();
  O.close();
  return 0;
}

