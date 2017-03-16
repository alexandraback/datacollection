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

bool Can(int a, const string& s) {
  string A = Encode(a);
  for (int i = 0; i < N; i++) {
    if (s[i] == '?') continue;
    if (s[i] != A[i]) return false;
  }
  return true;
}

void Solve() {
  cin >> C >> J;
  N = C.length();
  int to = pow(10, N);

  string res = "";
  int minDiff = 1000;
  for (int a = 0; a < to; a++) {
    if (!Can(a, C)) continue;
    for (int b = 0; b < to; b++) {
      if (!Can(b, J)) continue;
      if (abs(b - a) < minDiff) {
        minDiff = abs(b - a);
      }
    }
  }
        
  int minAScore = 1000;
  int minBScore = 1000;

  for (int a = 0; a < to; a++) {
    if (!Can(a, C)) continue;
    for (int b = 0; b < to; b++) {
      if (!Can(b, J)) continue;
      if (abs(b - a) == minDiff) {
        if (a < minAScore) {
          res = Encode(a) + " " + Encode(b);
          minAScore = a;
          minBScore = b;
        } else if (a == minAScore && b < minBScore) {
          res = Encode(a) + " " + Encode(b);
          minAScore = a;
          minBScore = b;
        }
      }
    }
  }

  printf("%s", res.c_str());
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "small"; // practice, small, large
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
    stdoutFile = "./output/B-small-attempt1.out";
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
