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
typedef vector<string>	VS;

char search_max(string &S, int n)
{
  char ret = S[0];
  for(int i = 0 ; i <= n ; i++){
    if( ret < S[i]) ret = S[i];
  }
  return ret;
}

int main(void)
{
  int T,t;
  int ret;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    VI list;
    string S;
    cin>>S;
    int N = S.length();
    string ans;
    int n = N -1;
    while( n > 0) {
//cout<<n<<endl;
      char c = search_max(S, n);
      int lastpos = n;
      for(int nn = n; nn >= 0 ; nn--){
        if(c == S[nn]) {
          ans = ans + c;
          list.push_back(nn);
          lastpos = nn;
        }
      }
      n = lastpos - 1;
    }
    for(n = 0 ; n < N ; n++){
      if(find(ALL(list), n) == list.end()){
        ans = ans + S[n];
      }
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

