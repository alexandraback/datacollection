#include <bits/stdc++.h>

using namespace std;

int N;
string S;

const string C[10] = {
  "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" 
};
  
int counts[10][26];
int A[26];

void Solve() {
  cin >> S;
  memset(counts, 0, sizeof(counts));
  for (int i = 0; i < 10; i++) {
    for (char c : C[i]) {
      counts[i][c - 'A']++;
    }
  }

  memset(A, 0, sizeof(A));
  for (char c : S) {
    A[c - 'A']++;
  }

  vector<pair<int, char>> keys = {
    { 0, 'Z' },
    { 2, 'W' },
    { 6, 'X' },
    { 4, 'U' },
    { 8, 'G' },
    { 3, 'R' },
    { 7, 'S' },
    { 5, 'F' },
    { 1, 'O' },
    { 9, 'I' }
  };

  vector<int> cs(10, 0);
  for (int i = 0; i < 10; i++) {
    auto key = keys[i];
    cs[key.first] = A[key.second - 'A'];
    for (char c : C[key.first]) {
      A[c - 'A'] -= cs[key.first];
    }
  }

  stringstream ss;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < cs[i]; j++) {
      ss << i;
    }
  }

  printf("%s", ss.str().c_str());
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "large"; // practice, small, large
  const bool redirectStdoutToFile = true;
  const bool redirectStderrToFile = true;

  string inputFile = "";
  string stdoutFile = "";
  string stderrFile = "./output/A.stderr";

  if (problem == "practice") {
    inputFile  = "./input/A-practice.in";
    stdoutFile = "./output/A-practice.out";
  } else if (problem == "small") {
    inputFile  = "./input/A-small-attempt1.in";
    stdoutFile = "./output/A-small-attempt1.out";
  } else if (problem == "large") {
    inputFile  = "./input/A-large.in";
    stdoutFile = "./output/A-large.out";
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
