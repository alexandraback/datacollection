#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;
typedef vector<string> VS;

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    VS v [2];
    string rel = "asdf";
    v[0] = v[1] = VS(4, rel);
    fi(4) cin >> v[0][i];
    fi(4) fj(4) v[1][i][j] = v[0][j][i];
    
    bool fin = true;
    bool ok = false;
    char gan;
    //rows and columns
    fk(2)
    fi (4)
    {
      int o, x;
      o=x=0;
      fj (4)
      {
        if (v[k][i][j] == 'O') o++;
        else if (v[k][i][j] == 'X') x++;
        else if (v[k][i][j] == 'T') {o++;x++;}
        else fin = false;
      }
      if (o == 4)
      {
        ok = true;
        gan = 'O';
      }
      if (x == 4)
      {
        ok = true;
        gan = 'X';
      }
    }
    
    if (ok)
    {
      cout << gan << " won" << endl;
      continue;
    }
    
    //diagonals
    
    fi (2)
    {
      int o, x;
      o=x=0;
      fj (4)
      {
        int ii = j;
        if (i == 1) ii = 3-j;
        if (v[0][ii][j] == 'O') o++;
        else if (v[0][ii][j] == 'X') x++;
        else if (v[0][ii][j] == 'T') {o++;x++;}
        else fin = false;
      }
      if (o == 4)
      {
        ok = true;
        gan = 'O';
      }
      if (x == 4)
      {
        ok = true;
        gan = 'X';
      }
    }
    if (ok)
    {
      cout << gan << " won" << endl;
      continue;
    }
    
    if (fin)
      cout << "Draw" << endl;
    else
      cout << "Game has not completed" << endl;
  }
}