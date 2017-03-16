#include <bits/stdc++.h>

using namespace std;

void Flip(string& S, int p) {
  reverse(S.begin(), S.begin() + p);
  for (int i = 0; i < p; i++) {
    S[i] = (S[i] == '+') ? '-' : '+';
  }
}

int Count(string S) {
  int res = 0;
  while (true) {
    if (S.find('-') == string::npos) break;  // all happy.

    // flip + sequence.
    if (S[0] == '+') {
      Flip(S, S.find('-'));
      res++;
    }

    if (S.find('+') == string::npos) {
      // flip all.
      Flip(S, S.size());
      res++;
    } else {
      // flip - sequence.
      Flip(S, S.find('+'));
      res++;
    }
  }
  fprintf(stderr, "%s\n", S.c_str());
  return res;
}

void Solve() {
  string S; cin >> S;
  string R = S; Flip(R, R.size());
  printf("%d", min(Count(S), Count(R) + 1));
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "small"; // practice, small, large
  const bool redirectStdoutToFile = true;
  const bool redirectStderrToFile = true;

  string inputFile = "";
  string stdoutFile = "";
  string stderrFile = "./out/B/B.stderr";

  if (problem == "practice") {
    inputFile  = "./data/B/B-practice.in";
    stdoutFile = "./out/B/B-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/B/B-small-attempt0.in";
    stdoutFile = "./out/B/B-small-attempt0.out";
  } else if (problem == "large") {
    inputFile  = "./data/B/B-large.in";
    stdoutFile = "./out/B/B-large.out";
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
