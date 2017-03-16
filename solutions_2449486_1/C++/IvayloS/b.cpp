#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    int n,m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));

    for (int i=0;i<n;++i) {
      for (int j=0;j<m;++j) {
        scanf("%d", &a[i][j]);
      }
    }
    
    vector<vector<int> > b(n, vector<int>(m, 100));
    for( int i=0;i<n;++i) {
      int mx = 0;
      for ( int j=0;j<m;j++) {
        mx = max(mx ,a[i][j]);
      }

      for ( int j=0;j<m;++j) {
        b[i][j] = min(b[i][j], mx);
      }
    }

    for( int j=0;j<m;++j) {
      int mx = 0;
      for ( int i=0;i<n;i++) {
        mx = max(mx ,a[i][j]);
      }

      for ( int i=0;i<n;++i) {
        b[i][j] = min(b[i][j], mx);
      }
    }

    string res;
    if (b == a) {
      res = "YES";
    } else {
      res = "NO";
    }
    cout<<"Case #"<<it<<": "<< res <<endl;
  }
  return 0;
}
