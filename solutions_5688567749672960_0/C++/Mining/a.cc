#include <cstdlib>
#include <string>
#include <iostream>
#include <utility>

std::string& reverse(std::string &s)
{
  for (int i = 0; i < s.size()/2; i++) {
    std::swap(s[i], s[s.size()-1-i]);
  }
  return s;
}

std::string& decrement(std::string &s)
{
  int i = s.size() - 1;
  while (s[i] == '0') {
    s[i--] = '9';
  }
  s[i] -= 1;
  if (s[0] == '0') {
    s.erase(s.begin());
  }
  return s;
}

bool good_format(std::string s)
{
  if (s.size() == 1)
    return false;
  if (s.size() == 2 && s[0] != '1' && s[1] == '1')
    return true;
  int val = atoi(s.c_str());
  if ()
    return true;
  return false;
}

int solve(std::string s)
{
  int steps = 1;
  while (s != "1") {
    while (!good_format(s)) {
      decrement(s);
      steps++;
      if (s == "1") {
        return steps;
      }
    }
    reverse(s);
    decrement(s);
    steps += 2;
  }
  return steps;
}

int main()
{
  int c;
  std::cin >> c;
  for (int i = 1; i <= c; i++) {
    std::string s;
    std::cin >> s;
    std::cout << "Case #" << i << ": " << solve(s) << std::endl;
  }
  return 0;
}
