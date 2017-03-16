#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdlib>
#include <set>
using namespace std;

int main(int argc, char** argv) {
  ifstream ifs(argv[1]);
  ofstream ofs(argv[2]);

  unsigned T = 0;
  ifs >> T;

  for (unsigned t = 0; t < T; ++t) {
unsigned zzz = 0;
    string A, B;
    ifs >> A;
    ifs >> B;

    long a0 = atol(A.c_str());
    long a = a0;
    long b = atol(B.c_str());
    int sizeA = A.size();
    while (a < b) {
      stringstream ssAA;
      ssAA << a;
      string AA = ssAA.str();
      AA = AA + AA;
      int maxRotate = sizeA - 1;
      set<long> results;
      for (int r = 0; r < maxRotate; ++r) {
        long ra = atol(AA.substr(r + 1, sizeA).c_str());
        if (ra > a && ra >= a0 && ra <= b) {
          results.insert(ra);
#if 0
cout << "Debug: " << zzz << ": (a, ra) = (" << a << ", " << ra << ")" << endl;
#endif
        }
      }
zzz += results.size();

      ++a;
    }

    // Output.
    ofs << "Case #" << t + 1 << ": " << zzz << endl;
  }

  return 0;
}
