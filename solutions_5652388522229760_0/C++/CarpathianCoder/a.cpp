#include <iostream>
#include <algorithm>

#define NUM_DIGITS 10

void fill_digits(int x, int *digits)
{
  while (x > 0) {
    digits[x % NUM_DIGITS] = 1;
    x /= NUM_DIGITS;
  }
}

bool any_zero(int *digits)
{
  return std::find(digits, digits + NUM_DIGITS, 0) != digits + NUM_DIGITS;
}

void solve_case(int case_num)
{
  int digits[NUM_DIGITS];
  int n;

  std::cin >> n;
  std::fill(digits, digits + NUM_DIGITS, 0);

  std::cout << "CASE #" << case_num << ": ";

  long long factor = 1;
  while (n > 0 && n % NUM_DIGITS == 0) {
    digits[0] = 1;
    n /= NUM_DIGITS;
    factor *= NUM_DIGITS;
  }
  
  if (n == 0) {
    std::cout << "INSOMNIA" << std::endl;
  } else {
    int x = n;
    for (; any_zero(digits); x += n) {
      fill_digits(x, digits);
    }
    std::cout << (x - n) * factor << std::endl;
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
