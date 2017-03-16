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

string s[4];

bool wygral(char kto)
{
  Fori(4)
  {
    for (int j=0; j<4; ++j)
      if (s[i][j]!='T' && s[i][j]!=kto) break;
      else if (j==3) return true;
    for (int j=0; j<4; ++j)
      if (s[j][i]!='T' && s[j][i]!=kto) break;
      else if (j==3) return true;
  }
  Fori(4)
    if (s[i][i]!='T' && s[i][i]!=kto) break;
      else if (i==3) return true;
  Fori(4)
    if (s[3-i][i]!='T' && s[3-i][i]!=kto) break;
      else if (i==3) return true;
  return false;
}

int main()
{
  int NNN;
  cin>>NNN;
  for (int ca=1; ca<=NNN; ++ca)
  {
    Fori(4)
      cin>>s[i];
    cout<<"Case #"<<ca<<": ";
    if (wygral('X'))
    {
      cout<<"X won\n";
      continue;
    }
    if (wygral('O'))
    {
      cout<<"O won\n";
      continue;
    }
    bool kropka=false;
    Fori(4)
      if (s[i].find('.')!=-1)
      {
        kropka=true;
        break;
      }
    if (kropka) cout<<"Game has not completed\n";
    else cout<<"Draw\n";
  }

  return 0;
}
