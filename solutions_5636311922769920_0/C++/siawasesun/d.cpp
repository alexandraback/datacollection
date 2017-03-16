#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int K, C, S; scanf("%d %d %d", &K, &C, &S);
  for (int i = 1; i <= K; i++) {
    printf("%d", i);
    if (i < K) printf(" ");
  }
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "small"; // practice, small, large
  const bool redirectStdoutToFile = true;
  const bool redirectStderrToFile = true;

  string inputFile = "";
  string stdoutFile = "";
  string stderrFile = "./out/D/D.stderr";

  if (problem == "practice") {
    inputFile  = "./data/D/D-practice.in";
    stdoutFile = "./out/D/D-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/D/D-small-attempt0.in";
    stdoutFile = "./out/D/D-small-attempt0.out";
  } else if (problem == "large") {
    inputFile  = "./data/D/D-large.in";
    stdoutFile = "./out/D/D-large.out";
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
