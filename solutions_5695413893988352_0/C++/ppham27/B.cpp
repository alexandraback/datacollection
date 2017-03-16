#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// void makeScoresCloseHelper(string &bestC, string &bestJ, unsigned long long &minDifference,
//                            string &C, string &J, int idx) {
//   int N = C.length();
//   if (idx == N) {
//     unsigned long long intC = stoull(C);
//     unsigned long long intJ = stoull(J);
//     unsigned long long difference = intC >= intJ ? intC - intJ : intJ - intC;
//     if (minDifference > difference) {
//       minDifference = difference;
//       bestC = C; bestJ = J;
//     } else if (minDifference == difference) {
//       if (C < bestC) {
//         bestC = C; bestJ = J;
//       } else if (C == bestC && J < bestJ) {
//         bestC = C; bestJ = J;
//       }
//     }
//   } else if (C[idx] != '?' && J[idx] != '?') {
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//   } else if (C[idx] == '?' && J[idx] == '?') {
//     C[idx] = '0'; J[idx] = '0';
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     C[idx] = '1'; J[idx] = '0';
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     C[idx] = '0'; J[idx] = '1';
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     C[idx] = '0'; J[idx] = '9';
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     C[idx] = '9'; J[idx] = '0';
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//   } else if (C[idx] == '?') {
//     C[idx] = J[idx];
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     if (J[idx] < '9') {
//       C[idx] = (char) (J[idx] + 1);
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     } else {
//       C[idx] = '0';
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     }
//     if (J[idx] > '0') {
//       C[idx] = (char) (J[idx] - 1);
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     } else {
//       C[idx] = '9';
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     }
//   } else if (J[idx] == '?') {
//     J[idx] = C[idx];
//     makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     if (C[idx] < '9') {
//       J[idx] = (char) (C[idx] + 1);
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     } else {
//       J[idx] = '0';
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     }
//     if (C[idx] > '0') {
//       J[idx] = (char) (C[idx] - 1);
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     } else {
//       J[idx] = '9';
//       makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
//     }
//   }
// }

void makeScoresCloseHelper(string &bestC, string &bestJ, unsigned long long &minDifference,
                           string &C, string &J, int idx) {
  int N = C.length();
  if (idx == N) {
    unsigned long long intC = stoull(C);
    unsigned long long intJ = stoull(J);
    unsigned long long difference = intC >= intJ ? intC - intJ : intJ - intC;
    if (minDifference > difference) {
      minDifference = difference;
      bestC = C; bestJ = J;
    } else if (minDifference == difference) {
      if (C < bestC) {
        bestC = C; bestJ = J;
      } else if (C == bestC && J < bestJ) {
        bestC = C; bestJ = J;
      }
    }
  } else if (C[idx] != '?' && J[idx] != '?') {
    makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
  } else if (C[idx] == '?' && J[idx] == '?') {
    for (char i = '0'; i <= '9'; ++i) {
      for (char j = '0'; j <= '9'; ++j) {
        C[idx] = i; J[idx] = j;
        makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
      }
    }
    C[idx] = '?'; J[idx] = '?';
  } else if (C[idx] == '?') {
    for (char i = '0'; i <= '9'; ++i) {
      C[idx] = i;
      makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
    }    
    C[idx] = '?';
  } else if (J[idx] == '?') {
    for (char j = '0'; j <= '9'; ++j) {
      J[idx] = j;
      makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, idx + 1);
    }    
    J[idx] = '?';
  }  
}

pair<string, string> makeScoresClose(string &C, string &J) {
  int N = C.length();
  // exhaustive enumeration 3 possibilities at each point
  string bestC; string bestJ; unsigned long long minDifference = ULLONG_MAX;
  makeScoresCloseHelper(bestC, bestJ, minDifference, C, J, 0);
  return make_pair(bestC, bestJ);
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int T; cin >> T;
  for (int t = 1; t <= T; ++t) {
    string C, J; cin >> C >> J;
    pair<string, string> newScores = makeScoresClose(C, J);
    cout << "Case #" << t << ": "
         << newScores.first << ' ' << newScores.second
         << '\n';
  }
  cout << flush;
  return 0;
}
