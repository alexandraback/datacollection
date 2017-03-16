#include <iostream>
#include <vector>
#include <limits>

using namespace std;
typedef long long int ll;

bool isPalindrome(ll x){
  string y;
  int i;
  while(x > 0){
    y.push_back(x%10);
    x /= 10;
  }
  for(i = 0; i < y.size()/2; i++){
    if(y[i] != y[y.size()-1-i]) return false;
  }
  return true;
}

ll solve(ll A, ll B){
  ll i, cnt;
  cnt = 0;
  for(i = 1; i*i <= B; i++){
    if(i*i >= A && isPalindrome(i) && isPalindrome(i*i)){
      // cout << i << ":" << i*i << endl;
      cnt++;
    }
  }
  return cnt;
}

int main(int argc, char * argv[]){
  ll n, T, A, B;
  // cout << numeric_limits<ll>::max() << endl;
  cin >> T;
  for(n = 0; n < T; n++){
    cin >> A >> B;
    ll result = solve(A, B);
    cout << "Case #" << (n+1) << ": " << result << endl;
  }  
}
