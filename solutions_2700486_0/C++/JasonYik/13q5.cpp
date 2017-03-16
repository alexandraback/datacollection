#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define pii pair<int,int>
#define LL long long
using namespace std;
int t,n,x,y,a[30],b,z;
void abc(int c,int d,int e){
     /*printf("%d %d %d: ",c,d,e);
     for (int i=8;i<=12;i++) printf("%d ",a[i]);
        printf("\n");*/
     if (c>n){
        b++;
        if (a[x+10]>=y) z++;
     }else{
           if (e<=0){
              a[d]+=2;
              abc(c+1,10,a[10]+2);
              a[d]-=2;
           }else if (a[d-1]>=e-1){
                if (a[d+1]>=e-1){
                   a[d]+=2;
                   abc(c+1,10,a[10]+2);
                   a[d]-=2;
                }else abc(c,d+1,e-1);
           }else{
                  if (a[d+1]>=e-1) abc(c,d-1,e-1);
                  else{
                       abc(c,d-1,e-1);
                       abc(c,d+1,e-1);
                       }
           }
     }
}
int main(){
    scanf("%d",&t);
    for (int i=1;i<=t;i++){
        scanf("%d%d%d",&n,&x,&y);
        if (n==1){
           if (x==0 && y==0) printf("Case #%d: 1.00\n",i);
           else printf("Case #%d: 0.00\n",i);
           continue;
           }
        if (x<=-10 || x>=10){
           printf("Case #%d: 0.00\n",i);
           continue;
           }
        b=0;z=0;
        for (int j=0;j<=20;j++) a[j]=-2+(j&1);
        a[10]=0;
        abc(2,10,2);
        printf("Case #%d: %.6f\n",i,z*1.0/b);
        }
    return 0;
}
