#include <bits/stdc++.h>

using namespace std;

int64_t N;

#define CAST(x,type)  *({ostringstream oss; oss << (x); istringstream iss(oss.str()); static type _r; iss >> _r; &_r; })

void Input() {
  cin >> N;
}

int64_t dp[1000010];

int64_t go(int cur) {
  if (dp[cur] != -1) return dp[cur];

  int64_t& res = dp[cur];
  if (cur % 10 == 0) {
    res = go(cur - 1) + 1;
  } else {
    string s = CAST(cur, string);
    reverse(s.begin(), s.end());
    int64_t prev = CAST(s, int64_t);
    if (prev < cur) {
      res = min(go(cur - 1), go(prev)) + 1;
    } else {
      res = go(cur - 1) + 1;
    }
  }
  return res;
}

void Prepare() {
  memset(dp, -1, sizeof(dp));
  dp[1] = 1;
  go(1000001);
}

void Solve() {
  cout << dp[N];
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;

  const string problem = "small"; // practice, small, large
  const bool outputToStdout = true;

  string inputFile = "";
  string outputFile = "";

  if (problem == "practice") {
    inputFile  = "./data/A/A-practice.in";
    outputFile = "./data/A/A-practice.out";
  } else if (problem == "small") {
    inputFile  = "./data/A/A-small-attempt1.in";
    outputFile = "./data/A/A-small-attempt1.out";
  } else if (problem == "large") {
    inputFile  = "./data/A/A-large.in";
    outputFile = "./data/A/A-large.out";
  }

  freopen(inputFile.c_str(), "r", stdin);
  if (outputToStdout) freopen(outputFile.c_str(), "w", stdout);

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  if (outputToStdout) fprintf(stderr, "Write to output: %s\n", outputFile.c_str());

  int T;
  string line;
  {
    getline(cin, line);
    istringstream is(line);
    is >> T;
  }

  Prepare();
  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }

  return 0;
}
