#include <iostream>
#include <string>
#include <set>

using namespace std;

void addToSet(set<int> & digits, int k)
{
  while (k > 0)
  {
    digits.insert(k % 10);
    k = k / 10;
  }
}

int solve(int n)
{
  set<int> digits;
  int last = n;
  while (true)
  {
    addToSet(digits, last);
    if (digits.size() == 10)
      return last;
    last += n;
  }
}

int main()
{
  int t;
  cin >> t;
  
  for (int i = 1; i <= t; i++)
  {
    int n;
    cin >> n;
    cout << "Case #" << i << ": ";
    if (n == 0)
      cout << "INSOMNIA";
    else
      cout << solve(n);
    cout << endl;
  }
  
  return 0;
}
