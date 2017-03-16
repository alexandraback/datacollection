#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef long long LL;
typedef pair<int,int>            PI;
typedef map<PI, int> MPI;
typedef vector<int>	VI;
typedef vector< vector<int> >	VII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair

#define INF 100000001

//#define DEBUG

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int D;
    cin>>D;
    int maxn = 0;
    int ans = INF;
    VI P;
    REP(i,D)
    {
      int tmp;
      cin>>tmp;
      if(tmp > maxn)maxn = tmp;
      P.PB(tmp);
    }
    int N = P.size();
    for(int m = maxn ; m > 0 ; m--){
      int ans_local = 0;
      int d_max = 0;
      for(int n = 0 ; n < N ; n++) {
        if(P[n] > m) {
          int d = (P[n] + m - 1)  / m;
          ans_local += d - 1;
          d_max = max(d_max, (P[n] + (d-1))/d);
        } else {
          d_max = max(d_max, P[n]);
        }
      }
      ans_local += d_max;
      ans = min(ans, ans_local);
#ifdef DEBUG
      cout<<t<<","<<m<<","<<ans_local<<endl;
#endif
    }

    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

