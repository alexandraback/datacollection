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

#define BMAX 50

int array[BMAX+1][BMAX+1];
int bp[BMAX+2];

void printarray(int B){
  int x,y;
  for(y=0;y<B;y++){
    for(x=0;x<B;x++){
      cout<<array[y][x];
    }
    cout<<endl;
  }
}

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    cout<<"Case #"<<t<<": ";
    int B;
    LL M;
    cin>>B>>M;
    int fp = 0;
    if(B==2){
      if(M!=1){
        cout<<"IMPOSSIBLE"<<endl;
      } else {
        cout<<"POSSIBLE"<<endl;
        cout<<"01"<<endl;
        cout<<"00"<<endl;
      }
    } else {
      int pat_max = (B-1)*B/2;
//cout<<"pat_max="<<pat_max<<endl;
      for(int pat = 0 ; pat < (1<<pat_max) ; pat++){
        int x,y;
        int pat_tmp = pat;
        memset(array, 0, sizeof(array));
        memset(bp, 0, sizeof(bp));
        for(y = B - 2 ; y >=0 ; y--){
          for(x = B-1 ; x>y ; x--){
            if(pat_tmp&1){
              array[y][x] = 1;
            }
            pat_tmp>>=1;
          }
        }
//printarray(B);
//cout<<endl;
        bp[B-1] = 1;
        for(int n1 = B-2; n1 >= 0; n1--){
          for(int n2 = B-1 ; n2 > n1 ; n2--){
            if(array[n1][n2]==1){
              bp[n1] += bp[n2];
            }
          }
        }
        if(bp[0] == M){
          cout<<"POSSIBLE"<<endl;
          printarray(B);
          fp = 1;
          break;
        }
      }
      if(fp == 0){
        cout<<"IMPOSSIBLE"<<endl;
      }
    }
  }
  return 0;
}

