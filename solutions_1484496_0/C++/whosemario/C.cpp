#include<iostream>
using namespace std;

int num[21];
int res[2000005];
int best=0;
int res1,res2;
int col[21];
int n;
void proc(int deep,int step,int sum,int bit){
     if(deep==step){
         if(sum<=2000000){
               if(res[sum]==0) res[sum]=bit;
               else{
                   if((bit&res[sum])==0){
                      best=1;
                      res1=bit;
                      res2=res[sum];
                   }
               }
         }
         return;
     }
     int i;
     for(i=deep;i<n;i++){
         if(col[i]==0){
            col[i]=1;
            proc(deep+1,step,sum+num[i],bit|(1<<i));
            col[i]=0;
         }
     }
     return ;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.data","w",stdout);
    
    int t;
    cin>>t;
    int ca;
    for(ca=1;ca<=t;ca++){
        cin>>n;
        int i;
        for(i=0;i<n;i++)
           cin>>num[i];
        memset(res,0,sizeof(res));
        best=0;
        memset(col,0,sizeof(col));
        for(i=1;i<n;i++){
           proc(0,i,0,0);
           if(best==1) break;
        }
        if(best){
           printf("Case #%d:\n",ca);
           int flag=1;
           for(i=0;i<n;i++)
              if(res1&(1<<i)){
                 if(flag) {flag=0;printf("%d",num[i]);}
                 else printf(" %d",num[i]);
              }
           printf("\n");
           flag=1;
           for(i=0;i<n;i++)
              if(res2&(1<<i)){
                 if(flag) {flag=0;printf("%d",num[i]);}
                 else printf(" %d",num[i]);
              }
           printf("\n");
           
        }
        else{
           printf("Case #%d: Impossible\n",ca);
        }
    }
}
