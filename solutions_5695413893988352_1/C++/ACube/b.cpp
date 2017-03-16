#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int test_case_number_ = 0;
#define gout printf("Case #%d: ", ++test_case_number_),cout

const long long inf = 1LL<<62;

int N;
int C[20], J[20];

long long best[20];
int type[20], whoC[20], whoJ[20];

void DP(int u) {
  if (u == N) {
    return;
  }

  DP(u + 1);

  for (int cd = 0; cd <= 9; ++cd) {
    for (int jd = 0; jd <= 9; ++jd) {
      if (cd != C[u] && C[u] != -1) {
        continue;
      }
      if (jd != J[u] && J[u] != -1) {
        continue;
      }

      // Find out current difference.
      long long diff = cd - jd;
      for (int i = u + 1; i < N; ++i) {
        diff *= 10;
      }

      if (diff < 0) {
        long long curCandidate = 0;
        for (int i = u + 1; i < N; ++i) {
          curCandidate *= 10;
          if (C[i] == -1) {
            curCandidate += 9;
          } else {
            curCandidate += C[i];
          }
          if (J[i] == -1) {
            curCandidate -= 0;
          } else {
            curCandidate -= J[i];
          }
        }
        curCandidate = abs(curCandidate + diff);
        // Check if best.
        if (curCandidate < best[u]) {
          best[u] = curCandidate;
          type[u] = 0;
          whoC[u] = cd;
          whoJ[u] = jd;
        }
      } else if (diff > 0) {
        long long curCandidate = 0;
        for (int i = u + 1; i < N; ++i) {
          curCandidate *= 10;
          if (C[i] == -1) {
            curCandidate += 0;
          } else {
            curCandidate += C[i];
          }
          if (J[i] == -1) {
            curCandidate -= 9;
          } else {
            curCandidate -= J[i];
          }
        }
        curCandidate = abs(curCandidate + diff);
        // Check best.
        if (curCandidate < best[u]) {
          best[u] = curCandidate;
          type[u] = 1;
          whoC[u] = cd;
          whoJ[u] = jd;
        }
      } else {
        long long curCandidate = best[u + 1];
        if (curCandidate < best[u]) {
          best[u] = curCandidate;
          type[u] = 2;
          whoC[u] = cd;
          whoJ[u] = jd;
        }
      }
    }
  }
  //cerr << "Here for u = " << u << " "  << minPos[u] << " " << maxPos[u] << " " << minNeg[u] << " " << maxNeg[u] << endl;
}

void RecoverDP(int u, string& Cans, string& Jans) {
  if (u == N) {
    return;
  }
  Cans += whoC[u] + '0';
  Jans += whoJ[u] + '0';
  //cerr << "u=" << u << " type[u]=" << type[u] << endl;
  if (type[u] == 2) {
    RecoverDP(u + 1, Cans, Jans);
    return;
  }
  for (int i = Cans.size(); i < N; ++i) {
    if (C[i] == -1) {
      if (type[u] == 1) {
        Cans += '0';
      } else {
        Cans += '9';
      }
    } else {
      Cans += C[i] + '0';
    }
    if (J[i] == -1) {
      if (type[u] == 1) {
        Jans += '9';
      } else {
        Jans += '0';
      }
    } else {
      Jans += J[i] + '0';
    }
  }
}

void Solution() {
  // Parse input.
  string Cstr, Jstr;
  cin >> Cstr >> Jstr;
  N = Cstr.size();
  for (int i = 0; i < N; ++i) {
    C[i] = Cstr[i] == '?' ? -1 : (Cstr[i] - '0');
    J[i] = Jstr[i] == '?' ? -1 : (Jstr[i] - '0');
  }

  // Initialize dp values.
  for (int i = 0; i < N; ++i) {
    best[i] = inf;
  }
  best[N] = 0;

  // Run dp.
  DP(0);
  string Cans, Jans;
  RecoverDP(0, Cans, Jans);
  //cerr << "Best[u]=" << best[0] << endl;
  gout << Cans << " " << Jans << endl;
}

int main() {
  int test_cases;
  cin >> test_cases;
  for (int t_case = 0; t_case < test_cases; ++t_case) {
    Solution();
  }

  return 0;
}
