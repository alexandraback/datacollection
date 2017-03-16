#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int motes[150];
int min(int a,int b){
    return a<b?a:b;
    }
int add(int n){
return n+n-1;    
}
int main()
{
    int i,j,k,n,cas=0;
    scanf("%d",&n);
    while(n--){
               cas++;
        int m,nm;
        scanf("%d %d",&m,&nm);
        for(i=0;i<nm;i++){
                 scanf("%d",&motes[i]);                  
        } 
        int steps=0,size=m;
        sort(motes,motes+nm);
         for(i=0;i<nm;i++){      
        int found=0;
                           
             if(motes[i]<size){
              size+=motes[i];   
              found=1;               
             }else{
                   int tempsize =size,tempsteps=steps;
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
              
      printf("Case #%d: %d\n",cas,min(nm,steps));         
    }
    
}
