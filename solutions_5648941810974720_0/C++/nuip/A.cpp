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
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  vector<string> spls={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
  vector<string> str(26);
  rep(i,10) for(char c:spls[i]) str[c-'A']+=i+'0';
  //rep(i,26) cout<<char(i+'A')<<str[i]<<endl;
  int T;
  cin>>T;
  rep(test,T){
    string str;
    cin>>str;
    vector<int> cnt(260),re(10);
    for(char c:str) ++cnt[c];
    re[0]=cnt['Z'];
    re[2]=cnt['W'];
    re[4]=cnt['U'];
    re[6]=cnt['X'];
    re[8]=cnt['G'];
    re[3]=cnt['T']-re[2]-re[8];
    re[7]=cnt['S']-re[6];
    re[5]=cnt['F']-re[4];
    re[9]=cnt['I']-re[5]-re[6]-re[8];
    re[1]=cnt['O']-re[0]-re[2]-re[4];
    cout<<"Case #"<<test+1<<": ";
    rep(i,10) cout<<string(re[i],'0'+i);
    cout<<endl;
  }
  return 0;
}
