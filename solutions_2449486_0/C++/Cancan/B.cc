#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef vector<int> VI;

bool solve()
{
  int M, N;
  cin >> M >> N;
  vector<VI> v(M);
  int intmp;
  for (int i=0; i<M; i++)
    for (int j=0; j<N; j++)
    {
      cin>> intmp;
      v[i].push_back(intmp);
    }
  VI mw(M, 0);
  VI mh(N, 0);
  for (int i=0; i<M; i++)
    for (int j=0; j<N; j++)
    {
      mw[i] = max(mw[i], v[i][j]);
    }

  for (int j=0; j<N; j++)
    for (int i=0; i<M; i++)
    {
      mh[j] = max(mh[j], v[i][j]);
    }

  for (int i=0; i<M; i++)
    for (int j=0; j<N; j++)
      if ((v[i][j] < mw[i]) && (v[i][j] < mh[j]))
        return false;

  return true;
}


int main()
{
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    string hehe;
    hehe = (solve())?"YES":"NO";
    printf("Case #%d: %s\n", i, hehe.c_str());
  }
  return 0;
}

