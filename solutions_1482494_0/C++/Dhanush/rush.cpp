#include <cstdio>
#include <iostream>
using namespace std;
int main (){
    bool b[1000][2],var;
    int T,N,level[1000][2],stars,total,max,temp,i,j;
    scanf("%d",&T);
    for (i=1;i<=T;i++){
        scanf("%d",&N);
        for (j=0;j<N;j++){
            scanf("%d %d",&level[j][0],&level[j][1]);
            b[j][0]=0;
            b[j][1]=0;
        }
        stars=0;
        total=0;
        while (stars!=2*N){
              var=0;
              for (j=0;j<N;j++){
                  if (b[j][1]==0 && stars>=level[j][1]){
                                  if (b[j][0]==1){
                                                  stars++;
                                  } else {
                                         stars+=2;
                                  }
                                  b[j][0]=1;
                                  b[j][1]=1;
                                  var=1;
                                  total++;
                  }
              }
              if (var==0){
                         max=-1;
                         for (j=0;j<N;j++){
                             if (b[j][0]==0 && stars>=level[j][0]){
                                            if (level[j][1]>max){
                                                                 max=level[j][1];
                                                                 temp=j;
                                            }
                                            var=1;
                             }
                         }
                         if (var==1){
                                    stars++;
                                    total++;
                                    b[temp][0]=1;
                         }
              }
              if (var==0){
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
    return 0;
}
