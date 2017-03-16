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

#define INF 10000000000000009LL

#define NMAX 1000000

LL A[NMAX + 1];

LL rev(LL n)
{
  LL ans = 0;
  while(n > 0){
    ans*=10;
    ans += (n%10);
    n /= 10;
  }
//cout<<"rev:"<<n<<","<<ans<<endl;
  return ans;
}

int main(void)
{
  int T,t;
  ll ret;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    ll N;
    cin>>N;
    for(LL n = 0;n<=NMAX;n++)A[n] = INF;

    A[0] = 0;
    for(LL n = 0;n<N;n++){
      A[n+1] = min(A[n+1], A[n] + 1);
      LL nr = rev(n);
      if(nr>n && nr <= N){
        A[nr] = min(A[nr], A[n]+1);
      }
    }

    cout<<"Case #"<<t<<": "<<A[N]<<endl;
  }
  return 0;
}

