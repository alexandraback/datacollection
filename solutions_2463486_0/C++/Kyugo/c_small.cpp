#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
using namespace std;

const int MAX = 1001;

vector<int>vec;

bool isPalindrome(int a){
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
   for(int i = 1 ; i < MAX ; i++){
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
      int a,b;
      cin >> a >> b;
      int res = upper_bound(vec.begin(),vec.end(),b) - lower_bound(vec.begin(),vec.end(),a);
      cout << res << endl;
   }
   return 0;
}
