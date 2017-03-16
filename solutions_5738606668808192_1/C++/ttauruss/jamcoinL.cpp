
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include "bigint/BigIntegerLibrary.hh"
using namespace std;

BigInteger convert(int N, long cnt, int b)
{
  BigInteger res = 0;
  long curbit = 1;
  BigInteger mult = b;
  for (int i = 0; i < (N-2); i++)
  {
    if (curbit & cnt) res += mult;
    mult *= b;
    curbit <<= 1;
  }
  return res;
}

bool finddiv(BigInteger n, long& div)
{
  for (div = 3; 1000 > div*div; div++)
  {
    if (n % div == 0) return true;
  }
  return false;
}

BigInteger mpow(long b, int p)
{
  BigInteger res = b;
  while (p - 1 > 0)
  {
    p--;
    res *= b;
  }
  return res;
}

void solve(int N, int J, ostream& out)
{
  vector<BigInteger> mins(11);
  for (int b = 2; b <= 10; b++)
  {
    mins[b] = mpow(b, N-1) + 1;
  }
  for (long cnt = 0; J > 0 and cnt < (1<<(N-2)); cnt++)
  {
    vector<long> divs(11);
    int b;
    for (b = 2; b <= 10; b++)
    {
      BigInteger num = mins[b] + convert(N, cnt, b);
      if (not finddiv(num, divs[b]))
      {
        break;
      }
    }
    if (b == 11)
    {
      out << "1";
      long curbit = (1<<(N-3));
      while (curbit > 0)
      {
        if (cnt & curbit) out << "1";
        else out << "0";
        curbit >>= 1;
      }
      out << "1";
      for (int b = 2; b <= 10; b++)
      {
        out << " " << divs[b];
      }
      out << endl;
      J--;
    }
  }
}

void run(istream& in, ostream& out)
{
  int T; in >> T;
  out << "Case #1:" << endl;
  for (int t = 1; t <= T; t++)
  {
    int N; in >> N;
    int J; in >> J;
    solve(N, J, out);
  }
}

int main()
{
  ifstream fin("1.txt");
  ofstream fout("C-large.out");
  run(fin, fout);
}

