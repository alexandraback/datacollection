#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 110;
const int MAX_L = 110;

int K, L, S;
string key;
string goal;

void Input() {
  cin >> K >> L >> S;
  cin >> key;
  cin >> goal;
}

double dp[MAX_S][MAX_L];

double Optimal() {
  int samePos = -1;
  for (int a = 1; a < goal.size(); a++) {
    string rest = goal.substr(a);
    if (goal.find(rest) == 0) {
      samePos = a;
      break;
    }
  }

  if (samePos == -1) {
    return S / goal.size();
  } else {
    int right = goal.length();
    int total = 1;
    while (true) {
      if (right + samePos <= S) {
        right += samePos;
        total++;
      } else {
        break;
      }
    }
    return total;
  }
}

void Solve() {
  for (int turn = 0; turn < MAX_S; turn++) {
    for (int completed = 0; completed < MAX_L; completed++) {
      dp[turn][completed] = 0.0;
    }
    dp[turn][0] = 1.0;
  }

  vector<int> counts(26, 0);
  int total = key.size();
  for (char c : key) counts[c - 'A']++;

  for (char c : goal) {
    if (counts[c - 'A'] == 0) {
      cout << 0;
      return;
    }
  }
  
  vector<double> prob(26, 0.0);
  for (int i = 0; i < 26; i++) prob[i] = (double)counts[i] / total;

  for (int turn = 1; turn <= S; turn++) {
    for (int completed = 1; completed <= L; completed++) {
      double p = prob[goal[completed - 1] - 'A'];
      dp[turn][completed] = dp[turn - 1][completed - 1] * p;
    }
  }

  double pay = 0.0;
  for (int turn = 0; turn <= S; turn++) {
    pay += dp[turn][L];
  }

  double bananas = Optimal();
  cout << bananas - pay;
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
