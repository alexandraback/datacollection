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
    
    int n, m;
    cin >> n >> m;
    VVI v (n, VI (m, 0));
    fi (n) fj (m) cin >> v[i][j];
    
    bool ok = true;
    fi (n)
    {
      fj (m)
      {
        bool rv,cv;
        rv = cv = true;
        //row
        fk (m)  if (v[i][k] > v[i][j]) rv = false;
        //column
        fk (n)  if (v[k][j] > v[i][j]) cv = false;
        if (not rv and not cv) ok = false;
      }
    }
    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}