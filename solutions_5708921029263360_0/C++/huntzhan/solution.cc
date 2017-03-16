// {{{ $VIMCODER$ <-----------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

// }}}

const string kInputFilename = "input.txt";
const string kOutputFilename = "output.txt";

ifstream fin(kInputFilename);
ofstream fout(kOutputFilename);



int main() {
  int T;
  fin >> T;

  for (int case_idx = 1; case_idx <= T; ++case_idx) {
    int J, P, S, K;
    fin >> J >> P >> S >> K;

    vector<vector<int>> J_P(J, vector<int>(P, 0));
    vector<vector<int>> J_S(J, vector<int>(S, 0));
    vector<vector<int>> P_S(P, vector<int>(S, 0));

    vector<vector<int>> ret;

    for (int j = 0; j < J; ++j) {
      for (int p = 0; p < P; ++p) {
        for (int s = 0; s < S; ++s) {
          if (J_P[j][p] >= K || J_S[j][s] >= K || P_S[p][s] >= K) {
            continue;
          }

          vector<int> line = {j, p, s};
          ret.push_back(line);

          // record it.
          ++J_P[j][p];
          ++J_S[j][s];
          ++P_S[p][s];
        }
      }
    }

    fout << "Case #" << case_idx << ": " << ret.size() << endl;
    for (int i = 0; i < ret.size(); ++i) {
      auto &line = ret[i];
      fout << line[0] + 1 << " "
           << line[1] + 1 << " "
           << line[2] + 1 << endl;
    }
  }

  fout.close();
}
