#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;

int main()
{
  freopen("A-small-attempt0.in", "rt", stdin);
  freopen("A-small-attempt0.out", "wt", stdout);

  int T;
  int N;
  int M;
  cin>>T;
  for (int t=1; t<=T; t++)
  {
    bool result = false;
    cin>>N;
    vector<list<int> > parentV;
    for (int i=0; i<N; i++)
    {
      int p;
      list<int> parent;
      cin>>M;
      for (int m=0; m<M; m++)
      { 
        cin>>p;
        parent.push_back(p);
      }
      parentV.push_back(parent);
    }

    for (int j=0; j<N; j++)
    {
      list<int> ansc(parentV.at(j));
      list<int>::iterator it;
      list<int>::iterator it2;
      list<int>::iterator it3;
      if (result) break;       
      for (it=ansc.begin(); it != ansc.end(); it++)
      {
        int anAnsc = *it;
        if (result) break;
        for (it2 = parentV.at(anAnsc-1).begin(); 
             it2 != parentV.at(anAnsc-1).end(); 
             it2++)
        {
          int newAnsc = *it2;
          if (result) break;
          for (it3 = ansc.begin(); it3 != ansc.end(); it3++)
          {  
            if (*it3 == newAnsc)
            { 
              result = true;
              break;
            }
          }
          ansc.push_back(newAnsc);
        }

      }

    }
    printf("Case #%d: %s\n", t, result ? "Yes" : "No");
  }
}
