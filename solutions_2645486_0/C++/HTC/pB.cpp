#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;
int value[10005],ans,E,R,N;
void dfs(int pos,int nowE,int nowValue){
    int i;
    if(pos == N){
        if(nowValue > ans)
            ans = nowValue;
        return ;
    }
    for(i=0;i<=nowE;i++){
        dfs(pos+1,min(nowE-i+R,E),nowValue+i*value[pos]);
    }
}
int main (){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("Bsamll.txt","w",stdout);
    //freopen("A-large.in","r",stdin);
    //freopen("Alarge.txt","w",stdout);
    int ca,T,i;
    scanf("%d",&T);
    for(ca = 1;ca <= T;ca++){
        scanf("%d%d%d",&E,&R,&N);
        ans = 0;
        for(i=0;i<N;i++){
            scanf("%d",&value[i]);
        }
        dfs(0,E,0);
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
