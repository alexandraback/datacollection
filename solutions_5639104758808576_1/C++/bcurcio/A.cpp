#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve(){
  int smax;
  cin >> smax;
  
  string str;
  cin >> str;
  
  int i;
  int cant = 0;
  int ans = 0;
  for(i=0;i<=smax;i++){
    
    if(cant<i){
      ans+= (i - cant);
      cant = i;
    }
    
    cant += str[i]-'0';
    
  }
  
  cout << ans << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": ";
      solve();
    }
}
