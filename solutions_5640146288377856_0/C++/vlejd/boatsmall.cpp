#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<set>
#include<vector>
#include<map>
#include<cstdlib>
#include<ctime>
using namespace std;

#define For(Q,W) for(int Q=0;Q<W;Q++)
#define ForL(Q,W) for(long long Q=0;Q<W;Q++)

#define LLD long long
#define mkp make_pair
#define pf printf
#define sf scanf

//#define debug
#ifdef debug
#define db(XZ) cout<<XZ<<" "
#define dbn() cout<<endl
#else 
#define db(XZ); 
#define dbn()
#endif


void solve(int T){
  printf("Case #%d: ",T+1);
  int R,C,W;
  scanf("%d %d %d ",&R,&C,&W);
  if(W==C){
      printf("%d\n",W);
      return;
  }
  int ans =0;
  while(C>W){
      ans++;
      C-=W;
  }
  if(C==0) ans--;
  ans+=W;
  
  printf("%d\n",ans);
  
  //solve your problem
  
}

int main(){
  int T;
  scanf("%d ",&T);
  For(i,T) solve(i);
  return 0;
}

