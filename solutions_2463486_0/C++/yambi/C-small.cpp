#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;
double EPS=1.0E-8;

bool isParindrome(int n){
  string s = boost::lexical_cast<string>(n);
  for(int i=0;i<s.size();++i){
    if(s[i]!=s[s.size()-i-1])return false;
  }
  return true;
}

void solve(){
  int A;cin>>A;
  int B;cin>>B;
  int res = 0;
  for(int i=A;i<=B;++i){
    if(!isParindrome(i))continue;
    int s = (int)(sqrt(i)+EPS);
    if(s*s!=i)continue;
    if(!isParindrome(s))continue;
    res++;
    //cout<<i<<" ";
  }
  cout << res << endl;
}
int main(){
  int N;cin>>N;
  for(int i=1;i<=N;++i){
    cout << "Case #" << i <<": ";
    solve();
  }
  return 0;
}

