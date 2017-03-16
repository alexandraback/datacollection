#include <bits/stdc++.h>

using namespace std;

void Solve() {
  int N; cin >> N;
  unordered_set<int> available;
  int res = 1;
  for (; res <= 100; res++) {
    int M = N * res;
    while (M) {
      available.insert(M % 10);
      M /= 10;
    }
    if (available.size() == 10) break;
  }

  if (available.size() < 10) {
    printf("INSOMNIA");
  } else {
    printf("%d", N * res);
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
  string stderrFile = "./out/A/A.stderr";

  if (problem == "practice") {
    inputFile  = "./data/A/A-practice.in";
    stdoutFile = "./out/A/A-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/A/A-small-attempt0.in";
    stdoutFile = "./out/A/A-small-attempt0.out";
  } else if (problem == "large") {
    inputFile  = "./data/A/A-large.in";
    stdoutFile = "./out/A/A-large.out";
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
