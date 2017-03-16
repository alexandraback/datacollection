#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<iostream>
#include<map>
#include<queue>
#include<bitset>
#include<string>
#include<stdlib.h>
#include<sstream>
#define pb push_back
using namespace std;
int cs,a[15];
set<int>H[1<<12];
void go(int M,int K){
    int i,j,k;
    for(i=2;i<=M;i++)
        for(j=i;j<=M;j++){
            for(k=j;k<=M;k++){
                int yo;
                for(yo=0;yo<K;yo++)
                    if(!H[(i-2)*16+(j-2)*4+(k-2)].count(a[yo]))break;
                if(yo==K){
                    printf("%d%d%d\n",i,j,k);
                    return;
                }
            }
        }
}
int main(){
    int T,i,j,k,R,N,M,K;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&R,&N,&M,&K);
        for(i=2;i<=M;i++)
            for(j=i;j<=M;j++)
                for(k=j;k<=M;k++){
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(1);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(i);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(j);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(k);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(i*j);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(i*k);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(j*k);
                    H[(i-2)*16+(j-2)*4+(k-2)].insert(i*j*k);
                }
        printf("Case #%d:\n",++cs);
        while(R--){
            for(i=0;i<K;i++)scanf("%d",&a[i]);
            go(M,K);
        }
    }
    return 0;
}

