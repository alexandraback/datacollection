#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <bitset>
#include <cmath>
#include <complex>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <stdlib.h>
#include <utility>
#include <ctime>
#include <limits.h>
using namespace std;

#define BIT(x) __builtin_popcount(x)
#define G1(x) cin >> x;
#define G2(x,y) cin >> x >> y;
#define G3(x,y,z) cin >> x >> y >> z;
#define MAX 100005
#define MOD 1000000007
int t,n,k;
double K[MAX];
double KK[MAX];
double r = 0;
double Exp(int x , int y){
  if(y == 0) return x+1;
  double s = x+2;
  s = min(s,(x-y+1)*KK[y] + (1-KK[y])*(x-y+1+x+1));  
  return min(s,Exp(x,y-1)+1);  
}
int main(){
   //freopen ("in.txt","r",stdin);
   //freopen ("out.txt","w",stdout);
   scanf("%d",&t);
   for(int tt = 1 ; tt <= t ;tt++){
     printf("Case #%d: ",tt);
     scanf("%d%d",&k,&n);
     KK[0] = 1;
     for(int i = 1 ;i <= k ; i++){
       cin >> K[i]; 
       KK[i] = K[i]*KK[i-1];       
     }
     printf("%.6lf\n",Exp(n,k));
   }
   
   return 0;    
}












