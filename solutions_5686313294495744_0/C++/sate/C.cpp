#include<bits/stdc++.h>
using namespace std;
typedef pair<string,string> P;
int N;

bool check(int st,const vector<P>& v){
  for(int i=0;i<N;i++){
    if( st & (1<<i) ) {
      bool a = false, b = false;
      for(int j=0;j<N;j++){
        if( st & (1<<j) ) continue;
        if( v[j].first == v[i].first ) a = true;
        if( v[j].second == v[i].second ) b = true;
      }
      if( !a || !b ) return false;
    }
  }
  return true;
}

int main(){
  int T; cin >> T;
  for(int ttt=1;ttt<=T;ttt++){
    cout << "Case #" << ttt << ": ";
    vector<P> v;
    cin >> N;
    for(int i=0;i<N;i++){
      string a,b; cin >> a >> b;
      v.push_back( P(a,b) );
    }
    int res = 0;
    for(int i=0;i<(1<<N);i++){
      if( check(i,v) )
        res = max( res, __builtin_popcount( i ) );      
    }
    cout << res << endl;
  }
}
