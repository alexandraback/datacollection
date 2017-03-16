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
typedef vector<VVB> VVVB;
typedef priority_queue<PT> PQPT;

int di[4] = {1,0,-1,0};
int dj[4] = {0,1,0,-1};

int main()
{
  int T;
  cin >> T;
  cout.setf(ios::fixed);
  cout.precision(1);
  for (int caso = 1; caso <= T; caso++)
  {
    cout << "Case #" << caso << ": ";
    int h, n, m;
    cin >> h >> n >> m;
    VVI ce (n, VI (m));
    fi (n) fj (m) cin >> ce[i][j];
    VVI fl (n, VI (m));
    fi (n) fj (m) cin >> fl[i][j];
//     fi (n) fj (m) ce[i][j] *= 10;
//     fi (n) fj (m) fl[i][j] *= 10;
//     h *= 10;
    VVB vis (n, VB (m, false));
    VVI dis (n, VI (m, inf));
    PQPT q;
    dis[0][0] = 0;
    q.push(PT(0,PI(0,0)));
    while (not vis[n-1][m-1])
    {
      PI a = q.top().second;
      q.pop();
      if (vis[a.first][a.second]) continue;
      vis[a.first][a.second] = true;
      int vi = a.first;
      int vj = a.second;
      int vh = h - dis[vi][vj];
      fi (4)
      {
	int ni = vi + di[i];
	int nj = vj + dj[i];
	if (ni < 0 or ni >= n or nj < 0 or nj >= m) continue;
	if (ce[ni][nj] < fl[ni][nj]+50) continue;
	if (ce[ni][nj] < fl[vi][vj]+50) continue;
	if (ce[vi][vj] < fl[ni][nj]+50) continue;
	//we can enter, computing time
// 	cout << vi << " " << vj << " " << ni << " " << nj << endl;
	int d = 0;
	int nvh = vh;
// 	cout << ce[ni][nj] << " " << vh << endl;
	if (ce[ni][nj] < vh + 50) //not yet
	{
	  d += nvh - ce[ni][nj] + 50;
	  nvh = ce[ni][nj] - 50;
	}
// 	cout << d << endl;
	if (nvh < h) //started
	{
	  if (nvh < fl[vi][vj]+20) //walk
	    d += 100;
	  else
	    d += 10; //kayak
	}
	d += dis[vi][vj];
	if (d < dis[ni][nj])
	{
	  dis[ni][nj] = d;
	  q.push(PT(-d,PI(ni,nj)));
	}
      }
    }
    int ans = dis[n-1][m-1];
    if (h - ans <= ce[n-1][m-1])
      cout << ans/10 << "." << ans%10 << endl;
    else
      cout << ce[n-1][m-1]/10 << "." << ce[n-1][m-1]/10 << endl;
  }
}