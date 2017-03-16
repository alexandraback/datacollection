
#include <iostream>
#include <set>
#include <fstream>
using namespace std;

void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    long N; in >> N;
    if (N == 0)
    {
      out << "Case #" << t << ": INSOMNIA" << endl;
      continue;
    }
    set<int> digits;
    int curN = N;
    while (true)
    {
      long n = curN;
      while (n > 0)
      {
        digits.insert(n%10);
        n /= 10;
      }
      if (digits.size() == 10)
      {
        out << "Case #" << t << ": " << curN << endl;
        break;
      }
      curN += N;
    }
  }
}

int main()
{
  ifstream fin("A-small-attempt0.in");
  ofstream fout("A-small-attempt0.out");
  run(fin, fout);
}

