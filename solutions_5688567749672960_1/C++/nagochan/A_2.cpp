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

int getd(LL n){
  int d = 0;
  while(n>0){
    d++;
    n /= 10;
  }
  return d;
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
    LL ans = 0;
    while(N>9){
      int d = getd(N);
      LL  d10 = 1;
      LL n1;
      LL n1_2;
      LL n2;
      for(int i = 0;i<d/2;i++){
        d10 *= 10;
      }
      n1_2 = N % d10;
      if(n1_2 == 0){
        N--;
        ans++;
        if(getd(N)!=d)continue;
      }
      LL nr = rev(N);
      if(d%2){
        n1 = N % (d10*10);
        n1_2 = N % d10;
        n2 = nr % d10;
      }
      else{
        n1 = N % d10;
        n1_2 = N % d10;
        n2 = nr % d10;
      }
      ans += n1 + n2;
      if(n2>1)ans++;
      d10 = 1;
      for(int i = 0;i<d-1;i++){
        d10 *= 10;
      }
      N = d10 - 1;
//cout <<"N="<<N<<endl;
    }
    ans += N;

    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

