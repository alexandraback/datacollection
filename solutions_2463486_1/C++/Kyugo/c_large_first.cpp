#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

typedef long long int ll;

const ll MAX = 1e14+1;

vector<ll>vec;

bool isPalindrome(ll a){
   stringstream s;
   s << a;
   string tmp;
   s >> tmp;
   int len = tmp.size();
   for(int i = 0 ; i < len/2 ; i++){
      if(tmp[i] != tmp[len-i-1])return false;
   }
   return true;
}

void make(){
   for(ll i = 1LL ; i*i < MAX ; i++){
      if(!isPalindrome(i))continue;
      if(!isPalindrome(i*i))continue;
      vec.push_back(i*i);
   }
}

int main(){
   make();
   int tc;
   cin >> tc;
   for(int i = 1 ; i <= tc ; i++){
      cout << "Case #" << i << ": ";
      ll a,b;
      cin >> a >> b;
      ll res = upper_bound(vec.begin(),vec.end(),b) - lower_bound(vec.begin(),vec.end(),a);
      cout << res << endl;
   }
   return 0;
}
