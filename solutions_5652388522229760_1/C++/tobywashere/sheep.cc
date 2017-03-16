#include <iostream>

using namespace std;

bool seenDigits(int num, bool *digits)
{
  while (num > 0)
    {
      int last = num % 10;
      digits[last] = true;
      num /= 10;
    }
  for (int i = 0; i < 10; i++)
    {
      if (!digits[i])
	{
	  return false;
	}
    }
  return true;
}

int main()
{
  int T;
  cin >> T;
  for (int c = 0; c < T; c++)
    {
      int N;
      cin >> N;
      bool digits[10] = {false};
      if (N == 0)
	{
	  cout << "Case #" << (c+1) << ": INSOMNIA" << endl;
	  continue;
	}
      int i = 1;
      while (!seenDigits(i*N, digits))
	{
	  i += 1;
	}
      cout << "Case #" << (c+1) << ": " << (i*N) << endl;
    }
}
