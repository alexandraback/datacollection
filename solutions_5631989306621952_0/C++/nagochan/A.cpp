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



int main(void)
{
  int T,t;
  int ret;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    string S;
    cin>>S;
    int N = S.length();
    VS vs;
    for(int n = 0 ; n < (1<<N) ; n++){
      int val = n;
      string ns;
      for(int m = 0 ; m < N ; m++){
        if(val & 1) {
          ns = S[m] + ns;
        } else {
          ns = ns + S[m];
        }
        val >>=1;
      }
      vs.push_back(ns);
    }
    sort(ALL(vs), greater<string>());
    cout<<"Case #"<<t<<": "<<vs[0]<<endl;
  }
  return 0;
}

