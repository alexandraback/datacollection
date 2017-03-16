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
typedef priority_queue<int> PQI;

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    int D;
    cin >> D;
    VI v(D);
    fi (D) cin >> v[i];
    int mn = 0;
    int mx = 0;
    fi(D) mx = max (mx, v[i]);
    
    while (mn < mx)
    {
      int md = (mn+mx)/2;
      bool ok = false;
      fi (md) //number of special rounds
      {
        int vm = md - i;
        int gt = 0;
        fj (D)
        {
          gt += max(0,(v[j]-1)/vm);
        }
        if (gt <= i) ok = true;
      }
      if (ok) mx = md;
      else mn = md + 1;
      
    }
    cout << "Case #" << caso << ": " << mn << endl;
  }
}