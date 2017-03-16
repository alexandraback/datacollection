#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void solve_case(int case_num)
{
  std::string s;
  std::vector<bool> v;

  std::cin >> s;
  std::cout << "CASE #" << case_num << ": ";

  for (char& ch : s) {
    bool b = (ch == '+');
    if (v.empty() || v.back() != b) {
      v.push_back(b);
    }
  }
  if (!v.empty() && v.back()) {
    v.pop_back();
  }

  std::cout << v.size() << std::endl;
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
