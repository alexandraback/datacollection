#include <iostream>
#include <iomanip>
#include <vector>
#include <limits.h>
using namespace std;
typedef long long int int64;

int main()
{
  int T;
  cin >> T;

  for (int test_case = 1; test_case <= T; ++test_case)
  {
    int E, R, N;
    cin >> E >> R >> N;
    vector<int64> v(N + 1, 0);
    for (int i = 1; i <= N; ++i)
      cin >> v[i];

    vector< vector<int64> > m(N + 1, vector<int64>(E + 1, LONG_LONG_MIN));
    m[0][E] = 0;
    for (int i = 0; i < N; ++i)
    {
      for (int e = (i == 0) ? E : 1; e <= E; ++e)
      {
	for (int spend = 0; spend <= e; ++spend)
	{
	  int ne = min(e - spend + R, E);
	  m[i + 1][ne] = max(m[i + 1][ne], m[i][e] + spend * v[i + 1]);
	}
      }
    }

#if 0
    for (int e = E; e >= 0; --e)
    {
      cerr << setw(3) << e << ":";
      for (int i = 0; i <= N; ++i)
	cerr << setw(3) << m[i][e];
      cerr << endl;
    }
#endif

    int64 max_m = m[N][0];
    for (int e = 1; e <= E; ++e)
      max_m = max(max_m, m[N][e]);
    cout << "Case #" << test_case << ": " << max_m << endl;
  }

  return 0;
}

