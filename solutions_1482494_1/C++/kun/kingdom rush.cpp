#include<cstdio>
#include<cstdlib>
int a[1001],b[1001],rr,u,step[1001],now,cc,cd,ans,n;
int main(){
    freopen("B-large.in","r",stdin);
    freopen("test.txt","w",stdout);
    scanf("%d",&rr);
    for(int rg = 0;rg<rr;rg++){
       scanf("%d",&n);
       for(int i=0;i<n;i++) scanf("%d%d",&a[i],&b[i]),step[i] = 0;
       u = 0; now = 0; ans = 0;
       while(now < 2*n){
          u = -1;    cc = 0; cd = -1;
          for(int i=0;i<n;i++){
                if( step[i] == 0 ){
                    if(a[i] <= now && (u==-1||b[u] < b[i]) && cd != 2 && cc == 0){
                        u = i; cc = 0;cd = 1;        
                    }
                    if(b[i] <= now){ u = i;cc = 1;cd = 2;} 
                }        
                if(step[i] == 1){
                    if(b[i] <= now ){
                        u = i;cc = 1; cd = 1;
                    }           
                }
          }   //printf("!!%d",u);
          if(u == -1) {printf("Case #%d: Too Bad\n",rg+1); goto ex1;}
          now += cd; if(cc == 1) step[u] = 2; else step[u] = 1; ans++;
          
       }
          printf("Case #%d: %d\n",rg+1,ans);
       ex1:;
    }
    //system("pause");
    return 0;
}
