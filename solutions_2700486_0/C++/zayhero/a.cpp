#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define pb push_back

const int N = 2000000;
const int ABS(int x) {while(x < 0) x = -x; return x;}

int x, y, n;
ll cnk[23][23] = {0};
vi v;

void prep()
{
  v.pb(1);
  for(ll i = 3; ; i += 2)
  {
    ll tmp = (1 + i) * i / 2;
    if (tmp > N) break;
    v.pb(tmp);
  }
  for(int i = 1; i <= 20; i++)
  {
    for(int j = 0; j <= i; j++)
    {
      if(j == 0 || j == i) cnk[i][j] = 1;
      else cnk[i][j] = cnk[i - 1][j] + cnk[i - 1][j - 1];
    }
  }
}

void init()
{
  cin>>n>>x>>y;
}

bool inside(int p)
{
  p *= 2;
  return (ABS(x) + ABS(y)) <= p;
}

double cal()
{
  if (x == 0 && y == 0) return 1.0;
  int p;
  for(p = 0; p < v.size(); p++)
  {
    if(v[p] >= n)
    {
      break;
    }
  }
  n -= v[p - 1];
  //cout<<n<<endl;
  if(inside(p - 1)) return 1.0;
  if(!inside(p)) return 0.0;
  int m = y + 1;
  //cout<<"still1"<<endl;
  //cout<<n<<" "<<p<<" "<<m<<endl;
  if(y / 2 == p)
  {
    if(n == m * 2 - 1) return 1.0;
    return 0.0;
  }
  //cout<<"still2"<<endl;
  if(n >= p + 1 + m) return 1.0;
  if(n < m) return 0.0;
  double res = 0.0;
  for(int i = m; i <= n; i++)
  {
    res += cnk[n][i] * pow(0.5, n);
    //cout<<res<<endl;
  }
  return res;
}

void solve(int tcase)
{
  double res = cal();
  printf("Case #%d: %.6lf\n", tcase, res);
}

int main()
{
  prep();
  int T;
  cin>>T;
  for(int i = 1; i <= T; i++)
  {
    init();
    solve(i);
  }
}