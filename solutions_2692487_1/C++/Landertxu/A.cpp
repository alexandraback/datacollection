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

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    ll A;
    int n;
    cin >> A >> n;
    VL v (n);
    fi (n) cin >> v[i];
    if (A == 1)
    {
      cout << n << endl;
      continue;
    }
    sort (v.begin(),v.end());
    int ans = n;
    fi (n) //remove i motes
    {
      ll val = A;
      int sum = i;
      fj (n-i)
      {
        while (sum <= ans and val <= v[j])
        {
          val += val-1;
          sum++;
        }
        val += v[j];
      }
      ans = min (ans, sum);
    }
    cout << ans << endl;
  }
}