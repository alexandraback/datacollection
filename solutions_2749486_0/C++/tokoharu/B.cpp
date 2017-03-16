#include <algorithm>
#include <cmath>
#include <climits>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
using namespace std;


typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define REP(i,n) for(int i=0;i<(int)n;i++) 
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++) 
#define ALL(c) (c).begin(),(c).end() 



int gcd(int a,int b){
  return b?gcd(b,a%b):a;
}
int lcm(int a,int b){
  return a/gcd(a,b)*b;
}

string solve() {
  int x,y;
  cin>>x>>y;
  string tmp ;
  for(int i=0; i<abs(x); i++) {
    if(x>0) {
      tmp += "W";
      tmp += "E";
    }
    if(x<0) {
      tmp += "E";
      tmp += "W";
    }
  }
  for(int i=0; i<abs(y); i++) {
    if(y<0) tmp += "NS";
    if(y>0) tmp += "SN";
    
  }  

  return tmp;

}

int main() {
  int t;
  cin>>t;
  for(int i=0; i<t; i++) {
    string ans = solve();
    cout<<"Case #"<<i+1<<": "<<ans<<endl;
    
  }
  
  return 0;
}
