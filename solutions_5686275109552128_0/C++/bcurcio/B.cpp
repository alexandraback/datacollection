#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

bool can2(int tl, int ct, vector<int> &P){
  int i;
  
  tl -= ct;
  
  for(i=0;i<P.size();i++){
    ct -= (P[i]-1) / tl;
    if(ct<0) return false;
  }
  
  
  return true;
  
}

bool can(int tl,vector<int> &P){
  
  int i;
  
  
  for(i=0;i<=tl-1;i++) if (can2(tl,i,P)) return true;
  
  
  return false;
}

void solve(){
  int D = in();
  vector<int> P;
  int i;
  
  for(i=0;i<D;i++) P.push_back(in());
  
  
  int inf = 0;
  
  int sup = 1005;
  
  while(inf+1!=sup){
    
    int mid = (inf+sup)/2;
    
    if(can(mid,P)){
      sup = mid;
    }else{
      inf = mid;
    }
  }
  
  //~ int it = 0;
  //~ while(!can(it,P)) it++;
  
  
  cout << sup << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": ";
      solve();
    }
}
