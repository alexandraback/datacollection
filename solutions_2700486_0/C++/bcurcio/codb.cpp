#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

double  dp[2][3000000];
double adp[2][3000000];

void solve(){
  int N = in();
  int X = in();
  int Y = in();
  if((X+Y)%2 == 1){
    cout << "0.0"<<endl;
    return;
  }
  
  if(N==1){
    puts(X+Y==0?"1.0":"0.0");
    return;
  }
  
  int have = 1;
  int i=3;
  int next = have + i * 2 - 1; 
  
  while(N>=next){
    have = next;
    i+=2;
    next = have + i * 2 + 1;
  }
  //cerr << have << ' ' << N << ' '<< next << endl;
  
  if(X+Y<=(i-3)){
    cout << "1.0"<<endl;
    return;
  }
  if(X+Y>i+1){
    cout << "0.0" << endl;
    return ;
  }
  if(X==0){
    cout << "0.0"<<endl;
    return;
  }

  int lv = i;
  N-=have;
  
  int cur = 0;
  memset(dp,0,sizeof dp);
  memset(adp,0,sizeof adp);
  
  int j;
  for(i=1;i<=min(N,lv-1);i++){
    cur = i & 1;
    
    dp[cur][0] = 0.5 * (1-adp[cur^1][0]);
    adp[cur][0] = adp[cur^1][0] + dp[cur][0];
    
    for(j=1;j<lv;j++){
      dp[cur][j] = 0.5 * (adp[cur^1][j-1] - adp[cur^1][j]) ;
      adp[cur][j] = adp[cur^1][j] + dp[cur][j];
    }
    
  }
  
  int pos=0;
  for(;i<=N;i++){
    cur = i & 1;
    
    for(j=0;j<=pos;j++){
      dp[cur][j]=(1-adp[cur^1][j]);
      adp[cur][j]=1.;
    }
    
    for(j=pos+1;j<N;j++){
      dp[cur][j] = 0.5 * (adp[cur^1][j-1] - adp[cur^1][j]);
      adp[cur][j] = adp[cur^1][j] + dp[cur][j];
    }
    pos++;
  }
  
  printf("%.7lf\n",adp[cur][Y]);
  
}

int main(){
  for(int i=0,T=in();i<T;i++){
    printf("Case #%d: ",i+1);
      solve();
    }
}
