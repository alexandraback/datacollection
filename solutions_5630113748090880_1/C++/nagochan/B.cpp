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

char swapc(char c)
{
  if(c == '-') return '+';
  return '-';
}

void swapS(int start, int end, string &S)
{
  while(start <= end){
    char cs=S[start];
    char ce=S[end];
    S[start] = swapc(ce);
    S[end] = swapc(cs);
    start++;
    end--;
  }
}

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    cout<<"Case #"<<t<<": ";
    int N;
    VS vs;
    cin>>N;
    VI array;
    for(int col = 0 ; col < 2*N - 1 ; col++){
      for(int row = 0 ; row < N ; row++){
        int tmp;
        cin>>tmp;
        array.push_back(tmp);
      }
    }
    sort(ALL(array));
    int n = 0;
    string ans;
    int size = array.size();
    while(1){
      int val = array[n];
      int count = 1;
      while(n < (size - 1) && val == array[n+1]) {
        n++;
        count++;
      }
      if(count & 1) {
        cout<< val<<" ";
      }
      if(n== (size-1))break;
      n++;
    }

    cout<<endl;
  }
  return 0;
}

