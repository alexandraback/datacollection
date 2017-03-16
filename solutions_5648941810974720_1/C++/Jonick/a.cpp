#include <bits/stdc++.h>

using namespace std;

const vector<string> DIGITS = {
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};

void solveTest() {
  std::string s;
  cin >> s;
  array<int, 26> counts = {{0}};
  for (int i = 0; i < s.size(); i++) {
    counts[s[i] - 'A']++; 
  }

  auto canApply = [](int dig, const auto& counts) {
    for (int i = 0; i < DIGITS[dig].size(); i++) {
      if (counts[DIGITS[dig][i] - 'A'] <= 0) {
	return false;
      }
    }
    return true;
  };

  auto apply = [](int dig, auto& a) {
    for (int i = 0; i < DIGITS[dig].size(); i++) {
      a[DIGITS[dig][i] - 'A']++;
    }
  };

  auto applyDig = [](int dig, auto& a) {
    for (int i = 0; i < DIGITS[dig].size(); i++) {
      a[DIGITS[dig][i] - 'A']--;
    }
  };
  
  auto isUniq = [](int dig, const auto& a) {
    for (int i = 0; i < DIGITS[dig].size(); i++) {
      if (a[DIGITS[dig][i] - 'A'] == 1) {
	return true;
      }
    }
    return false;
  };
  
  array<int, 10> res = {{0}};
  while (true) {
    bool applied = false;
    array<int, 26> rr = {{0}};
    for (int i = 0; i < 10; i++) {
      if (canApply(i, counts)) {
	apply(i, rr);
	applied = true;
      }
    }
    if (!applied) {
      break;
    }
    for (int i = 0; i < 10; i++) {
      if (canApply(i, counts) && isUniq(i, rr)) {
	res[i]++;
	applyDig(i, counts);
	break;
      }
    }
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < res[i]; j++) {
      cout << i;
    }
  }
  cout << "\n";
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    solveTest();
  }
  return 0;
}
