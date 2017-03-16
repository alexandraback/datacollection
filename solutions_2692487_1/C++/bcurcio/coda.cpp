#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int in(){int r=0,c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

long long m[105];
long long dp[120][120];
void solve(){
  int A =in();
  int N =in();
  int i;
  for(i=0;i<N;i++) m[i] = in();
  sort(m,m+N);
  
  memset(dp,-1,sizeof dp);
  dp[0][0] = A;
  for(i=1;i<=N;i++){
    
    int mote=m[i-1];
    int j;
    
    
    for(j=0;j<119;j++) dp[i][j+1]=dp[i-1][j];
    
    //cerr << i << ' ' << dp[i-1][2]<< ' ' << mote << endl;
    for(j=0;j<120;j++) if(dp[i-1][j]>mote) dp[i][j] = max(dp[i][j],dp[i-1][j]+mote);
    //cerr << i << ' ' << dp[i-1][2] << endl;
    
    for(j=0;j<119;j++){
      if(dp[i-1][j]==-1) continue;
      
      int k;
      long long size = dp[i-1][j];
      
      for(k=1;j+k<119;k++){
        size = size+size-1;
        //if(k<6) cerr << j+k << ' ' << size << ' ' << dp[i][j+k]<< endl;
        if(size>6000000) break;
        if(size<=mote) dp[i][j+k+1] = max(dp[i][j+k+1],size);
        else dp[i][j+k] = max(dp[i][j+k],size+mote);
      }
      
    }
  }
  
  for(i=0;i<120;i++) if(dp[N][i]!=-1) break;
  
  cout << i << endl;
}

int main(){
  for(int i=0,T=in();i<T;i++){
      printf("Case #%d: ",i+1);
      solve();
    }
}
