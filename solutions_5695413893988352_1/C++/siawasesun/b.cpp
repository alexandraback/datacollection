#include <bits/stdc++.h>

using namespace std;

string C, J;
int N;

string Encode(int a) {
  string res = "";
  while (a) {
    res += '0' + a % 10;
    a /= 10;
  }
  while (res.size() < N) {
    res += "0";
  }
  reverse(res.begin(), res.end());
  return res;
}

int64_t Decode(const string& a) {
  int64_t res = 0;
  for (int i = 0; i < N; i++) {
    res = res * 10 + a[i];
  }
  return res;
}

bool Can(int a, const string& s) {
  string A = Encode(a);
  for (int i = 0; i < N; i++) {
    if (s[i] == '?') continue;
    if (s[i] != A[i]) return false;
  }
  return true;
}

bool CanEqual() {
  for (int i = 0; i < N; i++) {
    if (C[i] == '?' || J[i] == '?') continue;
    if (C[i] != J[i]) return false;
  }
  return true;
}

bool SolveLarge(string& A, string& B, int k) {
  for (int i = 0; i <= k - 1; i++) {
    if (A[i] == '?' && B[i] == '?') {
      A[i] = '0';
      B[i] = '0';
    } else if (A[i] == '?') {
      A[i] = B[i];
    } else if (B[i] == '?') {
      B[i] = A[i];
    } else if (A[i] < B[i]) {
      return false;
    }
  }

  if (A[k] == '?' && B[k] == '?') {
    A[k] = '1';
    B[k] = '0';
  } else if (A[k] == '?') {
    if (B[k] == '9') return false;
    A[k] = B[k] + 1;
  } else if (B[k] == '?') {
    if (A[k] == '0') return false;
    B[k] = A[k] - 1;
  } else if (A[k] < B[k]) {
    return false;
  }

  for (int i = k + 1; i < N; i++) {
    if (A[i] == '?') A[i] = '0';
    if (B[i] == '?') B[i] = '9';
  }

  return true;
}

void Solve() {
  cin >> C >> J;
  N = C.length();
  int to = pow(10, N);

  if (CanEqual()) {
    for (int i = 0; i < N; i++) {
      if (C[i] == '?') C[i] = (J[i] == '?') ? '0' : J[i];
    }
    string res = C + " " + C;
    printf("%s", res.c_str());
    return;
  }

  int64_t least = 1e18;
  int64_t leastA = 1e18;
  int64_t leastB = 1e18;
  string res = "";

  for (int k = 0; k < N; k++) {
    string A = C, B = J;
    if (SolveLarge(A, B, k)) {
      int64_t diff = abs(Decode(A) - Decode(B));
      if (least > diff) {
        least = diff;
        leastA = Decode(A);
        leastB = Decode(B);
        res = A + " " + B;
      } else if (least == diff && leastA > Decode(A)) {
        least = diff;
        leastA = Decode(A);
        leastB = Decode(B);
        res = A + " " + B;
      } else if (least == diff && leastA == Decode(A) && leastB > Decode(B)) {
        least = diff;
        leastA = Decode(A);
        leastB = Decode(B);
        res = A + " " + B;
      }
      cerr << A << " " << B << endl;
    }

    A = J, B = C;
    if (SolveLarge(A, B, k)) {
      int64_t diff = abs(Decode(A) - Decode(B));
      if (least > diff) {
        least = diff;
        leastA = Decode(B);
        leastB = Decode(A);
        res = B + " " + A;
      } else if (least == diff && leastA > Decode(B)) {
        least = diff;
        leastA = Decode(B);
        leastB = Decode(A);
        res = B + " " + A;
      } else if (least == diff && leastA == Decode(B) && leastB > Decode(A)) {
        least = diff;
        leastA = Decode(B);
        leastB = Decode(A);
        res = B + " " + A;
      }
      cerr << A << " " << B << endl;
    }
  }

  cout << res;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "large"; // practice, small, large
  const bool redirectStdoutToFile = true;
  const bool redirectStderrToFile = true;

  string inputFile = "";
  string stdoutFile = "";
  string stderrFile = "./output/B.stderr";

  if (problem == "practice") {
    inputFile  = "./input/B-practice.in";
    stdoutFile = "./output/B-practice.out";
  } else if (problem == "small") {
    inputFile  = "./input/B-small-attempt1.in";
    stdoutFile = "./output/B-small-attempt2.out";
  } else if (problem == "large") {
    inputFile  = "./input/B-large.in";
    stdoutFile = "./output/B-large.out";
  }

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  if (redirectStdoutToFile) fprintf(stderr, "Redirect stdout: %s\n", stdoutFile.c_str());
  if (redirectStdoutToFile) fprintf(stderr, "Redirect stderr: %s\n", stderrFile.c_str());

  assert(freopen(inputFile.c_str(), "r", stdin) != nullptr);
  if (redirectStdoutToFile) freopen(stdoutFile.c_str(), "w", stdout);
  if (redirectStderrToFile) freopen(stderrFile.c_str(), "w", stderr);

  int T = 0;
  string line;
  {
    getline(cin, line);
    istringstream is(line);
    is >> T;
  }

  fprintf(stderr, "# of cases: %d\n", T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");

    fprintf(stderr, "Finished: #%d\n", test_case);
  }

  fprintf(stderr, "Finished all test cases\n");

  return 0;
}
