#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <map>

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
typedef vector<VVB> VVVB;
typedef priority_queue<PT> PQPT;
typedef map<int,int> MII;

void imprime (VI& v, int mask)
{
  int n = v.size();
  bool prim = true;
  fi (n)
  {
    if ((mask&(1<<i))!=0)
    {
      if (prim) prim = false;
      else cout << " ";
      cout << v[i];
    }
  }
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ":" << endl;
    
    int n;
    cin >> n;
    VI v (n);
    fi (n) cin >> v[i];
    MII m;
    bool ok = false;
    fi (1<<n)
    {
      int sm = 0;
      fj (n)
      {
	if ((i&(1<<j))!=0)
	  sm += v[j];
      }
      if (m.find(sm)!=m.end()) // we found it
      {
	imprime (v,m[sm]);
	imprime (v,i);
	ok = true;
	break;
      }
      else
	m[sm] = i;
    }
    if (not ok) cout << "Impossible" << endl;
  }
}