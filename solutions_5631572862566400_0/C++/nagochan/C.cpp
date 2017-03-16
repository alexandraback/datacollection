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


int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int N;
    cin>>N;
    VI bff;
    VI A;
    for(int n = 0 ; n < N ; n++){
      int tmp;
      cin>>tmp;
      bff.push_back(tmp-1);
      A.push_back(n);
    }
    int ans = 2;
    do{
      int num = 1;
      int p_0 = A[0];
      int b_0 = bff[p_0];
      for(int n = 1 ; n < N ; n++){
        int p_n = A[n];
        int b_n = bff[p_n];
        int p_l = A[n-1];
        int p_r;
        if(n== (N-1)){
          p_r = A[0];
        }else{
          p_r = A[n+1];
        }
        if(b_n != p_r && b_n != p_l){
          //A[0]がnのBFFかチェック
          
          if(b_n == p_0){
            num++;
          }
          break;
        }
        num++;
      }
      //最後にA[0]のチェック
      int flag = 1;
      //最後にA[0]のチェック
      if(b_0 != A[1] && b_0 != A[num-1]) flag = 0;
      //最後にA[num-1]のチェック
      int b_num1 = bff[A[num-1]];
      if(num >= 2 && b_num1 != A[num-2] && b_num1 != A[0]) flag = 0;
      if(flag == 1 && num > ans) {
        ans = num;
//        for(int n=0;n<ans;n++)cout<<A[n]<<" ";
//        cout<<endl;
      }
    }while(next_permutation(ALL(A)));
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
  return 0;
}

