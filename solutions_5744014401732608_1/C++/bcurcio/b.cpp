#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
typedef long long ll;

int mat[66][66];

void solve(){
    ll b,m;
    cin >> b >> m;
    
    ll pp = 1LL<<(b-2);
    
    if(pp<m){
      cout << "IMPOSSIBLE" << endl;
      return;
    }
    cout << "POSSIBLE" << endl;
    
    int i,j;
    for(i=0;i<b;i++) for(j=0;j<b;j++) mat[i][j] = 0;
    
    ll b2 = 1;
    while((1LL<<b2) <= m) b2++;
    b2--;
    m -= (1LL << b2);
    
    for(i=0;i<=b2;i++){
      mat[i][b-1] = 1;
      for(j=0;j<i;j++) mat[j][i] = 1;
    }
    
    if(m>0){
      i = b2+1;
      assert(b2<b-1);
      mat[i][b-1] = 1;
      
      j = b2;
      while(m>0){
        assert(j>=0);
        if(m>=(1LL<<(j-1))){
          m -= (1LL<<(j-1));
          mat[j][i] = 1;
        }
        j--;
      }
      
    }
    
    for(i=0;i<b;i++){
      for(j=0;j<b;j++){
        if(i==j) assert(mat[i][j]==0);
        if(i==b-1) assert(mat[i][j]==0);
        
        cout<<mat[i][j];
      }
      cout << endl;
    }
    
    
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": " ;
      solve();
    }
}
