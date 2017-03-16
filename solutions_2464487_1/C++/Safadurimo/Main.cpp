#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <ctime> 

using namespace std;

typedef string Date;
typedef long long ll;


ll f(ll n, ll r){
  return n*(2*r-3)+2*n*(n+1);
}

int main() 
{
  int T;
  ll k=3*707106781l;
  ll r,t;
  cin >> T;
  for(int i=1;i<=T;i++){
    cin >> r >> t;
    ll low =1;
    ll high = min(k,t/(2*r)+1);
    while(low<high){
      ll middle = (low+high)/2+1;
      if(f(middle,r)<=t){
        low =middle;
      }
      else
        high = middle-1;
    }
    
    cout << "Case #" << i << ": " << (low) << endl;
  }
}
