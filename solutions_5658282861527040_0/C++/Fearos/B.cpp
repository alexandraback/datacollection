#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    
    int n,m,i,j,k,x,t,a,b;
    int sum = 0;
    
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    
    scanf("%d",&x);
    for(t=1;t<=x;t++)
       {
        sum = 0;
        scanf("%d %d %d",&a,&b,&k);
        
        for(i=0;i<a;i++)
           for(j=0;j<b;j++)
              {
               if((i&j) < k ) sum++;
              }
        
        printf("Case #%d: ",t);
        printf("%d",sum);
        printf("\n");
       }
    
    
 scanf(" ");
 return 0;
}
