#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

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
typedef vector<VS> VVS;

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ":";
    int kk, n;
    cin >> kk >> n;
    VI lk (kk);
    fi (kk) cin >> lk[i];
    VVI kc (n);
    VI tp (n);
    fi (n)
    {
      int ki;
      cin >> tp[i] >> ki;
      kc[i] = VI (ki);
      fj (ki) cin >> kc[i][j];
    }
    VI base (201,0);
    fi (kk) base[lk[i]] ++;
    
    VI sig (1<<n, -1);
    sig[0] = 0;
    fii (1, 1<<n)
    {
      VI kac = base;
      fj (n)
      {
        if ((i&(1<<j)) == 0)
        {
          kac[tp[j]]--;
          fk (kc[j].size()) kac[kc[j][k]]++; 
        }
      }
      fj (n)
      {
        if ((i&(1<<j)) != 0 and kac[tp[j]] > 0)
        {
          if (sig[i^(1<<j)] > -1)
          {
            sig[i] = j;
            break;
          }
        }
      }
//       cout << i << " " << sig[i] << endl;
    }
    if (sig [(1<<n)-1] == -1) cout << " IMPOSSIBLE" << endl;
    else
    {
      int a = (1<<n)-1;
//       cout << "a=" << a << endl;
      while (a > 0)
      {
        cout << " " << sig[a]+1;
        a ^= 1<<sig[a];
      }
      cout << endl;
    }
  }
}