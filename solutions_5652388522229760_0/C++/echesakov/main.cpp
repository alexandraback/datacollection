#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int lastNumber(int N)
{
  vector<int> a;

  do
  {
    a.push_back(N % 10);
    N /= 10;
  } while (N);

  const vector<int> b(a);
  vector<bool> digits(10);

  for (;;)
  {
    for (int i = 0; i < a.size(); ++i)
    {
      digits[a[i]] = true;
    }

    bool eachDigit = true;

    for (int i = 0; eachDigit && (i < digits.size()); ++i)
    {
      eachDigit = eachDigit && digits[i];
    }

    if (eachDigit)
    {
      int lastNumber = 0;

      for (int i = a.size() - 1; i >= 0; --i)
      {
        lastNumber = a[i] + 10 * lastNumber;
      }

      return lastNumber;
    }

    int carry = 0;

    for (int i = 0; i < b.size(); ++i)
    {
      const int sum = a[i] + b[i] + carry;
      carry = (sum > 9) ? 1 : 0;
      a[i] = (sum > 9) ? (sum - 10) : sum;
    }

    for (int i = b.size(); carry && (i < a.size()); ++i)
    {
      const int sum = a[i] + carry;
      carry = (sum > 9) ? 1 : 0;
      a[i] = (sum > 9) ? (sum - 10) : sum;
    }

    if (carry)
    {
      a.push_back(carry);
    }
  }
}

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    int N;
    cin >> N;

    cout << "Case #" << (i + 1) << ": ";
    if (N)
    {
      cout << lastNumber(N) << endl;
    }
    else
    {
      cout << "INSOMNIA" << endl;
    }
  }
}