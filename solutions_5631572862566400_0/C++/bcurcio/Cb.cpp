#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef pair<int,int> pii;

void solve(){
  
  int N = in();
  int i,j;
  vector<int> nxt(N+1);
  
  for(i=0;i<N;i++){
    int x = in() - 1;
    nxt[i] = x;
  }
  
  int ans = 1;
  for(i=0;i<(1<<N);i++){
    if (__builtin_popcount(i)<=ans) continue;
    vector<int> aux;
    for(j=0;j<N;j++) if(i&(1<<j)){
      aux.push_back(j);
      //~ cout << j << ' ' ;
    }
    //~ cout << endl;
    int m  = aux.size();
    
    do{
      bool can = true;
      
      for(j=0;j<m;j++)
        if(aux[(j+1)%m]!=nxt[aux[j]] && aux[(j+m-1)%m]!=nxt[aux[j]])
          can = false;
      
      if(can){
        ans = __builtin_popcount(i);
        break;
      }
      
    }while(next_permutation(aux.begin(),aux.end()));
  }
  
  cout << ans << endl;
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #" << i+1 << ": ";
      solve();
    }
}
