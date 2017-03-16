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

double count_pattern[1001][1001];
double count_all[1001];
double exp_pattern[1001];

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int X,R,C;
    cin>>X>>R>>C;
    int yes = 0;
    if(X<=2){
      if(((R*C)%X) == 0){
        yes = 1;
      }
    }
    if(X==3){
      if(min(R,C) >= 2 && (((R*C)%X) == 0)){
        yes = 1;
      }
    }
    if(X==4){
      if((((R%4)==0)&&(C>=3)) || ((R>=3)&&((C%4)==0))){
        yes = 1;
      }
    }
    
    /* X==4ÇÕñ≥óùÅHÅH */
    if(yes==1){
      cout<<"Case #"<<t<<": "<<"GABRIEL"<<endl;
    }
    else {
      cout<<"Case #"<<t<<": "<<"RICHARD"<<endl;
    }
  }
  return 0;
}

