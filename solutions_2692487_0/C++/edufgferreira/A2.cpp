#define _USE_MATH_DEFINES
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <utility>
#include <set>
#include <map>
#include <bitset>
#include <iostream>
#include <ctype.h>

#define gc getchar  //unlocked linux
#define MOD 1000000007
#define INF numeric_limits<int>::max()
#define FOR(i,v,n) for(i=v;i<n;i++)
#define scan(i) scanf(" %d",&i)
#define scan2(i,j) scanf(" %d %d",&i,&j)
#define scan3(i,j,k) scanf(" %d %d %d",&i,&j,&k)
#define print(i) printf("%d\n",i);
#define pb push_back 
#define sz(i) i.size()
#define reset(vec) memset(vec,0,sizeof(vec))
#define ord(vec) sort(vec.begin(),vec.end())
#define rev(vec) reverse(vec.begin(),vec.end())
#define MAX 40

using namespace std;

inline void scanint(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int cmp_double(double a, double b, double eps = 1e-9){
    return a + eps > b ? b + eps > a ? 0 : 1 : -1;  //0 = iguais, 1 = a maior
}

vector <long long> vec;
set <long long> seti;
int mark[1000010];

int main(){
    int t1,casos=1;
    int i,j;
    int ans,ans2;
    long long ax;
    int a,n;
    long long A; 
    scan(t1);
    
    while(t1--){

       scanf(" %lld %d",&A,&n);
       FOR(i,0,n){
          scanf("%lld",&ax);    
          vec.pb(ax);               
       }  
       ord(vec);
       reset(mark);
       ans=0;
       FOR(i,0,n){
          if (vec[i]<A){
             A+=vec[i];              
          }else{
             if (!mark[i]){   
                seti.insert(ans+(n-i));
                mark[i]=1;
             }   
             ans++;
             if (ans>=*(seti.begin())){
                break;                          
             }
             A+=(A-1);
             i--;
        //     if (i!=n-1){
        //         if (vec[i+1]>=A){
        //            ans--;
        //            ans+=n-i;
         //           break;
         //        }
         //        i--;      
          //   }
          }           
                  
       }
       if (seti.begin()!=seti.end()){
       if(ans>*(seti.begin()))
          ans=*(seti.begin());
       }
       vec.clear();
       seti.clear();
       printf("Case #%d: ",casos++);         
       printf("%d\n",ans);        
    }
    
    
    return 0;
}




