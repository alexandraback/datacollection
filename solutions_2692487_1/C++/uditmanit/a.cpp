#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef unsigned long long int64;
int64 motes[150];
int64 min(int64 a,int64 b){
    return a<b?a:b;
    }
int64 add(int64 n){
return n+n-1;    
}
int main()
{
    int64 i,j,k,n,cas=0;
    scanf("%llu",&n);
    while(n--){
               cas++;
        int64 m,nm;
        scanf("%llu %llu",&m,&nm);
        for(i=0;i<nm;i++){
                 scanf("%llu",&motes[i]);                  
        } 
        int64 steps=0,size=m;
        sort(motes,motes+nm);
         for(i=0;i<nm;i++){      
        int64 found=0;
                           
             if(motes[i]<size){
              size+=motes[i];   
              found=1;               
             }else{
                   int64 tempsize =size,tempsteps=steps;
                   if(i==nm-1){
                               steps++;
                               break;
                               }
                   for(j=1;j<=nm-i-1;j++){
                                       //   printf("checking %d\n",j);
                       tempsize=add(tempsize);
                        tempsteps++;            
                   if(tempsize>motes[i]){
                   size=tempsize+motes[i];
                   steps=tempsteps;
                   found=1;
                   break;
                   }
                  if(j==nm-i-1){
                                
                                }
                   }
                   
             }
           if(!found){
                      steps+=nm-i;
                      break;
                      }                
         }
              
      printf("Case #%llu: %llu\n",cas,min(nm,steps));         
    }
    
}
