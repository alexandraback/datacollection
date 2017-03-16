#include<iostream>
#include<fstream>
using namespace std;

unsigned long long reverseNum(unsigned long long i)
{
  unsigned long long ret = 0;
  while (i)
  {
    ret *= 10;
    ret += i % 10;
    i /= 10;
  }
  return ret;
}

unsigned long long  getNum(unsigned long long i)
{
  if (i / 10 == 0)
    return i;
  if (i % 10 == 0)
    return 1 + getNum(i - 1);
  unsigned long long int tmp = i;
  int digits = 0;
  while (tmp > 0)
  {
    tmp /= 10;
    digits ++;
  }
  int half = (digits + 1) / 2;
  unsigned long long lowermod = 1, fullmod = 1;
  for (int k = 0; k < digits; k ++)
  {
    if (k < half) lowermod *= 10;
    fullmod *= 10;
  }
  unsigned long long uppermod = fullmod / lowermod;
  unsigned long long revNum = reverseNum(i);
  return (i % lowermod) + (revNum % uppermod - (revNum % uppermod == 1)) + 1 + getNum(fullmod / 10 - 1);
}

int main()
{
  ifstream cin("pa.in");
  ofstream cout("pb.out");

  int t, T;
  cin >> T;
  for (t = 1; t <= T; t ++)
  {
    unsigned long long n;
    cin >> n;
    cout << "Case #" << t << ": ";
    cout << getNum(n) << endl;
  }
  return 0;
}
