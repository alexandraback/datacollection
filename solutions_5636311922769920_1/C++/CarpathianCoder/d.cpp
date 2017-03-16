#include <iostream>

void solve_case(int case_num)
{
  long long k, c, s;

  std::cin >> k >> c >> s;
  std::cout << "CASE #" << case_num << ":";

  if (k > c * s) {
    std::cout << " IMPOSSIBLE" << std::endl;
  } else {
    for (int i = 0; i * c < k; i++) {
      long long b = 1;
      long long x = 0;
      for (int j = 0; j < c && i * c + j < k; j++, b *= k) {
        x += (i * c + j) * b;
      }
      std::cout << " " << x + 1;
    }
    std::cout << std::endl;
  }
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
