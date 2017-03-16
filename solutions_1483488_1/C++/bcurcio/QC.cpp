#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int pot[10];
int A,B,L,R;

set<int> factors[2000005];

void build(){
  int i,j,k,l;
  for(i=10;i<=99;i++){
    k=i;
    l=2;
    for(j=0;j<l-1;j++){
      k= k/pot[l-1] + (k%pot[l-1]) *10;
      if(i<k) factors[i].insert(k);
    }
  }
  for(i=100;i<=999;i++){
    k=i;
    l=3;
    for(j=0;j<l-1;j++){
      k= k/pot[l-1] + (k%pot[l-1]) *10;
      if(i<k) factors[i].insert(k);
    }
  }
  for(i=1000;i<=9999;i++){
    k=i;
    l=4;
    for(j=0;j<l-1;j++){
      k= k/pot[l-1] + (k%pot[l-1]) *10;
      if(i<k) factors[i].insert(k);
    }
  }
  for(i=10000;i<=99999;i++){
    k=i;
    l=5;
    for(j=0;j<l-1;j++){
      k= k/pot[l-1] + (k%pot[l-1]) *10;
      if(i<k) factors[i].insert(k);
    }
  }
  for(i=100000;i<=999999;i++){
    k=i;
    l=6;
    for(j=0;j<l-1;j++){
      k= k/pot[l-1] + (k%pot[l-1]) *10;
      if(i<k) factors[i].insert(k);
    }
  }
  for(i=1000000;i<=2000000;i++){
    k=i;
    l=7;
    for(j=0;j<l-1;j++){
      k= k/pot[l-1] + (k%pot[l-1]) *10;
      if(i<k) factors[i].insert(k);
    }
  }
}


void solve(){
  A=in();
  B=in();
  int i;
  if(B<10){
    puts("0");
    return;
  }
  R=0;
  
  set<int>::iterator it;
  
  for(i=A;i<=B;i++){
    it=factors[i].begin();
    while(it!=factors[i].end() && *it<=B){
      R++;
      ++it;
    }
  }
  
  printf("%d\n",R);
}


int main(){
  freopen("tin","r",stdin);
  freopen("ton","w",stdout);
  int T;
  pot[0]=1;
  for(T=1;T<9;T++){
    pot[T]=pot[T-1]*10;
  }
  
  build();
  T=in();
  for(int caso=1;caso<=T;caso++){
    printf("Case #%d: ",caso);
    solve();
  }
  
}
