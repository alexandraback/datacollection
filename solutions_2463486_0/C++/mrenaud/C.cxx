#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

using ull = unsigned long long;

bool is_palindrome(std::string const& str)
{
  auto i = str.begin();
  auto iEnd = str.end();

  // Empty or 1 element.
  if (i == iEnd || i == --iEnd)
    return true;

  for (;;)
  {
    if (*i != *iEnd)
      return false;

    // Move i forward.
    ++i;
    if (i == iEnd)
      break;

    // Move iEnd backwards.
    --iEnd;
    if (i == iEnd)
      break;
  }

  return true;
}

bool is_s_and_f(ull n)
{
  std::stringstream ss;
  ss << n;

  // If not a palindrome, not square and fair.
  if (!is_palindrome(ss.str()))
    return false;

  ull sq_root = sqrt(n);

  // If not the square of a number, not square and fair.
  if (sq_root * sq_root != n)
    return false;

  // If it is, it better be a palindrome.
  ss.str("");
  ss << sq_root;

  return is_palindrome(ss.str());
}

void solve()
{
  ull a, b;
  std::cin >> a >> b;

  // -1 : unknown
  // 0  : not square and fare
  // 1  : square and fair
  static std::vector<int> s_and_f;


  if (b + 1 > s_and_f.size())
    s_and_f.resize(b + 1, -1);

  ull count = 0;

  for (; a <= b; ++a)
  {
    if (s_and_f[a] == -1)
    {
      if (is_s_and_f(a))
        s_and_f[a] = 1;
      else
        s_and_f[a] = 0;
    }

    count += s_and_f[a];
  }

  std::cout << count << "\n";
}


int main()
{
  int N;
  std::cin >> N;

  for (int i = 1; i <= N; ++i)
  {
    std::cout << "Case #" << i << ": ";
    solve();
  }
}
