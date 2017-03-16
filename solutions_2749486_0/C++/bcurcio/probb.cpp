#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

static const int dr[4] = {0, -1, 0, 1};
static const int dc[4] = {-1, 0, 1, 0};
//static const char dp[4] = {'W','S','E','N'};

#define LIM 1200
#define lim2 600

piii dp[LIM][LIM];

string solve(){
  int X = in();
  int Y = in();
  int i;
  
  string ans = "";
  if(X>0){
    for(i=0;i<X;i++){
      ans+='W';
      ans+='E';
    }
  }else{
    for(i=0;i<-X;i++){
      ans+='E';
      ans+='W';
    }
  }
  
  if(Y>0){
    for(i=0;i<Y;i++){
      ans+='S';
      ans+='N';
    }
  }else{
    for(i=0;i<-Y;i++){
      ans+='N';
      ans+='S';
    }
  }
  return ans;
}


int main(){
  for(int i=0,T=in();i<T;i++){
      string ans = solve();
      printf("Case #%d: %s\n",i+1,ans.c_str());
    }
}
