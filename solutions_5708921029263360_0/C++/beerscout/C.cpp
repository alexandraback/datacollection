#include <vector>
#include <iostream>
#include <tuple>
#include <cstring>

using namespace std;


int JP[11][11], JS[11][11], PS[11][11];
bool JPS[11][11][11];


vector<tuple<int, int, int>> best, current;

int J, P, S, K;

void check()
{
  if ( current.size() > best.size() )
    best = current;
  for ( int j = 0; j < J; ++j )
    for ( int p = 0; p < P; ++p )
      for ( int s = 0; s < S; ++s )
        if ( !JPS[j][p][s] )
        {
          JPS[j][p][s] = true;
          if ( JP[j][p] < K && JS[j][s] < K && PS[p][s] < K )
          {
            ++JP[j][p]; ++JS[j][s]; ++PS[p][s];
            current.emplace_back(j, p, s);
            check();
            current.pop_back();
            --JP[j][p]; --JS[j][s]; --PS[p][s];
          }
          //JPS[j][p][s] = false;
        }
}


int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; ++t )
  {
    cin >> J >> P >> S >> K;
    memset(JP, 0, sizeof(JP));
    memset(JS, 0, sizeof(JS));
    memset(PS, 0, sizeof(PS));
    memset(JPS, 0, sizeof(JPS));
    current.clear();
    best.clear();
    check();
    cout << "Case #" << t << ": " << best.size() << '\n';
    for ( auto &b: best )
    {
      cout << (1 + get<0>(b)) << ' ' << (1 + get<1>(b)) 
        << ' ' << (1 + get<2>(b)) << '\n';
    }
  }
  return 0;
}
