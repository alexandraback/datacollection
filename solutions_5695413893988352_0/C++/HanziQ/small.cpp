#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <limits>

using namespace std;

vector<vector<int>> cA, cB;
uint32_t dist;
int mA, mB, L;
int tmpA, tmpB;

void recurse(int P)
{
  if (P == L)
  {
    // cout << "T " << tmpA << " " << tmpB << " " << abs(tmpA - tmpB) << " < " << dist << endl;
    if (abs(tmpA - tmpB) < dist)
    {
      dist = abs(tmpA - tmpB);
      mA = tmpA;
      mB = tmpB;
    }
  }
  else
  {
    tmpA *= 10;
    tmpB *= 10;
    for (int i = 0; i < cA[P].size(); ++i)
    {
      tmpA += cA[P][i];
      for (int j = 0; j < cB[P].size(); ++j)
      {
        tmpB += cB[P][j];
        recurse(P+1);
        tmpB -= cB[P][j];
      }
      tmpA -= cA[P][i];
    }
    tmpA /= 10;
    tmpB /= 10;
  }
}

int main(void)
{
  int T;
  cin >> T;
  cin.ignore();
  for (int CN = 1; CN <= T; ++CN)
  {
    string A, B;
    cin >> A; cin.ignore(); cin >> B;
    L = A.size();

    cA.clear();
    cB.clear();
    cA.resize(L);
    cB.resize(L);

    for (int i = 0; i < L; ++i)
    {
      if (A[i] != '?')
        cA[i] = {A[i] - '0'};
      if (B[i] != '?')
        cB[i] = {B[i] - '0'};

      if (A[i] == '?' && B[i] == '?')
      {
        cA[i] = {0, 1, 9};
        cB[i] = {0, 1, 9};
      }
      else if (A[i] == '?')
      {
        cA[i] = {cB[i][0]};
        if (cB[i][0] > 0)
          cA[i].push_back(cB[i][0] - 1);
        else
          cA[i].push_back(9);
        if (cB[i][0] < 9)
          cA[i].push_back(cB[i][0] + 1);
        else
          cA[i].push_back(0);

        if (cB[i][0] < 9 && cB[i][0] > 1)
          cA[i].push_back(0);
        if (cB[i][0] < 8 && cB[i][0] > 0)
          cA[i].push_back(9);

      }
      else if (B[i] == '?')
      {
        cB[i] = {cA[i][0]};
        if (cA[i][0] > 0)
          cB[i].push_back(cA[i][0] - 1);
        else
          cB[i].push_back(9);
        if (cA[i][0] < 9)
          cB[i].push_back(cA[i][0] + 1);
        else
          cB[i].push_back(0);

        if (cA[i][0] < 9 && cA[i][0] > 1)
          cB[i].push_back(0);
        if (cA[i][0] < 8 && cA[i][0] > 0)
          cB[i].push_back(9);
      }

      sort(cA[i].begin(), cA[i].end());
      sort(cB[i].begin(), cB[i].end());
    }


    tmpA = tmpB = 0;
    mA = mB = 0;
    dist = numeric_limits<uint32_t>::max();
    recurse(0);


    // for (int i = 0; i < L; ++i)
    // {
    //   cout << "{";
    //   for (int j = 0; j < cA[i].size(); ++j)
    //     cout << cA[i][j] << ", ";
    //   cout << "}, {";
    //   for (int j = 0; j < cB[i].size(); ++j)
    //     cout << cB[i][j] << ", ";
    //   cout << "}" << endl;
    // }

    cout << "Case #" << CN << ": ";
    cout << setw(L) << setfill('0') << mA << " " << setw(L) << setfill('0') << mB << endl;
  }
}
