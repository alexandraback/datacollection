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

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    int n, m, tab[100][100], man[100], mam[100];
    cin>>n>>m;
    Fori(n)
    {
      for (int j=0; j<m; ++j)
      {
        cin>>tab[i][j];
        man[i]=mam[j]=0;
      }
    }
    Fori(n)
      for (int j=0; j<m; ++j)
      {
        man[i]=max(man[i], tab[i][j]);
        mam[j]=max(mam[j], tab[i][j]);
      }
    bool ok=true;
    Fori(n)
      for (int j=0; j<m; ++j)
        if (tab[i][j]<man[i] && tab[i][j]<mam[j])
          ok=false;
    cout<<"Case #"<<ca<<": "<<(ok ? "YES" : "NO")<<endl;
  }

  return 0;
}
