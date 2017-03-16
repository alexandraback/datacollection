#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define EPS (1e-10)
#define lef(x) (x<<1)
#define rig(x) (x<<1)+1
int pas[100][100];
int getdia(int x,int y){
    if (x==0){
       int ctr=y/2;
       return ((ctr*(ctr+1))/2)*4+ctr+1;
    }
    x=abs(x);
    int ctr=(x+y)/2;
    ctr--;
    return ((ctr*(ctr+1))/2)*4+ctr+1;
}
void solve(){
     double memo[100];
     int n,x,y;
     pas[0][0]=1;
     pas[1][0]=1;
     pas[1][1]=1;
     for (int i=2;i<25;++i){
         for (int j=0;j<=i;++j){
             pas[i][j]=0;
             if (j<i) pas[i][j]+=pas[i-1][j];
             if (j>0) pas[i][j]+=pas[i-1][j-1];
         }
     }
     scanf("%d %d %d",&n,&x,&y);
     int dia=getdia(x,y);
     double ans;
     if (x==0){
        if (n>=dia){
           ans=1.0;
        }
        else ans=0.0;
     }
     else{
          int ctr=getdia(x+2,y);
          if (n>=ctr){
             ans=1.0;
          }
          else if (n-dia>=(1<<(y/2+1))+y+1){
               ans=1.0;
          }
          else{
              n-=dia;
              int lv=y+1;
              if (n-lv<0){
                 ans=0.0;
              }
              else{
                   double ctr,pro;
                   ctr=1.0;
                   pro=0.0;
                   for (int i=0;i<100;++i) memo[i]=0.0;
                   for (int i=0;i<n;++i){
                       ctr/=2.0;
                       for (int j=0;j<=i;++j){
                           memo[j]+=ctr*pas[i][j];
                       }
                   }
                   ans=memo[y];
              }
          }
     }
     printf("%.6lf\n",ans);
}
int main(){
    int ntest;
    scanf("%d",&ntest);
    for (int test=1;test<=ntest;++test){
        printf("Case #%d: ",test);
        solve();
    }
    return 0;
}
