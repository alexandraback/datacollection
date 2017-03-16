#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,t,s,p,f[1111];
int main(){
    int i,j,k,l,xx=0,b;
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&t);
    while (t--){
          scanf("%d%d%d",&n,&s,&p);
          for (i=0;i<n;i++)
              scanf("%d",&f[i]);
          l=0;    
          sort(f,f+n);
          for (i=n-1;i>=0;i--){
              if (f[i]>=p){     
              b=(f[i]-p)/2;
              if (p-b==2){
                     if (s){
                        s--;
                        l++;       
                     }     
                     else break;
              }
              else if (p-b<2)
                   l++;
                   }
          }     
    
          printf("Case #%d: %d\n",++xx,l);
    }
    return 0;   
}
