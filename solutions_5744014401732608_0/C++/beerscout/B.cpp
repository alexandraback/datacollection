#include <iostream>
#include <vector>
#include <string>


using namespace std;


bool create(int B, long M, vector<string> &G)
{
  G.resize(B);
  for ( auto &g: G )
    g.resize(B, '0');
  vector<long> b(B);
  b[B - 1] = 1;
  for ( int i = B - 2; i >= 0; --i )
  {
    long r = M;
    for ( int j = i + 1; j < B; ++j )
      if ( b[j] <= r )
      {
        b[i] += b[j];
        r -= b[j];
        G[i][j] = '1';
      }
  }
  return b[0] == M;
}


int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    int B; long M;
    cin >> B >> M;
    vector<string> G;
    bool x = create(B, M, G);
    if ( x )
    {
      cout << "Case #" << t << ": POSSIBLE\n";
      for ( auto &g: G )
        cout << g << '\n';
    }
    else
      cout << "Case #" << t << ": IMPOSSIBLE\n";
  }
  return 0;
}
