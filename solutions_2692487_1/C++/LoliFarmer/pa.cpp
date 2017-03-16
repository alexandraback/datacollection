#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long int A;
int n;
int ins[110];
long long val[110];
int ans;

int chk(long long int p){
    long long int now = p;
    for(int i=0;i<n;i++){
        if(ins[i] == 0){
            if( now <= val[i] ){
                return i;
            }
            now += val[i];
        }
    }
    return -1;
}


long long int Find(long long int p){
    long long int now = p;
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




void DFS(int tm, long long int sum,int del_from){
    if( ans!=-1 &&  tm >= ans) return;
    int stp = chk(sum);
    if( stp == -1 ){
        ans = tm;
//        printf("> ans = %d\n",ans);
        return;
    }
    if( tm + n - stp < ans || ans == -1){
        ans = tm + n - stp;
//        printf("=> ans = %d, stop = %d\n",ans,stp);
    }
    if( sum>1 ){
        DFS(tm+1, sum+Find(sum)-1,del_from);
    }
/*
 * for(int i=del_from;i<n;i++){
        ins[i] = 1;
        DFS(tm+1,sum,i+1);
        ins[i] = 0;
    }
  */
}


int main(){
    int T;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        scanf("%lld%d",&A,&n);
        for(int i=0;i<n;i++){
            scanf("%lld",&val[i]);
            ins[i] = 0;
        }
        sort(val,val+n);
        ans = -1;
        DFS(0,A,0);
        printf("Case #%d: %d\n",f,ans);
    }
    return 0;
}
