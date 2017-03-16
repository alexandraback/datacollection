#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int table[105];
int main(){
    
    int n,m,i,j,k,a,b,c,t,ans,minn,x;
    
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    
    scanf("%d",&t);
    for(k=0;k<t;k++)
       {
        ans = 0;
        
        scanf("%d%d",&x,&n);
        minn = n;
        for(i=0;i<n;i++)
           scanf("%d",&table[i]);
        
        //printf("%d ",a);
        sort(table,table+n);
        for(j=n;j>0;j--){
           ans = n-j;
           a = x;
         for(i=0;i<j;i++)
           {
         //   printf("%d ",table[i]);
            if(a > table[i])
               a += table[i];
            else
               {
                if(a == 1)
                   {
                    ans += j-i+99999999;
                    break;
                   }
                while(a <= table[i]) 
                   {
                    a += a-1;
                    ans++;
                  //  printf("-");
                   }
                a += table[i];
               }
           // printf(" ");
           }
         //printf("\n");
        // printf("*%d* ",ans);
         //ans += n-j;
         minn = min(minn,ans);
        }
        
        //for(i=0;i<n;i++)
        //   printf("%d ",table[i]);
       //printf("\n");
        printf("Case #%d: %d\n",k+1,minn);
        //system("pause");
       }
    
    
    
 scanf(" ");
 return 0;
}
