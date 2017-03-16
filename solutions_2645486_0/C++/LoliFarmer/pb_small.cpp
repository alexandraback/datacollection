#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;
int E, R, N;
int v[100];
int ans;
int MIN(int a,int b){
    return (a<b)?(a):(b);
}
void DFS(int stage, int en, int gain){
    if(stage == N){
        if(gain > ans){
            ans = gain;
        }
        return;
    }
    for(int i=0;i<=en && en-i>=0;i++){
        DFS( stage+1, MIN(E, en - i + R), gain + i*v[stage]);
    }
}
int main(){
    int T, f=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&E,&R,&N);
        for(int i=0;i<N;i++){
            scanf("%d",&v[i]);
        }
        ans = 0;
        DFS(0, E, 0);
        printf("Case #%d: %d\n",++f,ans);
    }


    return 0;
}
