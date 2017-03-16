#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main(void)
{
  int T;
  cin >> T;
  cin.ignore();
  for (int CN = 1; CN <= T; ++CN)
  {
    int N;
    cin >> N;
    cin.ignore();
    vector<string> sA, sB;
    map<string, int> mA, mB;
    sA.resize(N);
    sB.resize(N);
    for (int i = 0; i < N; ++i)
    {
      cin >> sA[i];
      cin.ignore();
      cin >> sB[i];
      mA[sA[i]]++;
      mB[sB[i]]++;
    }
    int fake = 0;

    set<string> ssA, ssB;

    for (int i = 0; i < N; ++i)
    {
      if (mA[sA[i]] == 1 || mB[sB[i]] == 1)
      {
        ssA.insert(sA[i]);
        ssB.insert(sB[i]);
      }
    }

    for (int i = 0; i < N; ++i)
    {
      if (mA[sA[i]] != 1 && mB[sB[i]] != 1 && ssA.count(sA[i]) && ssB.count(sB[i]))
      {
        ++fake;
      }
      ssA.insert(sA[i]);
      ssB.insert(sB[i]);
    }


    cout << "Case #" << CN << ": ";
    cout << fake << endl;
  }
}
