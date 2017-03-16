#include <fstream>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <cassert>

using namespace std;


void scan(char c1, char c2, char c3, char c4, bool flags[3]){
}

int main(int argc, char* argv[]) {
  fstream     f(argv[1]);

  int T;
  f >> T;

  for(int t = 1; t <= T; t++) {
    int   N, M;

    f >> N >> M;

    vector<vector<int>>     ar;

    ar.resize(N);

    for(int i = 0; i < N; i++) {
      ar.at(i).resize(M);

      for(int j = 0; j < M; j++) {
        f >> ar[i][j];
      }
    }

    ////

    if(0)
    for(auto& line : ar) {
      for(auto c : line) {
        cerr << c << " ";
      }
      cerr << endl;
    }

    vector<int>     ma_n, ma_m;

    ma_n.resize(N);
    ma_m.resize(M);

    for(int i = 0; i < N; i++) {
      int ma = ar[i][0];
      for(int j = 1; j < M; j++) {
        const auto& cur = ar[i][j];
        if(ma < cur) ma = cur;
      }
      ma_n[i] = ma;
    }

    for(int j = 0; j < M; j++) {
      int ma = ar[0][j];
      for(int i = 1; i < N; i++) {
        const auto& cur = ar[i][j];
        if(ma < cur) ma = cur;
      }
      ma_m[j] = ma;
    }

    bool  wecan = true;

    for(int i = 0; i < N; i++) {
      for(int j = 0; j < M; j++) {
        const auto& cur = ar[i][j];
        if(cur != ma_n[i] && cur != ma_m[j] ) {
          wecan = false;
          break;
        }
      }
      if(!wecan) break;
    }

    cout << "Case #" << t << ": " << (wecan?"YES":"NO")
      // << "(" << N << "x" << M << ")"
      << endl;
  }
}

