#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef unsigned int uint;

#define do_times(N) for (uint i = 0; i < N; i++)

#define min(x, y) x <= y ? x : y

string print(vector<string> &map) {
  string S = "";
  do_times(map.size()) {
    S += map[i];
    if (i != map.size() - 1) S += "\n";
  }
  return S;
}

string solve(vector<string> map, uint R, uint C, uint M) {
//  cout << endl << print(map) << endl;
  if (M == 0) {
    if ((C > 1 && R > 1) || 
        (map.size() == 1 && C > 0) || 
        (map[0].length() == 1 && R > 0) ||
        (C == 1 && R == 1)) {
      map[0][0] = 'c';
      return print(map);
    }
  }
  if (C == 2 && R == 2 && M != 3) return "Impossible";
  if (R >= C && M >= C && R > 0) {
    do_times(C) map[R-1][i] = '*';
    return solve(map, R-1, C, M-C);
  } else if (C >= R && M >= R && C > 0) {
    do_times(R) map[i][C-1] = '*';
    return solve(map, R, C-1, M-R);
  }
  if (R == 4 && C == 4 && M == 3) {
    map[3][3] = '*';
    map[2][3] = '*';
    map[3][2] = '*';
    return solve(map, R, C, 0);
  }
  if (R <= C && R > 2) {
    uint m = min(M, C - 2);
    do_times(m) map[R-1][C-i-1] = '*';
    M -= m;
    if (M != 0 && R > 4) {
      m = min(M, C - 2);
      do_times(m) map[0][C-i-1] = '*';
      M -= m;
    }
    if (M == 0) {
      map[0][0] = 'c';
      return print(map); 
    }
  } else if (C <= R && C > 2) {
    uint m = min(M, R - 2);
    do_times(m) map[R-i-1][C-1] = '*';
    M -= m;
    if (M != 0 && C > 4) {
      m = min(M, R - 2);
      do_times(m) map[R-i-1][0] = '*';
      M -= m;
    }
    if (M == 0) {
      map[0][0] = 'c';
      return print(map); 
    }
  }

  return "Impossible";
}

string solve_case(istream &input) {
  // do stuff here
  uint R, C, M;
  input >> R;
  input >> C;
  input >> M;
  vector<string> map;
  do_times(R) {
    string str = "";
    do_times(C) str += ".";
    map.push_back(str);
  }

  return "\n" + solve(map, R, C, M);
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
    string result = solve_case(file);
    cout << "Case #" << i + 1 << ": " << result << endl;
  }
}
