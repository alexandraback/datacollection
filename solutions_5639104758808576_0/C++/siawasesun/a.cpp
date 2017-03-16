#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 1010;

int S;
int A[MAX_S];

void Input() {
  cin >> S;
  char c;
  scanf("%c", &c);
  for (int i = 0; i <= S; i++) {
    scanf("%c", &c);
    A[i] = c - '0';
  }
  scanf("%c", &c);
}

void Solve() {
  int current_total = 0;
  int res = 0;
  for (int i = 0; i <= S; i++) {
    res = max(res, (i - current_total));
    current_total += A[i];
  }

  cout << res;
}

int main(int argc, char **argv) {
  (void)argc;
  (void)argv;
  //  string inputFile  = "./data/A-practice.in";
  //  string outputFile = "./data/A-practice.out";
  string inputFile  = "./data/A-small-attempt0.in";
  string outputFile = "./data/A-small-attempt0.out";
  //  string inputFile  = "./data/A-large.in";
  //  string outputFile = "./data/A-large.out";

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

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }

  return 0;
}
