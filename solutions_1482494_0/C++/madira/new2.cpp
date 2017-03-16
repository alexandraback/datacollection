#include <cstdio>
#include <iostream>
using namespace std;
int main (){
    bool b[1000][2],YN;
    int T,N,step[1000][2],war,total,max,temp,i,j;
    freopen( "B-small-attempt0.in", "r", stdin );
	freopen( "output.out", "w", stdout );
    cin>>T;
    cin.ignore();
    for (i=1;i<=T;i++){
        scanf("%d",&N);
        for (j=0;j<N;j++){
            scanf("%d %d",&step[j][0],&step[j][1]);
            b[j][0]=0;
            b[j][1]=0;
        }
        war=0;
        total=0;
        while (war!=2*N){
              YN=0;
              for (j=0;j<N;j++){
                  if (b[j][1]==0 && war>=step[j][1]){
                                  if (b[j][0]==1){
                                                  war++;
                                  } else {
                                         war+=2;
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
                             if (b[j][0]==0 && war>=step[j][0]){
                                            if (step[j][1]>max){
                                                                 max=step[j][1];
                                                                 temp=j;
                                            }
                                            YN=1;
                             }
                         }
                         if (YN==1){
                                    war++;
                                    total++;
                                    b[temp][0]=1;
                         }
              }
              if (YN==0){
                         total=-1;
                         war=2*N;
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
