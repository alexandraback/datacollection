// include {{{
#include <cstdio>
#include <iostream>
//#include <sstream>
#include <string>
#include <vector>
//#include <deque>
#include <stack>
#include <queue>
//#include <map>
#include <set>
#include <algorithm>
#include <cmath>
//#include <complex>
// }}}
using namespace std;
// macro {{{
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);++i)
#define REP(i,j,k) for(int i=j;i<(k);++i)
#define foreach(it,v) for(typeof((v).begin()) it=(v).begin();it!=(v).end();++it)
#define ALL(c) (c).begin(),(c).end()
#define priority_queue_greater(T) priority_queue< T, vector<T>, greater<T> >
// }}}

//string n = "abcdefghijklmnopqrstuvwxyz";
string m = "yhesocvxduiglbkrztnwjpfmaq";
int T;
string g;
int main(){
  cin >> T;
  getline(cin,g);
  REP(times,1,T+1){
    getline(cin,g);
    rep(i,g.size())if(g[i]!=' '){ g[i] = m[ g[i]-'a' ]; }
    cout <<"Case #"<< times <<": " << g << endl;
  }
  return 0;
}


