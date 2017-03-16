#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <sstream>
#include <stack>

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
typedef map<string,int> MSI;
typedef map<string,string> MSS;
typedef queue<string> QS;
typedef map<int,int> MII;
typedef queue<VI> QVI;
typedef map<VI,int> MVII;
typedef pair<string,int> PSI;
typedef vector<PSI> VPSI;
typedef stack<int> SI;

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    int n, m;
    cin >> n >> m;
    VS cod(n);
    fi (n) cin >> cod[i];
    VS cod2 = cod;
    sort(cod.begin(),cod.end());
    MSI id;
    fi (n) id[cod[i]] = i;
    VVI g (n, VI (n, 0));
    fi (m)
    {
      int a, b;
      cin >> a >> b;
      a--;b--;
      a = id[cod2[a]];
      b = id[cod2[b]];
      g[a][b] = g[b][a] = 1;
    }
    int qd = n-1;
    SI pl;
    pl.push(0);
    cout << cod[0];
    VI est(n,0);
    est[0] = 1;
    while (qd > 0)
    {
      fi (n)
      {
//         cout << i << endl;
        if (est[i] != 0) continue;
        SI p2 = pl;
        VI e2 = est;
        while (not p2.empty() and not g[p2.top()][i]) p2.pop();
//         cout << "ok" << endl;
        if (p2.empty()) continue;
//         cout << "ok2" << endl;
        p2.push(i);
        e2[i] = 1;
        SI p3 = p2;
        while (not p3.empty())
        {
          int a = p3.top();
          p3.pop();
//           cout << a << " " << g[a][1] << endl;
          fj (n) if (g[a][j] and e2[j] == 0)
          {
//             cout << "Dentro" << j << endl;
            e2[j] = 1;
            p3.push(j);
          }
        }
//         fj(n) cout << j << "-" << e2[j] << endl;
        bool ok = true;
        fj (n) if (e2[j] == 0) ok = false;
        if (ok)
        {
          cout << cod[i];
          est[i] = 1;
          pl = p2;
          break;
        }
        
      }
      qd--;
    }
    cout << endl;
  }
}