#include <bits/stdc++.h>

using namespace std;

int R, C, W;

void Input() {
  cin >> R >> C >> W;
}

int CertainLine(int c, int w) {
  if (c == w) {
    return w;
  } else {
    return (c - 1) / w + w;
  }
}

int Uncertain(int c, int w) {
  return c / w;
}

void Solve() {
  cout << Uncertain(C, W) * (R - 1) + CertainLine(C, W);
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "large"; // practice, small, large
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

  cerr << T << endl;

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");

    fprintf(stderr, "Finished: #%d\n\n", test_case);
  }

  cerr << "Finished all test cases\n\n";

  return 0;
}
