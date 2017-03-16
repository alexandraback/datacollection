#include <cmath>
#include <cassert>

#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

inline int64_t getDifference(const string &A, const string &B) {
  const int length = int(A.length());
  assert(A.length() == B.length());
  int64_t difference = 0, pow10 = 1;
  for (int i = length - 1; i >= 0; --i, pow10 *= 10)
    difference += pow10 * (A[i] - B[i]);
  return difference;
}

inline string maximize(string A) {
  for (int i = 0; i < int(A.length()); ++i)
    if (A[i] == '?')
      A[i] = '9';
  return A;
}

inline string minimize(string A) {
  for (int i = 0; i < int(A.length()); ++i)
    if (A[i] == '?')
      A[i] = '0';
  return A;
}

inline void update(const string C, const string J, string &bestC, string &bestJ) {
  if (bestC == "" && bestJ == "") {
    bestC = C;
    bestJ = J;
  }
  const int64_t difference = abs(getDifference(C, J));
  const int64_t bestDifference = abs(getDifference(bestC, bestJ));
  if (difference < bestDifference) {
    bestC = C;
    bestJ = J;
  } else if (difference == bestDifference) {
    if (C < bestC) {
      bestC = C;
      bestJ = J;
    } else if (C == bestC) {
      if (J < bestJ) {
        bestC = C;
        bestJ = J;
      }
    }
  }
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int testCount;
  in >> testCount;
  for (int test = 1; test <= testCount; ++test) {
    string C, J;
    in >> C >> J;
    const int length = int(C.length());
    string bestC = "", bestJ = "";
    for (int i = 0; i < length; ++i) {
      for (char c = '0'; c <= '9'; ++c) {
        string newC = C;
        if (newC[i] != '?' && c != newC[i])
          continue;
        else
          newC[i] = c;
        for (char j = '0'; j <= '9'; ++j) {
          string newJ = J;
          if (newJ[i] != '?' && j != newJ[i])
            continue;
          else
            newJ[i] = j;
          bool valid = true;
          for (int k = 0; k < i && valid; ++k) {
            if (newC[k] == '?' && newJ[k] != '?')
              newC[k] = newJ[k];
            else if (newC[k] != '?' && newJ[k] == '?')
              newJ[k] = newC[k];
            else if (newC[k] == '?' && newJ[k] == '?')
              newC[k] = newJ[k] = '0';
            else if (newC[k] != newJ[k])
              valid = false;
          }
          if (valid) {
            update(minimize(newC), maximize(newJ), bestC, bestJ);
            update(maximize(newC), minimize(newJ), bestC, bestJ);
          }
        }
      }
    }
    out << "Case #" << test << ": " << bestC << " " << bestJ << "\n";
  }
  in.close();
  out.close();
  return 0;
}
