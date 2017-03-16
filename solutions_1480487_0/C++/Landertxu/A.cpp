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


int main()
{
  int T;
  cin >> T;
  cout.setf(ios::fixed);
  cout.precision(6);
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ":";
    int N;
    cin >> N;
    VI v (N);
    fi (N) cin >> v[i];
    double sm = 0;
    fi (N) sm += v[i];
    fi (N)
    {
      double mn = 0;
      double mx = 1;
      while (mx-mn > eps)
      {
	double md = (mx+mn)/2.;
	double val = v[i] + sm*md;
	double nec = 0;
	fj (N)
	{
	  if (i == j) continue;
	  nec += max(0.,(val-v[j])/sm);
	}
	if (nec < 1-md)
	  mn = md;
	else
	  mx = md;
      }
      cout << " " << 100*(mx+mn)/2.;
    }
    cout << endl;
  }
}