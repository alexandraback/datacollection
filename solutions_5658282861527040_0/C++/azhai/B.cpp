#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int L = 32;
const int LEN_MAX = L + 5;
int A[LEN_MAX];
int B[LEN_MAX];
int K[LEN_MAX];
int trace[2][LEN_MAX];

void make_binary(long long x, int *X) {
  for (int i = 0; i < L; i++)
    X[i] = 0;

  int idx = 0;
  while (x > 0) {
    X[idx++] = (x % 2 == 0 ? 0 : 1);
    x /= 2;
  }
}

void init() {
  long long a, b, k;
  cin >> a >> b >> k;

  // int ct = 0;
  // for (int i = 0; i < a; i++)
  //   for (int j = 0; j < b; j++)
  //     if ((i & j) < k)
  //       ct++;
  // cout << "ct " << ct << endl;

  make_binary(a, A);
  make_binary(b, B);
  make_binary(k, K);
  memset(trace, 0, sizeof(trace));
}

void print_status() {
  cout << "A: ";
  for (int i = 0; i < L; i++)
    cout << A[i];
  cout << endl << "B: ";
  for (int i = 0; i < L; i++)
    cout << B[i];
  cout << endl << "K: ";
  for (int i = 0; i < L; i++)
    cout << K[i];
  cout << endl;

  cout << "trace 0: ";
  for (int i = 0; i < L; i++)
    cout << trace[0][i];
  cout << endl << "trace 1: ";
  for (int i = 0; i < L; i++)
    cout << trace[1][i];
  cout << endl;
}

void compute_trace(int suffixA, int suffixB) {
  memset(trace, 0, sizeof(trace));

  for (int i = 0; i < L; i++) {
    bool fixedA = (i >= suffixA);
    bool fixedB = (i >= suffixB);

    if (fixedA && fixedB) {
      bool a_and_b = (A[i] == 1) && (B[i] == 1);
      if (a_and_b)
        trace[1][i] = 1;
      else
        trace[0][i] = 1;
    } else if ((!fixedA) && (!fixedB)) {
      trace[1][i] = 1;
      trace[0][i] = 3;
    } else if (fixedA && (!fixedB)) {
      trace[1][i] = (A[i] == 1 ? 1 : 0);
      trace[0][i] = (A[i] == 1 ? 1 : 2);
    } else if ((!fixedA) && fixedB) {
      trace[1][i] = (B[i] == 1 ? 1 : 0);
      trace[0][i] = (B[i] == 1 ? 1 : 2);
    }
  }
}

long long num_ways(int suffixA, int suffixB, int suffixK) {
  compute_trace(suffixA, suffixB);

  //  cout << suffixA << ", " << suffixB << ", " << suffixK << endl;
  //  print_status();

  long long ans = 1;

  for (int i = 0; i < L; i++) {
    bool fixedK = (i >= suffixK);
    if (fixedK) {
      ans *= trace[K[i]][i];
    } else {
      ans *= trace[0][i] + trace[1][i];
    }
  }

  //  cout << "got " << ans << endl << endl;
  return ans;
}

void solve_case(int t) {
  init();

  long long ans = 0;

  // num to fix
  for (int i = 0; i < L; i++) {
    if (A[i] == 0)
      continue;
    A[i] = 0;
    for (int j = 0; j < L; j++) {
      if (B[j] == 0)
        continue;
      B[j] = 0;
      for (int k = 0; k < L; k++) {
        if (K[k] == 0)
          continue;
        K[k] = 0;
        ans += num_ways(i, j, k);
        K[k] = 1;
      }
      B[j] = 1;
    }
    A[i] = 1;
  }

  cout << "Case #" << t << ": " << ans << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
