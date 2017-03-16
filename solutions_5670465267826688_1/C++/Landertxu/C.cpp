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

int mult (int a, int b)
{
  int sign = 1;
  if (a * b < 0) sign = -1;
  a = abs(a);
  b = abs(b);
  int c;
  if (a == 1) c = b;
  else if (b == 1) c = a;
  else if (a == b) c = -1;
  else
  {
    a -= 2;
    b -= 2;
    if ((a+1)%3 != b)
    {
      sign *= -1;
    }
    a += 2;
    b += 2;
    fii(2,5) if (i != a and i != b) c = i;
  }
  return c * sign;
}

int cti (char c)
{
  return c-'i'+2;
}

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    ll l, x;
    cin >> l >> x;
    string s;
    cin >> s;
    int tot = 1;
    fi (l) tot = mult (tot, cti(s[i]));
    int pt = 1;
    fi (x%4) pt = mult(pt,tot);
    if (pt != -1)
    {
      cout << "NO" << endl;
      continue;
    }
    int busc = 2;
    ll rd = 0;
    ll ii = 0;
    ll jj = 0;
    tot = 1;
    while (busc < 5 and rd < 100 and jj < x)
    {
      tot = mult(tot, cti(s[ii]));
      ii++;
      if (ii >= l)
      {
        ii = 0;
        rd ++;
        jj ++;
      }
      if (tot == busc)
      {
        busc ++;
        tot = 1;
        rd = 0;
      }
    }
    if (busc == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}