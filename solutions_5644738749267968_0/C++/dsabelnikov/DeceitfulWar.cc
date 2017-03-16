#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned int uint;

#define do_times(N) for (uint i = 0; i < N; i++)

void solve_case(istream &input, ostream &output) {
  // do stuff here
  uint N;
  double temp;
  vector<double> naomi;
  vector<double> ken;
  input >> N;
  do_times(N) {
    input >> temp;
    naomi.push_back(temp);
  }
  do_times(N) {
    input >> temp;
    ken.push_back(temp);
  }
  sort(naomi.begin(), naomi.end());
  sort(ken.begin(), ken.end());

  // step 1, War
  uint sc1 = 0;
  vector<bool> used(N, false);
//cout << endl;
//for (double &d: naomi) cout << d << " ";
//cout << endl;
//for (double &d: ken) cout << d << " ";
//cout << endl;
  for (uint x = N; x > 0; x--) {
    bool next = false;
    for (uint j = 0; j < N; j++) {
      if (ken[j] > naomi[x-1] && !used[j]) {
        used[j] = true;
        next = true;
        break;
      }
    }
    if (next) continue;
    for (uint j = 0; j < N; j++) {
      if (!used[j]) {
        used[j] = true;
        sc1++;
        break;
      }
    }
  }

  // step 2, Deceitful War
  uint sc2 = N;
  vector<bool> used2(N, false);
  for (uint x = N; x > 0; x--) {
    bool next = false;
    for (uint j = N; j > 0; j--) {
      if (ken[j-1] < naomi[x-1] && !used2[j-1]) {
        used2[j-1] = true;
        next = true;
        break;
      }
    }
    if (next) continue;
    for (uint j = N; j > 0; j--) {
      if (!used2[j-1]) {
        used2[j-1] = true;
        sc2--;
        break;
      }
    }
  }

  output << sc2 << " " << sc1;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Usage: " << argv[0] << " <filename>" << endl;
    return 0;
  }
  ifstream file(argv[1]);
  if (file == NULL) {
    cerr << "Can't open file " << argv[1] << endl;
  }
  uint N; // Number of cases
  file >> N;
  do_times(N) {
    cout << "Case #" << i + 1 << ": ";
    solve_case(file, cout);
    cout << endl;
  }
}
