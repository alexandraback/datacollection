#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std; 
int T,R,N,M,K;

int main(){
    scanf("%d %d %d %d %d",&T,&R,&N,&M,&K);
    printf("Case #1:\n");
    for (int t=0;t<R;t++){
        int b[10];
        memset(b,0,sizeof b);
        for (int i=0;i<K;i++){
            int a;
            scanf("%d",&a);
            if (a%5==0) b[5]=max(b[5],1);
            if (a%25==0) b[5]=max(b[5],2);
            if (a%125==0) b[5]=max(b[5],3);
            if (a%3==0) b[3]=max(b[3],1);
            if (a%9==0) b[3]=max(b[3],2);
            if (a%27==0) b[3]=max(b[3],3);
            if (a%2==0) b[2]=max(b[2],1);
            if (a%4==0) b[2]=max(b[2],2);
            if (a%8==0) b[2]=max(b[2],3);
            if (a%16==0) b[2]=max(b[2],4);
            if (a%32==0) b[2]=max(b[2],5);
            if (a%64==0) b[2]=max(b[2],6);
            }
        while (b[2]+b[3]+b[4]+b[5]>3){
              b[2]=b[2]-2;
              b[4]++;
              }
        while (b[2]+b[3]+b[4]+b[5]<3) b[2]++;      
        for (int i=2;i<=5;i++)
        for (int j=0;j<b[i];j++) printf("%d",i);
        printf("\n");
        }
    
    return 0;
    }
