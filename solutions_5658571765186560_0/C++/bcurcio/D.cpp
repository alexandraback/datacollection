#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

#define WIN(a,b,c) {if(R==a && C==b) puts(c?"GABRIEL":"RICHARD"); return;}

void solve(){
  int X = in();
  int R = in();
  int C = in();
  
  if(R>C) swap(R,C);
  
  if(X==1){
    puts("GABRIEL");
    return;
  }
  
  
  if(X==2){
    if( (R*C)%2 == 0){
      puts("GABRIEL");
      return;
    }else{
      puts("RICHARD");
      return;
    }
  }
  
  if(X==3){ 
    if(R>=2 && C>=3 && (R*C)%3==0){
      cout << "GABRIEL" << endl;
    }else{
      cout << "RICHARD" << endl;
    }
    return;
  }
  
  if(X==4){
    if(R>=3 && C>=4 && (R*C)%4==0){
      cout << "GABRIEL" << endl;
    }else{
      cout << "RICHARD" << endl;
    }
  }
  
  if(X==5){
    if(R>=4 && C>=5 && (R*C)%5==0){
      cout << "GABRIEL" << endl;
    }else{
      cout << "RICHARD" << endl;
    }
  }
  
  if(X==6){
    if(R>=5 && C>=6 && (R*C)%6==0){
      cout << "GABRIEL" << endl;
    }else{
      cout << "RICHARD" << endl;
    }
  }
  
  
  if(X>=7){
      cout << "RICHARD" << endl;
      return;
  }
}

int main(){
  for(int i=0,T=in();i<T;i++){
      cout << "Case #"<< i+1 << ": ";
      solve();
    }
}
