#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

void solve(){
  int N = in();
  
  int i;
  
  vector<int> count(3000,0);
  
  for(i=0;i<N * (2*N-1);i++) count[in()]++;
  
  for(i=0;i<3000;i++) if(count[i]%2 == 1) cout << i << ' ';
  
  cout << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1 << ": ";
      solve();
    }
}
