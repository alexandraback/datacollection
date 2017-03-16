#include <cstdio>
#include <iostream>
using namespace std;
int main (){
    bool a[1000][2],y;
    int t1,n,level[1000][2],s,t,maxm,temp,i,j;
    scanf("%d",&t1);
    for (i=1;i<=t1;i++){
        scanf("%d",&n);
        for (j=0;j<n;j++){
            scanf("%d %d",&level[j][0],&level[j][1]);
            a[j][0]=0;
            a[j][1]=0;
        }
        s=0;
        t=0;
        while (s!=2*n){
              y=0;
              for (j=0;j<n;j++){
                  if (a[j][1]==0 && s>=level[j][1]){
                                  if (a[j][0]==1){
                                                  s++;
                                  } else {
                                         s+=2;
                                  }
                                  a[j][0]=1;
                                  a[j][1]=1;
                                  y=1;
                                  t++;
                  }
              }
              if (y==0){
                         maxm=-1;
                         for (j=0;j<n;j++){
                             if (a[j][0]==0 && s>=level[j][0]){
                                            if (level[j][1]>maxm){
                                                                 maxm=level[j][1];
                                                                 temp=j;
                                            }
                                            y=1;
                             }
                         }
                         if (y==1){
                                    s++;
                                    t++;
                                    a[temp][0]=1;
                         }
              }
              if (y==0){
                         t=-1;
                         s=2*n;
              }
        }
        if (t==-1){
                       printf("Case #%d: Too Bad\n",i);
        } else {
               printf("Case #%d: %d\n",i,t);
        }
    }
    return 0;
}
