#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

int test_case_number_ = 0;
#define gout printf("Case #%d: ", ++test_case_number_),cout

const int MAXLEN = 2048;

vector<string> strReps = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void GreedyByIdentificator(int dig, char iden, int *counts, vector<int>& outputs) {
  while (counts[(int)iden]) {
    for (char ch : strReps[dig]) {
      --counts[(int)ch];
    }
    outputs.push_back(dig);
  }
}

void Solution() {
  string s;
  cin >> s;
  int counts[256];
  memset(counts, 0, sizeof(counts));
  for (char ch : s) {
    ++counts[(int)ch];
  }

  vector<int> output;
  GreedyByIdentificator(2, 'W', counts, output);
  GreedyByIdentificator(0, 'Z', counts, output);
  GreedyByIdentificator(4, 'U', counts, output);
  GreedyByIdentificator(1, 'O', counts, output);
  GreedyByIdentificator(3, 'R', counts, output);
  GreedyByIdentificator(8, 'T', counts, output);
  GreedyByIdentificator(5, 'F', counts, output);
  GreedyByIdentificator(6, 'X', counts, output);
  GreedyByIdentificator(7, 'S', counts, output);
  GreedyByIdentificator(9, 'N', counts, output);
  for (int i = 0; i < 256; ++i) {
    assert(!counts[i]);
  }
  gout;
  sort(output.begin(), output.end());
  for (int dig : output) {
    printf("%d", dig);
  }
  printf("\n");
}

int main() {
  for (int i = 0; i < 10; ++i) {
    sort(strReps[i].begin(), strReps[i].end());
  }

  int test_cases;
  cin >> test_cases;
  for (int t_case = 0; t_case < test_cases; ++t_case) {
    Solution();
  }

  return 0;
}
