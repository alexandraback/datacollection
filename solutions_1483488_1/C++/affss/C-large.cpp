#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template<class T> inline string toS(T& x){ostringstream sout;sout<<x;return sout.str();}

void main2(){
  int A,B,i,j,res = 0;
  set< pair<string,string> > s;

  scanf("%d %d",&A,&B);

  string sA = toS(A);
  string sB = toS(B);

  for(i = A; i <= B; i++){
    string str = toS(i);
    rep(j,str.size()){
      string rotate = str.substr(j) + str.substr(0,j);
      if(sA <= rotate && rotate <= sB && rotate != str) s.insert(make_pair(rotate,str));
    }
  }

  cout << s.size() / 2 << endl;
}

int main(){
  int T,t;
  scanf("%d",&T);
  rep(t,T){
    printf("Case #%d: ",t+1);
    main2();
  }
  return 0;
}
