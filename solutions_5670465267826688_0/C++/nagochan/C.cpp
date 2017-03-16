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

//#define DEBUG

int array[256][256];

void init_array(void)
{
  char ci = 'i';
  char cj = 'j';
  char ck = 'k';
  array[ 1][ 1] = 1;
  array[ 1][ci] = ci;
  array[ 1][cj] = cj;
  array[ 1][ck] = ck;
  array[ci][ 1] = ci;
  array[ci][ci] = -1;
  array[ci][cj] = ck;
  array[ci][ck] = -cj;
  array[cj][ 1] = cj;
  array[cj][ci] = -ck;
  array[cj][cj] = -1;
  array[cj][ck] = ci;
  array[ck][ 1] = ck;
  array[ck][ci] = cj;
  array[ck][cj] = -ci;
  array[ck][ck] = -1;
}
int multiple(int a, int b)
{
  int flag = 1;
  if(a<0) {
    a = -a;
    flag = -flag;
  }
  if(b<0) {
    b = -b;
    flag = -flag;
  }
#ifdef DEBUG
//cout<<"multiple:"<<a<<","<<b<<","<<array[a][b]<<endl;
#endif
  return array[a][b];
}


int main(void)
{
  int T,t;
  init_array();
  cin>>T;
  for(t=1;t<=T;t++)
  {
    LL X, Lin, L;
    string sin;
    cin>>Lin>>X>>sin;
    string s;
    L = 0;
    for(LL x=0;x<X;x++){
      s+=sin;
      L += Lin;
    }
    X = 1;
#ifdef DEBUG
cout<<L<<endl;
#endif
    int flag = 1;
    int pos = 0;
    int cal = 1;
    int yes = 1;
    /* stage 1 */
    while(pos < L && cal != 'i'){
      cal = multiple(cal, s[pos]);
      if(cal < 0) {
        cal = -cal;
        flag = -flag;
      }
      pos++;
    }
    if(pos==L) {
      yes = 0;
    }
#ifdef DEBUG
cout<<"stage1:"<<pos<<","<<yes<<endl;
#endif

    /* stage 2 */
    cal = 1;
    while(pos < L && cal != 'j'){
      cal = multiple(cal, s[pos]);
      if(cal < 0) {
        cal = -cal;
        flag = -flag;
      }
      pos++;
    }
    if(pos==L) {
      yes = 0;
    }
#ifdef DEBUG
cout<<"stage2:"<<pos<<","<<yes<<endl;
#endif
    /* stage 3 */
    cal = 1;
    while(pos < L){
      cal = multiple(cal, s[pos]);
      if(cal < 0) {
        cal = -cal;
        flag = -flag;
      }
      pos++;
    }
#ifdef DEBUG
cout<<"stage3:"<<pos<<","<<yes<<endl;
#endif
    if(yes == 1 && cal == 'k' && flag == 1) {
      cout<<"Case #"<<t<<": "<<"YES"<<endl;
      yes = 0;
    } else {
      cout<<"Case #"<<t<<": "<<"NO"<<endl;
    }
  }
  return 0;
}

