#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
//#include <ios>
using namespace std;

int main(int argc, char** argv) {
  ifstream ifs(argv[1]);
  ofstream ofs(argv[2]);

  unsigned T = 0;
  ifs >> T;

  vector<int> list;
  list.reserve(1000);
  for (unsigned t = 0; t < T; ++t) {
    unsigned N = 0;
    ifs >> N;

    unsigned S = 0;
    ifs >> S;

    int P = 0;
    ifs >> P;

    list.clear();
    for (unsigned n = 0; n < N; ++n) {
      int i;
      ifs >> i;
      list.push_back(i);
    }

    vector<int> sorted(list);
    sort(sorted.rbegin(), sorted.rend());

    unsigned numPeople = 0;
    unsigned numSurprise = 0;
    unsigned numInt = sorted.size();

#if 0
cerr << "Debug: " << endl
<< "N = " << N << endl
<< "S = " << S << endl
<< "P = " << P << endl
<< "numInt = " << numInt << endl
<< "numPeople = " << numPeople << endl
<< "numSurprise = " << numSurprise << endl;
#endif

    for (unsigned i = 0; i < numInt; ++i) {
      int s = sorted[i];
      if (s >= (3 * P - 2)) {
        ++numPeople;
//cerr << "Debug1" << endl;
        continue;
      } else if (s < P || s < (3 * P - 4)) {
//cerr << "Debug2" << endl;
//cerr << "s = " << s << endl;
        break;
      } else if (numSurprise >= S) {
//cerr << "Debug3" << endl;
        break;
      } else {
        ++numSurprise;
        ++numPeople;
//cerr << "Debug4" << endl;
        continue;
      }
    }

    // Output.
//cout << "Case #" << t + 1 << ": " << numPeople << endl;
    ofs << "Case #" << t + 1 << ": " << numPeople << endl;
  }

  return 0;
}
