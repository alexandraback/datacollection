#include <cstdio>
#include <iostream>
using namespace std;
int main (){
    bool boolarr[1000][2],y_or_n;
    int T,N,level[1000][2],stars,total,max,temp,i,j;
    scanf("%d",&T);
    for (i=1;i<=T;i++){
        scanf("%d",&N);
        for (j=0;j<N;j++){
            scanf("%d %d",&level[j][0],&level[j][1]);
            boolarr[j][0]=0;
            boolarr[j][1]=0;
        }
        stars=0;
        total=0;
        while (stars!=2*N){
              y_or_n=0;
              for (j=0;j<N;j++){
                  if (boolarr[j][1]==0 && stars>=level[j][1]){
                                  if (boolarr[j][0]==1){
                                                  stars++;
                                  } else {
                                         stars+=2;
                                  }
                                  boolarr[j][0]=1;
                                  boolarr[j][1]=1;
                                  y_or_n=1;
                                  total++;
                  }
              }
              if (y_or_n==0){
                         max=-1;
                         for (j=0;j<N;j++){
                             if (boolarr[j][0]==0 && stars>=level[j][0]){
                                            if (level[j][1]>max){
                                                                 max=level[j][1];
                                                                 temp=j;
                                            }
                                            y_or_n=1;
                             }
                         }
                         if (y_or_n==1){
                                    stars++;
                                    total++;
                                    boolarr[temp][0]=1;
                         }
              }
              if (y_or_n==0){
                         total=-1;
                         stars=2*N;
              }
        }
        if (total==-1){
                       printf("Case #%d: Too Bad\n",i);
        } else {
               printf("Case #%d: %d\n",i,total);
        }
    }
    //system("pause");
    return 0;
}
