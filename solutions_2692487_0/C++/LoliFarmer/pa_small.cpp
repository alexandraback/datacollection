#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int A,n;
int ins[110],val[110];
int ans;

int chk(int p){
    int now = p;
    for(int i=0;i<n;i++){
        if(ins[i] == 0){
            if( now <= val[i] ){
                return 0;
            }
            now += val[i];
        }
    }
    return 1;
}


int Find(int p){
    int now = p;
    for(int i=0;i<n;i++){
        if(ins[i] == 0){
            if( now <= val[i] ){
                return now;
            }
            now += val[i];
        }
    }
    return now;
}


void DFS(int tm, int sum,int del_from){
    if( tm >= ans) return;
    if( chk(sum) ){
        ans = tm;
        return;
    }
    if( sum>1 ){
        DFS(tm+1, sum+Find(sum)-1,del_from);
    }
    for(int i=del_from;i<n;i++){
        ins[i] = 1;
        DFS(tm+1,sum,i+1);
        ins[i] = 0;
    }
}


int main(){
    int T;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        scanf("%d%d",&A,&n);
        for(int i=0;i<n;i++){
            scanf("%d",&val[i]);
            ins[i] = 0;
        }
        sort(val,val+n);
        ans = 2147483647;
        DFS(0,A,0);
        printf("Case #%d: %d\n",f,ans);
    }
    return 0;
}
