#include <bits/stdc++.h>

using namespace std;

const int MAX_D = 1010;
const int MAX_P = 1010;

int D;
int P[MAX_D];

void Prepare() {
}

void Input() {
  cin >> D;
  for (int i = 0; i < D; i++) {
    cin >> P[i];
  }
}

void Solve() {
  int counts[MAX_P];
  memset(counts, 0, sizeof(counts));
  for (int i = 0; i < D; i++) counts[P[i]]++;

  int res = MAX_P;

  for (int eat = 1; eat < MAX_P; eat++) {
    int divide_count = 0;
    for (int k = eat + 1; k < MAX_P; k++) {
      divide_count += (k - 1) / eat * counts[k];
    }
    res = min(res, eat + divide_count);
  }

  cout << res;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  //  string inputFile  = "./data/B-practice.in";
  //  string outputFile = "./data/B-practice.out";
  string inputFile  = "./data/B-small-attempt1.in";
  string outputFile = "./data/B-small-attempt1.out";
  //  string inputFile  = "./data/B-large.in";
  //  string outputFile = "./data/B-large.out";

  freopen(inputFile.c_str(), "r", stdin);
  freopen(outputFile.c_str(), "w", stdout);

  fprintf(stderr, "Read from input: %s\n", inputFile.c_str());
  fprintf(stderr, "Write to output: %s\n", outputFile.c_str());

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
