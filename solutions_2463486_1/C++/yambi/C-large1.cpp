#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <boost/lexical_cast.hpp>
using namespace std;
double EPS=1.0E-8;
vector<long long> fairsquares;

bool isParindrome(long long n){
  string s = boost::lexical_cast<string>(n);
  for(int i=0;i<s.size();++i){
    if(s[i]!=s[s.size()-i-1])return false;
  }
  return true;
}

void solve(){
  long long A;cin>>A;
  long long B;cin>>B;
  int res = 0;
  for(int i=0;i<fairsquares.size();++i){
    if(A<=fairsquares[i]&&fairsquares[i]<=B)res++;
  }
  cout << res << endl;
}
int main(){
  for(long long i=1;i<=10000000;++i){
    if(isParindrome(i)&&isParindrome(i*i)){
      fairsquares.push_back(i*i);
    }
  }
  int N;cin>>N;
  for(int i=1;i<=N;++i){
    cout << "Case #" << i <<": ";
    solve();
  }
  return 0;
}

