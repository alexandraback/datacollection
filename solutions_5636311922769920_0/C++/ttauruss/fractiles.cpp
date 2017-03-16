
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

using ulong = unsigned long;

void solve(ulong K, ulong C, ostream& out)
{
  ulong offset = 1;
  for (int i = 0; i < C-1; i++) offset *= K;
  for (int i = 0; i < K; i++)
  {
    out << " " << (offset*i + 1);
  }
}

void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    int K; in >> K;
    int C; in >> C;
    int S; in >> S; // = K for small input
    out << "Case #" << t << ": ";
    solve(K, C, out);
    out << endl;
  }
}

int main()
{
  ifstream fin("D-small-attempt0.in");
  ofstream fout("D-small.out");
  run(fin, fout);
}

