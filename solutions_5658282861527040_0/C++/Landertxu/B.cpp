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

int main()
{
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    int a, b, k;
    cin >> a >> b >> k;
    int ans = 0;
    fi(a) fj(b) if ((i&j) < k) ans++;
//     else cout << i << " " << j << " " << k << " " << (i&j) << endl;
    cout << ans << endl;
  }
}