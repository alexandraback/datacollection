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
int t,n,x,xx,r ;
int A[MAX],B[MAX];

int main(){
   //freopen ("in.txt","r",stdin);
   //freopen ("out.txt","w",stdout);
   scanf("%d",&t);
   for(int tt = 1 ; tt <= t ;tt++){
     printf("Case #%d: ",tt);
     scanf("%d",&n);
     for(int i = 0 ;i < n ;i++){
        cin >> A[i]>>B[i];      
     }
     xx = -2;
     x = 0;
     r  =0;
     int p = -1;
     while(x!=xx){
        xx = x;
        p = -1;
       // printf("Step %d\n",x);
        for(int i = 0 ; i < n ; i++){
          //printf("%d %d\n",A[i],B[i]);
          if(B[i] == -1) continue;
          if(A[i] == -1 && B[i]<=x ){A[i] = -1;B[i] = -1; x+=1;r++;continue;} 
          if(B[i] <= x){A[i] = -1;B[i] = -1; x+=2;r++;continue;} 

          if(A[i] > x || A[i] == -1) continue;
          if(p ==-1 || (B[p]<B[i]) )p = i;      
        }             
        if(x == xx && p!=-1){
           A[p]=-1;
           x++;
           r++;
        }
       
     }
     if(x == 2*n)
      cout << r << endl;
     else
       cout << "Too Bad" << endl;
   }
   
   return 0;    
}












