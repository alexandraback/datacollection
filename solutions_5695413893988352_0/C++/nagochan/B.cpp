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
typedef vector<string>	VS;
typedef vector<VS>	VSS;
typedef vector<int>	VI;
typedef vector< vector<int> >	VII;
typedef unsigned int UINT32;
typedef unsigned short UINT16;
typedef unsigned char UINT8;
#define ALL(c) (c).begin(), (c).end()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define PB push_back
#define MP make_pair

//#define DEBUG

int match(int n ,string &S)
{
  int length = S.length();
  int flag = 1;
  int i;
  for (i = length - 1  ; i >=0 ; i--){
//cout<<n<<","<<S<<endl;
    char ci = S[i];
    int d = n%10;
    n /= 10;
    if( ci != '?' && ci !=('0' + d)){
      flag = 0;
      break;
    }
  }
  return flag;
}


int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    string S1, S2, Sall;
    cin>>S1>>S2;
    int ansnum1 = 0;
    int ansnum2 = 0;
    Sall = S1 + S2;
    int N = Sall.length();
    int mN = 1;
    int mN2 = 1;
    int i;
    for(i = 0 ; i < N ; i++) mN *= 10;
    for(i = 0 ; i < S1.length() ; i++) mN2 *= 10;
    int mindiff = mN;
//cout<<Sall<<","<<mindiff<<endl;
    for(int n = 0 ; n < mN ; n++){
      int f = match(n, Sall);
      if (f!=0) {
        int n1 = n / mN2;
        int n2 = n % mN2;
//cout<<n1<<","<<n2<<endl;

        int diff = abs(n1 - n2);
        if(mindiff > diff) {
          mindiff = diff;
          ansnum1 = n1;
          ansnum2 = n2;
        }
      }
    }
    string ans1;
    string ans2;
    for(i=0;i<S1.length();i++){
      char d1 = (ansnum1%10) + '0';
      char d2 = (ansnum2%10) + '0';
      ans1 = d1 + ans1;
      ans2 = d2 + ans2;
      ansnum1 /= 10;
      ansnum2 /= 10;
    }
    cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;
  }
  return 0;
}

