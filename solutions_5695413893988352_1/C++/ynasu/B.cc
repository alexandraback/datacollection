#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

namespace {

long long maximize(string S) {
  long long res = 0;
  for (char c : S) {
    res *= 10;
    res += (c == '?') ? 9 : (c - '0');
  }
  return res;
}

long long minimize(string S) {
  long long res = 0;
  for (char c : S) {
    res *= 10;
    res += (c == '?') ? 0 : (c - '0');
  }
  return res;
}

vector<string> Solve(string C, string J) {
  const int N = C.length();
  long long d = 1;
  for (int i = 0; i < N; ++i) {
    d *= 10;
  }

  long long best_c = -1;
  long long best_j = -1;
  long long current = 0;

  auto update = [&](long long c, long long j) {
    if (best_c < 0) {
      best_c = c;
      best_j = j;
    } else if (abs(c - j) <= abs(best_c - best_j)) {
      if (abs(c - j) < abs(best_c - best_j) ||
          c < best_c ||
          (c == best_c && j < best_j)) {
        best_c = c;
        best_j = j;
      }
    }
  };
  for (int i = 0; i < N; ++i) {
    d /= 10;
    if (C[i] != '?' && J[i] != '?') {
      long long c = current + d * (C[i] - '0');
      long long j = current + d * (J[i] - '0');
      if (c == j) {
        current = c;
        if (i == N - 1) {
          update(current, current);
        }
        continue;
      }
      if (c > j) {
        update(c + minimize(C.substr(i + 1)),
               j + maximize(J.substr(i + 1)));
      } else {
        update(c + maximize(C.substr(i + 1)),
               j + minimize(J.substr(i + 1)));
      }
      break;
    }
    if (C[i] != '?' && J[i] == '?') {
      int t = C[i] - '0';
      current += d * t;
      if (t > 0) {
        update(current + minimize(C.substr(i + 1)),
               current - d + maximize(J.substr(i + 1)));
      }
      if (t < 9) {
        update(current + maximize(C.substr(i + 1)),
               current + d + minimize(J.substr(i + 1)));
      }
    }
    if (C[i] == '?' && J[i] != '?') {
      int t = J[i] - '0';
      current += d * t;
      if (t > 0) {
        update(current - d + maximize(C.substr(i + 1)),
               current + minimize(J.substr(i + 1)));
      }
      if (t < 9) {
        update(current + d + minimize(C.substr(i + 1)),
               current + maximize(J.substr(i + 1)));
      }
    }
    if (C[i] == '?' && J[i] == '?') {
      update(current + d + minimize(C.substr(i + 1)),
             current + maximize(J.substr(i + 1)));
      update(current + maximize(C.substr(i + 1)),
             current + d + minimize(J.substr(i + 1)));
    }
    if (i == N - 1) {
      update(current, current);
    }
  }

  vector<string> res(2);
  stringstream ss;
  ss << setfill('0') << setw(N) << best_c;
  res[0] = ss.str();
  ss.str("");
  ss << setfill('0') << setw(N) << best_j;
  res[1] = ss.str();
  return res;
}

}

int main(void) {
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    string C, J;
    cin >> C >> J;
    cout << "Case #" << i << ":";
    for (string s : Solve(C, J)) {
      cout << ' ' << s;
    }
    cout << endl;
  }

  return 0;
}
