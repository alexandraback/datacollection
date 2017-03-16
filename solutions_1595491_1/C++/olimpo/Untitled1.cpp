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
#define GI(n) cin >> n;
#define FORn(i,s,f,p) for(int i = s;i<f;i+=p)
#define FOR(i,n) FORn(i,0,n,1)
#define MOD 1000000007
int t, tt;
int n , s, p ,x , a , b;
int main()
{
    freopen ("in.txt","r",stdin);    
    freopen ("out.txt","w",stdout);
    
     
    scanf("%d",&t);tt = 1 ;

    while(t--){
     scanf("%d%d%d",&n,&s,&p);
     a = b = 0;
     printf("Case #%d: ",tt++);   
     for(int i = 0 ; i < n ; i++){
       scanf("%d",&x);
       if(x >= p + 2*max(0,p-1)) {a++; continue;}
       if((x >= p + 2*max(0,p-2)) && s>0){s--;a++;}        
     }
     printf("%d\n",a);
   }
  return 0;    
}
