#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

int N,P,S;
int c[1000];

bool can(int x){
  int i; int cant=0; int voy=0;
  int qa,qb,qc;
  for(i=0;i<N;i++){
    if((c[i]+2)/3 >=P ) cant++;  
    else if(voy<S){
      qa=P;
      qb=(c[i]-qa)/2;
      qc=c[i]-qa-qb;
      
      if(qc+qa+qb==c[i] && qc>=0 && qb>=0 && abs(qa-qb)<=2 && abs(qa-qc)<=2 && abs(qc-qb)<=2 ){
        cant++;
        voy++;
      }
     }
  }
  return cant>=x;
}

void solve(){
  N=in();
  S=in();
  P=in();
  int i;
  for(i=0;i<N;i++) c[i]=in();
  int inf=0;
  int sup=N;
  int mid;
  while(inf<sup){
    mid=(inf+sup+1)/2;
    if(can(mid)){
      inf=mid;
    }else{
      sup=sup-1;
    }
  }
  
  printf("%d\n",inf);
}

int main(){
  freopen("tin","r",stdin);
  freopen("ton","w",stdout);
  int i,T=in();
  for(int caso=1;caso<=T;caso++){
    printf("Case #%d: ",caso);
    solve();
  }
  
}
