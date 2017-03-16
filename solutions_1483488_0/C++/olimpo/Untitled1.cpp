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
int n , a , b,s,y,c,p;
int M[2000005];
map<int,int>::iterator it;
int Convert(int x){
  y = x;
  c = 0;
  p = 1;
  while(y){
    c++;
    p*=10;
    y/=10;
  }
  p/=10;
  y = x;
  while(c--){
    int z = (x%10)*p;     
    x = x/10 + z;
    y = min(x,y);
  }
  return y;
}
int main()
{
    //freopen ("in.txt","r",stdin);    
    //freopen ("out.txt","w",stdout);

    scanf("%d",&t);tt = 1 ;

    while(t--){
     s=0;
     memset(M,0,sizeof(M));
     scanf("%d%d",&a,&b);
     for(int i = a ; i <= b ; i++){
           M[Convert(i)]++;  
           s+=M[y]-1;
     }
     
     printf("Case #%d: ",tt++);   
     printf("%d\n",s);
   }
  return 0;    
}
