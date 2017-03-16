#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int mtb[5][5]={
  {0, 0, 0, 0, 0},
  {0, 1, 2, 3, 4},
  {0, 2,-1, 4,-3},
  {0, 3,-4,-1, 2},
  {0, 4, 3,-2,-1}};

int mult(int x,int y){
  return mtb[abs(x)][abs(y)]*((x<0)==(y<0)?1:-1);
}
int inv(int x){return (abs(x)==1)?x:-x;}

int solve(ll n,ll m,string &str){
  vector<int> v(n);
  int prod=1;
  rep(i,n)
    v[i]=str[i]-'i'+2;
  rep(i,n)
    prod=mult(prod,v[i]);
  //cout<<v<<prod;
  int prodl=1,prodr=1,f=0;
  rep(i,m%4)prodr=mult(prodr,prod);
  if(prodr!=-1)return 0;
  rep(i,min(8ll,m)){
    rep(j,n){
      if(prodl==2)f=1;
      if(prodl==4 && f)return 1;
      prodl=mult(prodl,v[j]);
    }
  }
  return 0;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int Case,T;
  cin>>T;
  rep(Case,T){
    ll n,m;
    string str;
    cin>>n>>m>>str;
    cout<<"Case #"<<Case+1<<": "<<(solve(n,m,str)?"YES":"NO")<<endl;
  }
  return 0;
}
