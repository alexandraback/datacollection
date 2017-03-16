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
const int dy[]={-1,0,1,0},dx[]={0,1,0,-1};
// adjust problem by problem
const double EPS=1e-8;
const double PI=acos(-1.0);
#define REP(i,n) for(int i=0;i<(int)n;++i)
#ifdef __GNUC__
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
int popcount(int n){return __builtin_popcount(n);}
int popcount(ll n){return __builtin_popcountll(n);}
#endif
#ifndef __GNUC__
template<class T> int popcount(T val){
  val = val - ((val >> 1) & 0x55555555);
  val = (val & 0x33333333) + ((val >> 2) & 0x33333333);
  val = (val + (val >> 4)) & 0x0f0f0f0f;
  val += val >> 8;
  val += val >> 16;
  return (int)(val & 0x0000003f);
}
#endif
template<class T>int SIZE(T a){return a.size();}
template<class T>string IntToString(T num){string res;stringstream ss;ss<<num;return ss.str();}
template<class T>T StringToInt(string str){T res=0;for(int i=0;i<SIZE(str);i++)res=(res*10+str[i]-'0');return res;}
template<class T>T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template<class T>T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> void PrintSeq(T &a,int sz){for(int i=0;i<sz;i++){cout<<a[i];if(sz==i+1)cout<<endl;else cout<<' ';}}
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

int T;
int R;
int N,M,K;

vector<vector<int> > ary[130];

int main(){

  for(int i=2;i<=5;i++){
    vector<int> v;
    v.push_back(i);
    ary[i].push_back(v);
    for(int j=i;j<=5;j++){
      vector<int> v;
      v.push_back(i);
      v.push_back(j);
      ary[i*j].push_back(v);
      for(int k=j;k<=5;k++){
        vector<int> v;
        v.push_back(i);
        v.push_back(j);
        v.push_back(k);
        ary[i*j*k].push_back(v);
      }
    }
  }
  
  cin>>T;
  cin>>R>>N>>M>>K;
  cout<<"Case #1:"<<endl;
  for(int i=0;i<R;i++){
    int v[10]={};
    for(int j=0;j<K;j++)cin>>v[j];
    sort(v,v+N,greater<int>());
    bool ok=false;
    for(int lim=0;lim<130;lim++){
      for(int j=0;j<K;j++){
        if(ary[v[j]].size()==1){
          ok=true;
          int sz=(int)ary[v[j]][lim].size();
          for(int k=0;k<sz;k++)
            cout<<ary[v[j]][lim][k];
          for(int k=sz;k<N;k++)
            cout<<2;
          cout<<endl;
          break;
        }
      }
      if(ok){
        break;
      }
    }
    if(!ok){
      for(int k=0;k<N;k++)
        cout<<2;
      cout<<endl;
    }
  }
  
  return 0;
}
