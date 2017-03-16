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

double prob (int a, int b)
{
  VD v (a+1,0);
  v[0] = 1;
  for (int i = 0; i < a; i++)
  {
    for (int j = a; j > 0; j--)
    {
      v[j] = (v[j]+v[j-1])/2.;
    }
  }
  return v[b];
}

int main()
{
  int T;
  cin >> T;
  VI lc (1000);
  lc[0] = 1;
  fii (1, lc.size())
  {
    lc[i] = lc[i-1] + 4*i + 1;
//     cout << i << " " << lc[i] << endl;
  }
//   cout << lc[900] << endl;
  cout.setf(ios::fixed);
  cout.precision(8);
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    int N, X, Y;
    cin >> N >> X >> Y;
    if (abs(X) + Y > 1800)
    {
      cout << 0. << endl;
      continue;
    }
    if (X == 0)
    {
      if (lc[Y/2] > N)
        cout << 0. << endl;
      else
        cout << 1. << endl;
      continue;
    }
    int lvl = (abs(X)+Y) / 2;
    if (N >= lc[lvl])
    {
      cout << 1. << endl;
      continue;
    }
    if (N <= lc[lvl-1])
    {
      cout << 0. << endl;
      continue;
    }
    int K = N - lc[lvl-1];
    int alt = Y+1;
    int tot = lc[lvl]-lc[lvl-1]-1;
    if (K <= tot/2)
      cout << prob (K, alt) << endl;
    else
      cout << 1-prob(tot-K, (tot/2)+1-alt) << endl;
  }
}