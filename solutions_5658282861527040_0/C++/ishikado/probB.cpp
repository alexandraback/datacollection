#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <iterator>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <stack>
#include <climits>
#include <deque>
#include <bitset>
#include <cassert>
#include <ctime>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
// rep macro
#define REP(i,x,n) for(int i=x;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define RREP(i,x,n) for(int i=x;i>=(int)(n);--i)
#define rrep(i,n) RREP(i,n,0)
#ifdef __GNUC__
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
int popcount(unsigned int n){int cnt=0;for(int i=0;i<32;i++)if((n>>i)&1)cnt++;return cnt;}
int popcountll(unsigned ll n){int cnt=0;for(int i=0;i<64;i++)if((n>>i)&1)cnt++;return cnt;}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
ll getTen(int a){return (a<=0)?1:(getTen(a-1)*10);}
bool EQ(double a,double b){return abs(a-b)<EPS;}
void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}
vector<string> split(string str,char del){
  vector<string> res;
  for(int i=0,s=0;i<SIZE(str);i++){
    if(str[i]==del){if(i-s!=0)res.push_back(str.substr(s,i-s));s=i+1;}
    else if(i==SIZE(str)-1){res.push_back(str.substr(s));}
  }
  return res;
}
struct TimeWatch{
  clock_t start_,end_;
  void start(){start_=clock();}
  double stop(){return (double)(clock()-start_)/CLOCKS_PER_SEC;}
};

int A,B,K;
void solve(){
  cin>>A>>B>>K;
  int cnt=0;
  for(int i=0;i<A;i++){
    for(int j=0;j<B;j++){
      int k=i&j;
      if(k<K){
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
}  

int main(){

  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    cout<<"Case #";
    cout<<t<<": ";
    solve();
  }
  
  
  return 0;
}
