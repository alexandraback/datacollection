#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#define LL long long
#define ULL unsigned long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v) {
  s << '{';
  for (int i = 0 ; i < v.size(); ++i)
    s << (i ? "," : "") << v[i];
  return s << '}';
}
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p){
  return s << "(" << p.first << "," << p.second << ")";
}

int smax;
string str;

int main(){
  int TC; cin>>TC;
  for(int tc=1; tc<=TC; tc++){
    cin>>smax>>str;
    int tot_standing = 0;
    int fill = 0;
    for(int i=0; i<=smax; i++){
      if(str[i]-'0' == 0){
        continue;
      }

      if(tot_standing >= i){
        // ok, all of these guys stand
        tot_standing += str[i]-'0';
      }
      else{
        // not ok, need to fill
        fill += i - tot_standing;
        tot_standing = i + str[i]-'0';
      }
    }

    cout << "Case #" << tc << ": " << fill << endl;
  }
}

