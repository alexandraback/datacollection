#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;

void tiles(long long K, long long C, long long S)
{
  vector<long long> positions;

  long long num = 0;
  for (; (num < K) && (positions.size() < S); num++)
  {
    long long pos = num;
    long long len = K;

    for (long long lvl = 1; lvl < C; ++lvl)
    {
      len *= K;
      if (num < K - 1)
      {
        ++num;
      }
      pos = num + pos * K;
    }

    positions.push_back(pos + 1);
  }

  if (num < K)
  {
    cout << "IMPOSSIBLE";
  }
  else
  {
    copy(positions.begin(), positions.end(), ostream_iterator<long long>(cout, " "));
  }
}

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    long long K, C, S;
    cin >> K >> C >> S;

    cout << "Case #" << (i + 1) << ": ";
    tiles(K, C, S);
    cout << endl;
  }
}