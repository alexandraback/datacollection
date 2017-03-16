#include <string>
#include <iostream>
using namespace std;
int smallGenerator(int x)
{
  return (1 << 7) + (x << 1) + 1;
}

int bigGenerator(int x)
{
  return (1 << 15) + (x << 1) + 1;
}

void printBits(int x)
{
  if (!x)
  {
    return;
  }

  printBits(x/2);
  cout << x%2;
}

long toBase10(long x, int base)
{
  if (x)
  {
    return toBase10(x/2, base) * base + (x%2);
  }

  return 0;
}

void printer(int x)
{
  printBits(x);
  printBits(x);
  for (int y = 2; y < 11; y++)
  {
    cout << " " << toBase10(x, y);
  }

  cout << endl;
}

int main()
{
  cout << "Case #1:" << endl;
  for (int x = 0; x < 50; x++)
  {
    printer(smallGenerator(x));
  }

  cout << "Case #1:" << endl;
  for (int x = 0; x < 500; x++)
  {
    printer(bigGenerator(x));
  }

  return 0;
}

