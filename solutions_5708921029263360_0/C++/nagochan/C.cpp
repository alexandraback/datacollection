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

void check_and_add(VII & ans, int j, int p, int s, int K)
{
  VI tmp;
  tmp.push_back(j);
  tmp.push_back(p);
  tmp.push_back(s);
  ans.push_back(tmp);
  int size = ans.size();
  int flag = 1;
  for(int n1 = 0 ; n1 < size; n1++){
    int count = 0;
    for(int n2 = 0 ; n2 < size; n2++){
      int f = 0;
      if(ans[n1][0] == ans[n2][0]) f++;
      if(ans[n1][1] == ans[n2][1]) f++;
      if(f >= 2){
        count++;
      }
    }
//cout<<n1<<","<<count<<endl;
    if(count > K){
      flag = 0;
      break;
    }
    count = 0;
    for(int n2 = 0 ; n2 < size; n2++){
      int f = 0;
      if(ans[n1][0] == ans[n2][0]) f++;
      if(ans[n1][2] == ans[n2][2]) f++;
      if(f >= 2){
        count++;
      }
    }
//cout<<n1<<","<<count<<endl;
    if(count > K){
      flag = 0;
      break;
    }
    count = 0;
    for(int n2 = 0 ; n2 < size; n2++){
      int f = 0;
      if(ans[n1][1] == ans[n2][1]) f++;
      if(ans[n1][2] == ans[n2][2]) f++;
      if(f >= 2){
        count++;
      }
    }
//cout<<n1<<","<<count<<endl;
    if(count > K){
      flag = 0;
      break;
    }
  }
//cout<<j<<","<<p<<","<<s<<","<<flag<<endl;
  if(flag==0){
    ans.pop_back();
  }
}

int main(void)
{
  int T,t;
  cin>>T;
  for(t=1;t<=T;t++)
  {
    int J,P,S,K;
    cin>>J>>P>>S>>K;
    VII ans;
    for(int j = 1 ; j <= J ; j++){
      for(int p = 1 ; p <= P ; p++){
        for(int s = 1 ; s <= S ; s++){
          check_and_add(ans, j, p, s, K);
        }
      }
    }
    int size = ans.size();
    cout<<"Case #"<<t<<": "<<size<<endl;
    for(int n = 0 ; n < size; n++){
      cout<<ans[n][0]<<" "<<ans[n][1]<<" "<<ans[n][2]<<" "<<endl;
    }
    
  }
  return 0;
}

