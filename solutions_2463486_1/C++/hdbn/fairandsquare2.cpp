#include <iostream>
#include <vector>
#include <limits>

using namespace std;
typedef long long int ll;

ll x[48] = {
  1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,
  11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,
  1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,
  1102011,1110111,1111111,2000002,2001002,
  10000001,
  10011001,
  10100101,
  10111101,
  11000011,
  11011011,
  11100111,
  11111111,
  20000002
};

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
  for(i = 0; i < 48; i++){
    ll r = x[i] * x[i];
    if(A <= r && r <= B) cnt++;
  } return cnt;
}

int main(int argc, char * argv[]){
  ll n, T, A, B;
  cin >> T;
  for(n = 0; n < T; n++){
    cin >> A >> B;
    ll result = solve(A, B);
    cout << "Case #" << (n+1) << ": " << result << endl;
  }  
}
