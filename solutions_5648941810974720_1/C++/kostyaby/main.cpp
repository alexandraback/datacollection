#include <bits/stdc++.h>

using namespace std;

map<char, int> get_histogram(const string &s) {
  map<char, int> result;

  for (char c : s) {
    result[c] += 1;
  }

  return result;
}

void process(map<char, int> &histogram, vector<int> &answer, int digit, char cdigit, const string &word) {
  int cnt = histogram[cdigit];

  answer[digit] += cnt;

  for (char c : word) {
    histogram[c] -= cnt;
  }
}

void solve(int case_id) {
  string s; cin >> s;

  map<char, int> histogram = get_histogram(s);
  vector<int> answer(10);

  process(histogram, answer, 0, 'Z', "ZERO");
  process(histogram, answer, 6, 'X', "SIX");
  process(histogram, answer, 2, 'W', "TWO");
  process(histogram, answer, 8, 'G', "EIGHT");
  process(histogram, answer, 3, 'H', "THREE");
  process(histogram, answer, 4, 'U', "FOUR");
  process(histogram, answer, 5, 'F', "FIVE");
  process(histogram, answer, 1, 'O', "ONE");
  process(histogram, answer, 9, 'I', "NINE");
  process(histogram, answer, 7, 'V', "SEVEN");

  string result = "";
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < answer[i]; j++) {
      result += '0' + i;
    }
  }

  cout << "Case #" << case_id << ": " << result << "\n";
}

int main() {
  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}