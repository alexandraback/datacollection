// author : Romil //
//Code :Google CodeJAM A1 Q2//
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include<map>
using namespace std;
int main (){
    bool b[1000][2],done;
    int cases,no,level[1000][2],stars,total,max,temp,i,j;
    scanf("%d",&cases);
    for (i=1;i<=cases;i++){
        scanf("%d",&no);
        for (j=0;j<no;j++){
            scanf("%d %d",&level[j][0],&level[j][1]);
            b[j][0]=0;
            b[j][1]=0;
        }
        stars=0;
        total=0;
        while (stars!=2*no){
              done=0;
              for (j=0;j<no;j++){
                  if (b[j][1]==0 && stars>=level[j][1]){
                                  if (b[j][0]==1){
                                                  stars++;
                                  } else {
                                         stars+=2;
                                  }
                                  b[j][0]=1;
                                  b[j][1]=1;
                                  done=1;
                                  total++;
                  }
              }
		// printf("%d\n" , stars);
              if (done==0){
			//printf("inside done=0");
                         max=-1;
                         for (j=0;j<no;j++){
				//printf("%d\n",j);
                             if (b[j][0]==0 && stars>=level[j][0]){
                                            if (level[j][1]>max){
                                                                 max=level[j][1];
                                                                 temp=j;
                                            }
                                            done=1;
                             }
                         }
                         if (done==1){
                                    stars++;
                                    total++;
                                    b[temp][0]=1;
                         }
              }
              if (done==0){
                         total=-1;
                         stars=2*no;
              }
        }
        if (total==-1){
                       printf("Case #%d: Too Bad\n",i);
        } else {
               printf("Case #%d: %d\n",i,total);
        }
    }
}
