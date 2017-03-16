#include <cmath>

#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

inline bool match(const string &A, const string &B) {
  const int length = int(A.length());
  if (A.length() != B.length())
    return false;
  for (int i = 0; i < length; ++i)
    if (A[i] != '?' && B[i] != '?' && A[i] != B[i])
      return false;
  return true;
}

inline string toString(int value, const int length) {
  string valueString = "";
  for (int i = 0; i < length; ++i, value /= 10)
    valueString.push_back('0' + value % 10);
  reverse(valueString.begin(), valueString.end());
  return valueString;
}

inline bool valid(const int c, const int j, const string &C, const string &J) {
  const int length = int(C.length());
  return match(toString(c, length), C) && match(toString(j, length), J);
}

int main() {
  ifstream in("input.txt");
  ofstream out("output.txt");
  int testCount;
  in >> testCount;
  int pow10[] = {1, 10, 100, 1000};
  for (int test = 1; test <= testCount; ++test) {
    string C, J;
    in >> C >> J;
    const int length = int(C.length());
    int bestC = -1, bestJ = 1000;
    for (int c = 0; c < pow10[length]; ++c) {
      for (int j = 0; j < pow10[length]; ++j) {
        if (valid(c, j, C, J)) {
          if (abs(c - j) < abs(bestC - bestJ)) {
            bestC = c;
            bestJ = j;
          } else if (abs(c - j) == abs(bestC - bestJ)) {
            if (c < bestC) {
              bestC = c;
              bestJ = j;
            } else if (c == bestC) {
              if (j < bestJ) {
                bestC = c;
                bestJ = j;
              }
            }
          }
        }
      }
    }
    out << "Case #" << test << ": " << toString(bestC, length) << " " << toString(bestJ, length) << "\n";
  }
  in.close();
  out.close();
  return 0;
}
