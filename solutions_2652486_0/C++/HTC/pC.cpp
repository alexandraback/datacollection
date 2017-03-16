#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<time.h>
using namespace std;
int R,N,M,K;
int num[100];
int value[100];
int gen[100];
int ans[100];
double best;
void getAns(){
    int i;
    for(i=0;i<N;i++)
        ans[i] = num[i];
}
double guess(){
    int i,j;
    int pro;
    int cnt = 0;
    for(j=0;j<K;j++){
        pro = 1;
        for(i=0;i<N;i++){
            if(rand()%2 == 0)
                pro *= num[i];
        }
        gen[j] = pro;
    }
    for(i=0;i<K;i++){
        if(gen[i] == value[i])cnt++;
    }
    return (double)cnt / (double) K;
}
void dfs(int pos){
    int i,T=100;
    double tmp;
    if(pos == N){
        while(T--)
        {
            tmp = guess();
            if(best < tmp){
                best = tmp;
                getAns();
            }
        }
        return ;
    }
    for(i=2;i<=M;i++){
        num[pos] = i;
        dfs(pos+1);
    }
}
int check(){
    int i;
    for(i=0;i<N;i++){
        if(value[i] == 125){
            num[0] = num[1] = num[2] = 5;
            getAns();
            return 1;
        }
        if(value[i] == 27){
            num[0] = num[1] = num[2] = 3;
            getAns();
            return 1;
        }
        if(value[i] == 64){
            num[0] = num[1] = num[2] = 3;
            getAns();
            return 1;
        }
        if(value[i] == 100){
            num[0] = 4;
            num[1] = 5;
            num[2] = 5;
            getAns();
            return 1;
        }
        if(value[i] == 80){
            num[0] = 4;
            num[1] = 4;
            num[2] = 5;
            getAns();
            return 1;
        }
        if(value[i] == 60){
            num[0] = 3;
            num[1] = 4;
            num[2] = 5;
            getAns();
            return 1;
        }
        if(value[i] == 45){
            num[0] = 3;
            num[1] = 3;
            num[2] = 5;
            getAns();
            return 1;
        }
        if(value[i] == 50){
            num[0] = 2;
            num[1] = 5;
            num[2] = 5;
            getAns();
            return 1;
        }
    }
    return 0;
}
int main (){
    freopen("C-small-1-attempt3.in","r",stdin);
    freopen("Csamll_1.txt","w",stdout);
    //freopen("A-large.in","r",stdin);
    //freopen("Alarge.txt","w",stdout);
    int ca,T,i,j;
    srand(time(0));
    scanf("%d",&T);
    for(ca = 1;ca <= T;ca++){
        best = 0;
        printf("Case #%d:\n",ca);
        scanf("%d%d%d%d",&R,&N,&M,&K);
        for(i=0;i<R;i++){
            best = 0;
            for(j=0;j<K;j++){
                scanf("%d",&value[j]);
            }
            if(check() == 0)
                dfs(0);
            for(j=0;j<N;j++)printf("%d",ans[j]);
            printf("\n");
        }
    }
    return 0;
}
