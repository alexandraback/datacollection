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

LL solve() {
  string s;
  int N;
  cin>>s>>N;
  int n= s.size();
  LL ans = 0;
  int con = 0;
  int prev = N-2;
  for(int i=0; i<n; i++) {
    if(s[i]=='a' || s[i]=='i' || s[i]=='u' || s[i]=='e' || s[i]=='o')
      con = 0;
    else con++;
    if(con==N) {
      con--;
      ans += (LL) (i-prev) * (n-i);
      prev = i;
      //      cout<<ans<<endl;
    }
  }
  return ans;
  
    //  return 0;
}

int main() {
  int t;
  cin>>t;
  for(int i=0; i<t; i++) {
    LL ans = solve();
    cout<<"Case #"<<i+1<<": "<<ans<<endl;
    
  }
  
  return 0;
}
