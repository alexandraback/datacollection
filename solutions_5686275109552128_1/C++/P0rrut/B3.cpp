#include<bits/stdc++.h>
#define ri(X) scanf("%d",&X)
#define rii(X,Y) scanf("%d %d",&X,&Y)
#define rf(X) scanf("%lf",&X)
#define rff(X,Y) scanf("%lf %lf",&X,&Y)
#define mp(X,Y) make_pair(X,Y)
#define pii pair<int,int>
#define FOR(i,j) for(int i=0;i<j;i++)
#define FORC(i,j,c) for(int i=0;i<j;i+=c)

using namespace std;

int T,D;
int ps[1010];
int main(){
  ri(T);
  FOR(t,T){
    printf("Case #%d: ",t+1);
    ri(D);
    int maxi = 0;
    FOR(i,D){
      ri(ps[i]);
      maxi = max(maxi,ps[i]);
    }
    int best = maxi;
    FOR(i,1010){
       if(!i) continue;
       int k = 0;
       FOR(j,D){
          k+=(ps[j]-1)/i;
       }
       best = min(best,k+i);
    }
    printf("%d\n",best);
    
  }

  

  return 0;
}
