#include <map>
#include <vector>
#include <iostream>
using namespace std;
int counter(int x)
{
  int count = 0;
  while (x)
  {
    count |= (1 << (x%10));
    x /= 10;
  }

  return count;
}
int solve(int x)
{
  if (x == 0)
  {
    return 0;
  }

  int allDigits = 1023, current = 0, start = 0;
  while (current != allDigits)
  {
    start += x;
    current |= counter(start);
  }

  return start;
}
int main()
{
  int solutions[1000001], n;
  for (int x = 0; x < 1000001; x++)
  {
    solutions[x] = solve(x);
  }

  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cout << "Case #" << i << ": ";
    cin >> temp;
    if (!temp)
    {
      cout << "INSOMNIA";
    }
    else
    {
      cout << solutions[temp];
    }

    cout << endl;
  }

  return 0;
}

