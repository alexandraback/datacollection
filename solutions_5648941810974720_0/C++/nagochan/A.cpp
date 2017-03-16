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

int A[256];
int CT[10];

string L[10] ={
  "ZERO",
  "ONE",
  "TWO",
  "THREE", 
  "FOUR", 
  "FIVE", 
  "SIX", 
  "SEVEN", 
  "EIGHT", 
  "NINE"
};

void check(int n)
{
  string s = L[n];
  while(1){
    int flag = 1;
    for(int i = 0 ; i < s.length() ; i++){
      int c = s[i];
      if (A[c] ==0) {
        flag = 0;
        break;
      }
    }
    if(flag == 0) break;
    for(int i = 0 ; i < s.length() ; i++){
      int c = s[i];
      A[c]--;
    }
    CT[n]++;
  }
}

int main(void)
{
  int T,t;
  int ret;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    string ans;
    string S;
    cin>>S;
    int N = S.length();
    VS vs;
    memset(A, 0, sizeof(A));
    memset(CT, 0, sizeof(CT));
    for(int n = 0 ; n < N ; n++){
      A[S[n]]++;
    }
    check(0);
    check(2);
    check(6);
    check(4);
    check(1);
    check(7);
    check(5);
    check(9);
    check(8);
    check(3);
    for(int i = 0 ; i < 10 ; i++){
      while(CT[i]>0){
        ans += '0'+i;
        CT[i]--;
      }
    }
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

