#include <bits/stdc++.h>

using namespace std;

int B;
int64_t M;

void Solve() {
  cin >> B >> M;
  cerr << B << " " << M << endl;

  vector<vector<int>> res(B, vector<int>(B, 0));
  for (int i = 0; i < B; i++) {
    for (int j = i + 1; j < B; j++) {
      res[i][j] = 1;
    }
  }

  for (int i = 1; i < B; i++) {
    int c = B - 2 - i;
    int64_t cur = (c >= 0) ? 1LL << c : 1;
    if (cur > M) {
      res[0][i] = 0;
    } else {
      M -= cur;
    }
  }

  if (M > 0) {
    printf("IMPOSSIBLE");
    return;
  }

  // print result.
  printf("POSSIBLE\n");
  {
    for (int i = 0; i < B; i++) {
      for (int j = 0; j < B; j++) {
        printf("%d", res[i][j]);
      }
      if (i + 1 < B) printf("\n");
    }
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
  string stderrFile = "./output/B.stderr";

  if (problem == "practice") {
    inputFile  = "./input/B-practice.in";
    stdoutFile = "./output/B-practice.out";
  } else if (problem == "small") {
    inputFile  = "./input/B-small-attempt0.in";
    stdoutFile = "./output/B-small-attempt0.out";
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
