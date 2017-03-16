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
typedef map<string, int> MSI;
typedef vector<int>	VI;
typedef vector<string>	VS;
typedef vector<LL>	VLL;
typedef set<int>	SI;
typedef set<LL>	SLL;
typedef vector< vector<int> >	VII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair

//#define DEBUG

int flags[1001];

int countbit(int d)
{
  int ret = 0;
  while(d>0){
    if(d&1)ret++;
    d>>=1;
  }
  return ret;
}

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int N;
    cin>>N;
    MSI msi1;
    MSI msi2;
    VS vs1;
    VS vs2;
    int ans = 0;
    memset(flags, 0 , sizeof(flags));
    for(int n = 0 ; n < N ; n++){
      string s1,s2;
      cin>>s1>>s2;
      msi1[s1]++;
      msi2[s2]++;
      vs1.push_back(s1);
      vs2.push_back(s2);
    }
    for(int n = 0 ; n < N ; n++){
//cout<<vs1[n]<<","<<vs2[n]<<","<<msi1[vs1[n]]<<","<<msi2[vs2[n]]<<endl;
      if((msi1[vs1[n]] > 1) && (msi2[vs2[n]] > 1)) {
        flags[n] = 1;
      }
    }
    for(int n = 0 ; n < (1<<N) ; n++){
      int num = n;
      int f = 1;
      MSI msitmp1;
      MSI msitmp2;
      int index;
      for(index = 0; index < N ; index++){
        if((num&1)==0){
          msitmp1[vs1[index]]++;
          msitmp2[vs2[index]]++;
        }
        num >>= 1;
      }
      index = 0;
      num = n;
      for(index = 0; index < N ; index++){
        if((num&1)==1){
          if(flags[index]==0) {
            f = 0;
            break;
          }
          if(msitmp1[vs1[index]]==0){
            f = 0;
            break;
          }
          if(msitmp2[vs2[index]]==0){
            f = 0;
            break;
          }
        }
        num >>= 1;
      }
      if(f==1){
        int d = countbit(n);
        ans = max(d, ans);
//cout<<n<<","<<d<<","<<ans<<endl;
      }
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

