#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

const char *letters[] = {
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

void solve_case(int case_num)
{
  std::string s;
  std::map<char, int> m;
  std::vector<int> nums(10);

  std::cin >> s;
  std::cout << "CASE #" << case_num << ": ";

  for (char& ch : s) {
    m[ch] += 1;
  }

  nums[8] = m['G'];
  nums[4] = m['U'];
  nums[2] = m['W'];
  nums[6] = m['X'];
  nums[0] = m['Z'];

  for (int i = 0; i < 10; i += 2) {
    size_t len = strlen(letters[i]);
    for (size_t j = 0; j < len; j++) {
      m[letters[i][j]] -= nums[i];
    }
  }

  nums[5] = m['F'];
  nums[3] = m['H'];
  nums[1] = m['O'];
  nums[7] = m['S'];

  for (int i = 1; i < 9; i += 2) {
    size_t len = strlen(letters[i]);
    for (size_t j = 0; j < len; j++) {
      m[letters[i][j]] -= nums[i];
    }
  }

  nums[9] = m['I'];

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < nums[i]; j++) {
      std::cout << i;
    }
  }
  std::cout << std::endl;
}

int main()
{
  int num_cases;

  std::cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    solve_case(i);
  }
  
  return 0;
}
