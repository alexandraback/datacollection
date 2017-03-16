#include<stdio.h>
#include<stdlib.h>
int main (){
    int b[1000][2],YN;
    int T,N,level[1000][2],s,total,max,temp,i,j;
    scanf("%d",&T);
    for (i=1;i<=T;i++){
        scanf("%d",&N);
        for (j=0;j<N;j++){
            scanf("%d %d",&level[j][0],&level[j][1]);
            b[j][0]=0;
            b[j][1]=0;
        }
        s=0;
        total=0;
        while (s!=2*N){
              YN=0;
              for (j=0;j<N;j++){
                  if (b[j][1]==0 && s>=level[j][1]){
                                  if (b[j][0]==1){
                                                  s++;
                                  } else {
                                         s+=2;
                                  }
                                  b[j][0]=1;
                                  b[j][1]=1;
                                  YN=1;
                                  total++;
                  }
              }
              if (YN==0){
                         max=-1;
                         for (j=0;j<N;j++){
                             if (b[j][0]==0 && s>=level[j][0]){
                                            if (level[j][1]>max){
                                                                 max=level[j][1];
                                                                 temp=j;
                                            }
                                            YN=1;
                             }
                         }
                         if (YN==1){
                                    s++;
                                    total++;
                                    b[temp][0]=1;
                         }
              }
              if (YN==0){
                         total=-1;
                         s=2*N;
              }
        }
        if (total==-1){
                       printf("Case #%d: Too Bad\n",i);
        } else {
               printf("Case #%d: %d\n",i,total);
        }
    }
    return 0;
}
