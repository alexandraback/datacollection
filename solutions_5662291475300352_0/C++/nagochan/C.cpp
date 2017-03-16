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
typedef pair<PI,int>            PII;
typedef map<PI, int> MPI;
typedef vector<int>	VI;
typedef vector< vector<int> >	VII;
typedef vector<PI>	VPI;
typedef vector<PII>	VPII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair

VPI A;

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int N;
    cin>>N;
    A.clear();
    REP(i,N)
    {
      int D,H,M;
      cin>>D>>H>>M;
      for(int j = 0;j<H;j++){
        A.PB(PI(M + j, D));
      }
    }
    sort(ALL(A));

    int ans = 0;
    if(A.size()>1){
      int a0s = A[0].first;
      int a0d = A[0].second;
      int a1s = A[1].first;
      int a1d = A[1].second;
//cout<<"("<<a0s<<","<<a0d<<")("<<a1s<<","<<a1d<<")"<<endl;
      if(a0s!=a1s){
        LL t0 = (720 - a0d);
        LL t1 = (360 - a1d);

        if(t0 * a0s <= t1 * a1s)ans = 1;
      }
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;

  }
  return 0;
}

