#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

map<long long, long long> memo[100][100][2];

long long count(
  size_t pa,
  size_t pb,
  long long rema,
  long long remb,
  vector<long long>& a,
  vector<long long>& b,
  vector<int>& A,
  vector<int>& B)
{
  if (pa >= a.size() || pb >= b.size())
    return 0;
  auto it = memo[pa][pb][!!rema].find(rema ? rema : remb);
  if (it != memo[pa][pb][!!rema].end())
    return it->second;

cerr << "pa=" << pa << ",pb=" << pb << endl;
  long long result = 0;
  if (A[pa] == B[pb])
  {
    long long common = min(a[pa], b[pb]);
    size_t npa = pa, npb = pb;
    if (!(a[pa] -= common))
      ++npa;
    if (!(b[pb] -= common))
      ++npb;
cerr << "common type=" << A[pa] << ",length=" << common << endl;
    result = common + count(npa, npb, a[pa] - common, b[pb] - common, a, b, A, B);
    a[pa] += common;
    b[pa] += common;
  }
  long long resulta = count(pa + 1, pb, 0, 0, a, b, A, B);
  long long resultb = count(pa, pb + 1, 0, 0, a, b, A, B);
cerr << "result=" << result << ",rema=" << resultb << ",remb=" << resulta << endl;
  return memo[pa][pb][!!rema][rema ? rema : remb] = max(result, max(resulta, resultb));;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    return 1;
  cout << fixed << setprecision(6);
  ifstream in(argv[1]);
  int t;
  in >> t;
  for (int ti = 0; ti < t; ++ti)
  {
    int n, m;
    in >> n >> m;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        for (int k = 0; k < 2; ++k)
          memo[i][j][k].clear();

    vector<long long> a(n), b(m);
    vector<int> A(n), B(m);
    for (int i = 0; i < n; ++i)
    {
      in >> a[i] >> A[i];
    }
    for (int i = 0; i < m; ++i)
    {
      in >> b[i] >> B[i];
    }

    cout << "Case #" << 1 + ti << ": " << count(0, 0, 0, 0, a, b, A, B) << endl;
  }
  return 0;
}

