
#include <iostream>
#include <vector>
#include <fstream>
#include <limits>
using namespace std;

typedef unsigned long ulong;

ulong findmax(ulong c, ulong B)
{
  if (c == B) return 1;
  int res = 0;
  for (int i = c+1; i<=B; i++)
  {
    res += findmax(i, B);
  }
  return res;
}
void fill(vector<string>& res, ulong& cur, ulong max, ulong f, ulong l)
{
  if (cur >= max) return;
  for (int i = f+1; i < l; i++)
  {
    res[f-1][i-1] = '1';
    res[i-1][l-1] = '1';
    cur++;
    if (cur >= max) return;
  }
  for (int i = f+1; i < l; i++)
  {
    fill(res, cur, max, i, l);
  }
}
void solve(ulong B, ulong M, ostream& out)
{
  auto max = findmax(1, B);
  if (M > max)
  {
    out << "IMPOSSIBLE" << endl;
    return;
  }
  vector<string> res(B, string(B, '0'));
  res[0][B-1] = '1';
  ulong cnt = 1;
  fill(res, cnt, M, 1, B);
  out << "POSSIBLE" << endl;
  for (auto s : res) out << s << endl;
}

void run(istream& in, ostream& out)
{
  int T; in >> T;
  for (int t = 1; t <= T; t++)
  {
    int B; in >> B;
    int M; in >> M;
    out << "Case #" << t << ": ";
    solve(B, M, out);
  }
}

int main()
{
  ifstream fin("B-small.in");
  ofstream fout("B-small.out");
  run(fin, fout);
}

