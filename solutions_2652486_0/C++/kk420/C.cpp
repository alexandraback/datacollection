#include <algorithm>
#include <limits>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int MaxInt=numeric_limits<int>::max();
typedef vector<int> VI;
typedef vector<string> VS;
#define For(i,a,n) for (int i=a; i<n; ++i)
#define Fori(n) For(i,0,n)

int r, n, m, k;
VI il;

int x[6][6][6];

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    cin>>r>>n>>m>>k;
    cout<<"Case #"<<ca<<": "<<endl;
    Fori(r)
    {
      il.clear();
      for (int a=0; a<6; ++a)
        for (int b=0; b<6; ++b)
          for (int c=0; c<6; ++c)
            x[a][b][c]=0;
      int na=2, nb=2, nc=2, nw=0;
      for (int j=0; j<k; ++j)
      {
        int u;
        cin>>u;
      for (int a=2; a<6; ++a)
        for (int b=2; b<6; ++b)
          for (int c=2; c<6; ++c)
            if (a*b*c==u || a==u || b==u || c==u ||a*b==u ||a*c==u||b*c==u)
            {
              if (++x[a][b][c]>nw)
              {
                nw=x[a][b][c];
                na=a;
                nb=b;
                nc=c;
              }
            }
      }
      cout<<na<<nb<<nc<<endl;
           
    }   
  }


  return 0;
}
