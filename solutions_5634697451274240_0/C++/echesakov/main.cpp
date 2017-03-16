#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numberOfManeuvers(string const& S)
{
  int numberOfManeuvers = 0;

  for (int i = 1; i < S.size(); ++i)
  {
    if (S[i] != S[i - 1])
    {
      ++numberOfManeuvers;
    }
  }

  if (S[S.size() - 1] == '-')
  {
    ++numberOfManeuvers;
  }

  return numberOfManeuvers;
}

int main()
{
  int T;
  cin >> T;

  for (int i = 0; i < T; ++i)
  {
    string S;
    cin >> S;

    cout << "Case #" << (i + 1) << ": " << numberOfManeuvers(S) << endl;
  }
}