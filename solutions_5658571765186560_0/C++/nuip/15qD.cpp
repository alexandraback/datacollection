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

int solve(int x,int r,int c){
  if(r>c)swap(r,c);
  switch(x){
  case 1:
    return 0;
  case 2:
    return r*c%2;
  case 3:
    if(r==1)return 1;
    return r*c%3;
  case 4:
    if(r<=2)return 1; //T
    if(c<4)return 1;  //I
    if(r%4==0 || c%4==0)
      return 0;
    return r*c%4;
  case 5:
    if(r%5 && c%5)return 1;
    if(r<3) return 1;  //V
    if(r==3) return c==5; //W
    return 0;
  case 6:
    if(c<6) return 1;
    if(r<=3) return 1;  //1131
    if(r*c%6) return 1;
    return 0;
  default:
    return 1;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int Case,T;
  string exist="RICHARD",noex="GABRIEL";
  cin>>T;
  rep(Case,T){
    int x,r,c;
    cin>>x>>r>>c;
    cout<<"Case #"<<Case+1<<": "<<(solve(x,r,c)?exist:noex)<<endl;
  }
  return 0;
}
