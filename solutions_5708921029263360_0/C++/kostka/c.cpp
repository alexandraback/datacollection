#include "bits/stdc++.h"

using namespace std;

void test()
{
  map <pair <pair <int, int>, pair <int, int> >, int> M;
  vector <tuple <int, int, int> > MOZ, RES, BEST;
  int jj, pp, ss, kk;
  cin >> jj >> pp >> ss >> kk;
  for(int i=1; i<=jj; i++)
    for(int j=1; j<=pp; j++)
        for(int k=1; k<=ss; k++)
          MOZ.emplace_back(i,j,k);

  for(int t=0; t<50000; t++)
  {
    M.clear();
    RES.clear();
    random_shuffle(MOZ.begin(), MOZ.end());
    for(auto ele : MOZ)
        {
          int i,  j, k;
          tie(i,j,k) = ele;
          int used = max(max(M[{{1,i},{2,j}}], M[{{1,i},{3,k}}]), M[{{2,j},{3,k}}]);
          if(used < kk)
          {
            M[{{1,i}, {2,j}}]++;
            M[{{1,i}, {3,k}}]++;
            M[{{2,j}, {3,k}}]++;
            RES.emplace_back(i,j,k);
          }
        }
    if((int)RES.size() > (int)BEST.size())
      BEST = RES;
  }
  cout << (int)BEST.size() << "\n";
  for(auto ele : BEST)
  {
    int x, y, z;
    tie(x,y,z) = ele;
    cout << x << " " << y << " " << z << "\n";
  }
}

int main()
{
  int t;
  cin >> t;
  for(int tti=1; tti<=t; tti++)
  {
    //cerr << tti << "\n";
    cout << "Case #" << tti << ": ";
    test();
  }
}
