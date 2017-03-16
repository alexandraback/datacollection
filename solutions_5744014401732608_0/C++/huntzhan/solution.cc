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


void Print(const int B, unordered_map<int, vector<int>> &paths) {
  for (int i = 0; i < B; ++i) {
    unordered_set<int> has_j(paths[i].begin(), paths[i].end());

    for (int j = 0; j < B; ++j) {
      if (has_j.count(j) > 0) {
        fout << '1';
      } else {
        fout << '0';
      }
    }
    
    fout << endl;
  }
}

void DebugPrint(const int B, unordered_map<int, vector<int>> &paths) {
  for (int i = 0; i < B; ++i) {
    unordered_set<int> has_j(paths[i].begin(), paths[i].end());

    for (int j = 0; j < B; ++j) {
      if (has_j.count(j) > 0) {
        cout << '1';
      } else {
        cout << '0';
      }
    }
    
    cout << endl;
  }
}


unordered_map<int, int> memo;

int PathsNumberHelper(
    int src,
    unordered_map<int, vector<int>> &paths, const int B) {

  if (memo.count(src) > 0) {
    return memo[src];
  }

  if (src == B - 1) {
    return 1;
  }

  int count = 0;
  for (int dst : paths[src]) {
    if (memo.count(dst) > 0) {
      count += memo[dst];
    } else {
      int dst_count = PathsNumberHelper(dst, paths, B);
      // set memo.
      memo[dst] = dst_count;
      // acc.
      count += dst_count;
    }
  }

  memo[src] = count;
  return count;
}

int PathsNumber(unordered_map<int, vector<int>> &paths, const int B) {
  memo.clear();
  // DebugPrint(B, paths);
  int c = PathsNumberHelper(0, paths, B);
  // cout << c << endl;
  // cout << "----------------------------" << endl;
  return c;
}

bool DFS(
    vector<bool> &searched, unordered_map<int, vector<int>> &paths,
    const int B, const int M) {

  bool stop = true;
  for (int i = 0; i < B; ++i) {
    if (!searched[i]) {
      stop = false;
      break;
    }
  }
  if (stop) {
    // count the number of path.
    return PathsNumber(paths, B) == M;
  }

  // recursive case.
  vector<int> already_searched;
  vector<int> not_searched;
  for (int i = 0; i < B; ++i) {

    if (searched[i]) {
      // dst can not be start.
      if (i != B - 1) {
        already_searched.push_back(i);
      }

    } else {
      not_searched.push_back(i);
    }
  }

  for (int dst : not_searched) {
    searched[dst] = true;

    for (int conn = 0; conn < (1 << already_searched.size()); ++conn) {

      for (int src_i = 0; src_i < already_searched.size(); ++src_i) {
        if (conn & (1 << src_i)) {
          int src = already_searched[src_i];
          paths[src].push_back(dst);
        }
      }

      if (DFS(searched, paths, B, M)) {
        return true;
      }

      for (int src_i = 0; src_i < already_searched.size(); ++src_i) {
        if (conn & (1 << src_i)) {
          int src = already_searched[src_i];
          paths[src].pop_back();
        }
      }

    }

    searched[dst] = false;
  }
  // no way.
  return false;
}


int main() {
  int T;
  fin >> T;

  for (int case_idx = 1; case_idx <= T; ++case_idx) {
    int B, M;
    fin >> B >> M;

    vector<bool> searched(B, false);
    searched[0] = true;

    unordered_map<int, vector<int>> paths;
    bool possible = DFS(searched, paths, B, M);

    fout << "Case #" << case_idx << ": ";
    if (!possible) {
      fout << "IMPOSSIBLE" << endl;
      continue;
    }

    // possible!
    fout << "POSSIBLE" << endl;
    Print(B, paths);
  }

  fout.close();
}
