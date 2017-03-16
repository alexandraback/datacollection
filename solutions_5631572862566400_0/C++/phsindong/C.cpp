#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<string>

using namespace std;

int T,N,ret;
int bff[1000];
int bffOrder[1000];

void solve(int nowPos, int nowOrder){
    if(bffOrder[nowPos]>0){
        if(bffOrder[nowPos]==nowOrder-2){
            bool check=false;
            for(int i=0;i<N;i++){
                if(bffOrder[i]<1){
                    check=true;
                    solve(i,nowOrder);
                }
            }
            if(check==false){
                int minOrder = N;
                for(int i=0;i<N;i++){
                    if(bff[i]==nowPos) minOrder = min(minOrder,bffOrder[i]);
                    ret=nowOrder-minOrder;
                    return;
                }
            }
        }else{
            if(ret<nowOrder - bffOrder[nowPos])ret = nowOrder - bffOrder[nowPos];
            return;
        }
    }else{
        bffOrder[nowPos]=nowOrder;
        solve(bff[nowPos],nowOrder+1);
        bffOrder[nowPos]=-1;
    }
}

int main(){
    FILE *inf, *outf;
    inf=fopen("C-small-attempt3.in","r");
    outf=fopen("C-small-attempt3-result.in","w");
    
    fscanf(inf,"%d",&T);
    for(int ii=0;ii<T;ii++){
        ret=0;
        fscanf(inf,"%d",&N);
        memset(bff,-1,sizeof(bff));
        for(int j=0;j<N;j++){
            int tmp;
            fscanf(inf,"%d",&tmp);
            bff[j]=tmp-1;
        }
        for(int i=0;i<N;i++){
            memset(bffOrder,-1,sizeof(bffOrder));
            solve(i,1);
        }

        fprintf(outf,"Case #%d: %d\n",ii+1,ret);
    }
}